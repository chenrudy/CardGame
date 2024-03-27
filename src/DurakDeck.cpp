#include "DurakDeck.hpp"
#include <algorithm> // shuffle
#include <random>    // mt19937, random_device

#include <iostream> // cout, endl

namespace CardGames
{

    DurakDeck::DurakDeck() : m_deck()
    {
        m_deck.reserve(36);

        for (int rank = Card::ACE; rank <= Card::KING; ++rank)
        {
            if (rank >= Card::TWO && rank <= Card::FIVE)
                continue;
            for (int suit = Card::HEARTS; suit <= Card::SPADES; ++suit)
            {
                m_deck.push_back(std::make_shared<Card>(static_cast<Card::Ranks>(rank), static_cast<Card::Suits>(suit)));
            }
        }
    }

    DurakDeck::~DurakDeck()
    {
        m_deck.clear();
    }

    void DurakDeck::ShuffelDeck()
    {
        shuffleDeckHelper(m_deck);
    }

    void DurakDeck::PrintDeck() const
    {
        printDeckHelper(m_deck);
    }

    std::shared_ptr<Card> DurakDeck::GetTopCard()
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