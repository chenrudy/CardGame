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

    std::vector<int> SortIndices(const std::vector<int> &indices) // emoving an element from the deque will change the indices of subsequent elements.
    {
        std::vector<int> sortedIndices = indices;
        std::sort(sortedIndices.rbegin(), sortedIndices.rend());
        return sortedIndices;
    }

    void RemoveCards(const std::vector<int> &sortedIndices, std::deque<std::shared_ptr<Card>> &hand)
    {
        for (size_t index : sortedIndices)
        {
            if (index < hand.size())
            {
                auto it = hand.begin() + index;
                hand.erase(it);
            }
        }
    }

    void YanivPlayer::discardFromHand(const std::vector<int> &indices)
    {
        RemoveCards(SortIndices(indices), m_hand);
    }
}
