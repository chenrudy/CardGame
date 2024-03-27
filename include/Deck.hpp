
// @ts-check

#ifndef DECK_H
#define DECK_H

#include "Card.hpp"
#include "IDeck.hpp"

namespace CardGames
{
    class Deck : public IDeck // a full 54 cards deck
    {
    public:
        Deck();
        virtual ~Deck();

        void ShuffelDeck() override;
        void PrintDeck() const override; // for testing
        std::shared_ptr<Card> GetTopCard() override;

    private:
        std::vector<std::shared_ptr<Card>> m_deck;
    };
}

#endif // DECK_H