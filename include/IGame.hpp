// base Game class with virtual methods representing common game actions (e.g., startGame(), endTurn(), checkWinCondition()).
// Subclasses for specific games (e.g., PokerGame, BlackjackGame) can override these methods with game-specific implementations.
#ifndef IGAME_H
#define IGAME_H

#include <vector>
#include <memory>
#include "Card.hpp"
#include "IDeck.hpp"
#include "GameInstance.hpp"

namespace CardGames
{

    class IGame
    {
    public:
        virtual ~IGame() {}
        virtual void startGame() = 0;
        virtual void endTurn() = 0;
        virtual bool checkWinCondition() = 0;
        virtual const GameInstance &getGameInstance() const = 0;
    };
}

#endif // IGAME_H
