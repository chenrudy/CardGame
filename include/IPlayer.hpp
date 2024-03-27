#ifndef IPLAYER_H
#define IPLAYER_H

#include <string>
#include <memory>

#include "Card.hpp"

namespace CardGames
{
    class IPlayer
    {
    public:
        virtual ~IPlayer() {}
        virtual void displayHand() const = 0;
        virtual std::string GetName() const = 0;
    };
}

#endif // IPLAYER_H