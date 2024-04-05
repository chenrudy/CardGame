#include <string>
#include <vector>
#include <iostream>
#include <algorithm> // For std::sort

#include "YanivPlayer.hpp"
#include "Card.hpp"

namespace CardGames
{
    YanivPlayer::YanivPlayer(const std::string &name) : m_name(name), m_score(0) {}
    YanivPlayer::~YanivPlayer() {}

    void YanivPlayer::displayHand() const
    {
        std::cout << m_name << "'s Hand:" << std::endl;
        for (const auto &card : m_hand)
        {
            card->PrintCard();
        }
        std::cout << std::endl;
    }
    void YanivPlayer::addToHand(const std::shared_ptr<Card> card)
    {
        m_hand.push_back(card);
    }

    std::string YanivPlayer::GetName() const
    {
        return m_name;
    }

    int YanivPlayer::GetScore() const
    {
        return m_score;
    }

    void YanivPlayer::SetScore(int newScore)
    {
        m_score = newScore;
    }

    std::vector<size_t> SortIndices(const std::vector<size_t> &indices) // emoving an element from the deque will change the indices of subsequent elements.
    {
        std::vector<size_t> sortedIndices = indices;
        std::sort(sortedIndices.rbegin(), sortedIndices.rend());
        return sortedIndices;
    }

    std::vector<std::shared_ptr<Card>> YanivPlayer::discardFromHand(const std::vector<size_t> &indices)
    {
        std::vector<size_t> sortedIndices = SortIndices(indices);
        std::vector<std::shared_ptr<Card>> discardedCards;

        // Iterate over the sorted indices and extract the cards from the hand
        for (size_t index : sortedIndices)
        {
            if (index <= m_hand.size())
            {
                auto it = m_hand.begin() + index;
                discardedCards.push_back(*it); // Store the discarded card
                m_hand.erase(it);
            }
        }

        return discardedCards; // Return the vector of discarded cards
    }

    std::size_t YanivPlayer::GetHandSize() const
    {
        return m_hand.size();
    }

}
