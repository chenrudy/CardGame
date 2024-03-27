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
        virtual void startGame() = 0;
        virtual void endTurn() = 0;
        virtual bool checkWinCondition() = 0;
        virtual const GameInstance &getGameInstance() const = 0;
    };
}

#endif // IGAME_H

/* To create a card game app that supports multiple games using your Card and Deck classes, you'll likely need additional classes to represent the game logic, player actions, and overall game state. Here's a basic outline of the classes you might consider and how they could be related:

Game Class:

This class represents the overall game logic and state.
It may have methods for initializing the game, executing player actions, managing turns, and determining the game outcome.
Each specific game (e.g., Poker, Blackjack, Solitaire) could be implemented as a subclass or a separate instance of this class.
Player Class:

Represents a player in the game.
Contains information about the player's hand, score, and any other relevant attributes.
May have methods for actions such as drawing cards, discarding cards, and making moves.
Rule Class:

Represents the specific rules of a game.
Contains information about the deck composition, scoring mechanisms, winning conditions, etc.
Allows for flexibility in defining different rule sets for various games.
Game Controller Class:

Manages the flow of the game, including player turns, rule enforcement, and game state updates.
Acts as an intermediary between the user interface (if any) and the game logic.
User Interface Classes (optional):

If your game app has a graphical or text-based user interface, you'll need classes to manage user interactions, display game information, and handle input/output.
These classes may include components such as menus, buttons, card displays, and scoreboards.
Regarding making the game classes interchangeable, you can use a combination of inheritance, interfaces, and composition:

Inheritance: Define a base Game class with virtual methods representing common game actions (e.g., startGame(), endTurn(), checkWinCondition()). Subclasses for specific games (e.g., PokerGame, BlackjackGame) can override these methods with game-specific implementations.

Interfaces: Define interfaces (abstract base classes) for concepts shared among different games, such as Playable, Scorable, or RuleBased. Each game class can implement these interfaces to ensure consistency in behavior.

Composition: Use composition to include instances of the Card, Deck, Player, and Rule classes within your game classes. This allows you to customize each game's components independently and switch them out as needed.

By designing your classes with flexibility and modularity in mind, you can create a card game app that supports various games with different rules, decks, and gameplay mechanics. Users can select the game they want to play, and the app can dynamically adjust its behavior based on the chosen game's specifications.*/