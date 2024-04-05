
// @ts-check

#ifndef DURAK_DECK_H
#define DURAK_DECK_H

#include <vector>
#include <memory>

#include "Card.hpp"
#include "IDeck.hpp"

namespace CardGames
{
    class DurakDeck : public IDeck // a durak 36 cards deck
    {
    public:
        DurakDeck();
        virtual ~DurakDeck();

        void ShuffelDeck() override;
        void PrintDeck() const override;
        std::shared_ptr<Card> GetTopCard() override;

    private:
        std::vector<std::shared_ptr<Card>> m_deck;
    };
}

#endif // DURAK_DECK_H