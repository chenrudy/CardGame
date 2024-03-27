#include "Deck.hpp"
#include "Card.hpp"

#include <algorithm> // shuffle
#include <random>    // mt19937, random_device
#include <memory>
#include <iostream> // cout, endl

namespace CardGames
{

    Deck::Deck() : m_deck()
    {
        m_deck.reserve(54);

        for (int rank = Card::ACE; rank <= Card::KING; ++rank)
        {
            for (int suit = Card::HEARTS; suit <= Card::SPADES; ++suit)
            {
                m_deck.push_back(std::make_shared<Card>(static_cast<Card::Ranks>(rank), static_cast<Card::Suits>(suit)));
            }
        }

        m_deck.push_back(std::make_shared<Card>(static_cast<Card::Ranks>(Card::JOKER), static_cast<Card::Suits>(Card::BLACK_JOCKER)));
        m_deck.push_back(std::make_shared<Card>(static_cast<Card::Ranks>(Card::JOKER), static_cast<Card::Suits>(Card::RED_JOCKER)));
    }

    Deck::~Deck()
    {
        m_deck.clear();
    }

    void Deck::ShuffelDeck()
    {
        std::random_device rd;
        std::mt19937 randNumGenerator(rd());

        std::shuffle(m_deck.begin(), m_deck.end(), randNumGenerator);
    }

    void Deck::PrintDeck() const
    {
        for (const auto &sharedCard : m_deck)
        {
            sharedCard.get()->PrintCard();
        }
        std::cout << std::endl;
    }

    std::shared_ptr<Card> Deck::GetTopCard()
    {
        if (m_deck.empty())
        {
            return nullptr;
        }

        std::shared_ptr<Card> topCard = m_deck.back();
        m_deck.pop_back();

        return topCard;
    }
}
