#ifndef YANIV_PILE_H
#define YANIV_PILE_H

#include <vector>
#include <memory>

#include "Card.hpp"

namespace CardGames
{
    class YanivPile // does not have the responsebillity of first turn (where playe cannot call GetPervCard). this should be handled in the game loop
    {
    public:
        enum CardFromPile
        {
            Top,
            Bottom
        };
        std::shared_ptr<Card> GetPervCard(CardFromPile cardFromPile = CardFromPile::Top); // choose top or, if perv played discarded multiple crds, bottom card
        void DiscardToPile(std::vector<std::shared_ptr<Card>> discarded);

        void TakenFromDeck(); // here we will move current to perv, as player choose to take from deck and not pile
        void PrintPile();

    private:
        std::vector<std::shared_ptr<Card>> m_Prev;
        std::vector<std::shared_ptr<Card>> m_current;
    };
}

#endif // YANIV_PILE_H