#include "IGame.hpp"
#include "Deck.hpp"

#include "GameYaniv.hpp"

namespace CardGames
{

    GameYaniv::GameYaniv(std::vector<std::shared_ptr<IPlayer>> players) : m_deck(std::make_shared<Deck>()), m_players(players), m_gameInstance() {}

    void GameYaniv::startGame()
    {
    }
    void GameYaniv::endTurn()
    {
    }
    bool GameYaniv::checkWinCondition()
    {
        return true;
    }
    const GameInstance &GameYaniv::getGameInstance() const
    {
        return m_gameInstance;
    }
};
