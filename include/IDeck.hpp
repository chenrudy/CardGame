
#ifndef IDECK_H
#define IDECK_H

#include <vector>
#include <memory>

#include "Card.hpp"

namespace CardGames
{
    class IDeck
    {
    public:
        virtual ~IDeck() {} // Virtual destructor for polymorphic behavior

        virtual void ShuffelDeck() = 0;
        virtual void PrintDeck() const = 0;
        virtual std::shared_ptr<Card> GetTopCard() = 0;

    protected:
        //  centralize the common functionality in the base class while allowing derived classes to customize their behavior as needed.
        void shuffleDeckHelper(std::vector<std::shared_ptr<Card>> &deck);
        void printDeckHelper(const std::vector<std::shared_ptr<Card>> &deck) const;
    };
}

#endif // IDECK_H