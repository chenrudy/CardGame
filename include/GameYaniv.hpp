#ifndef GameYaniv_H
#define GameYaniv_H

#include <vector>
#include <memory>
#include "IDeck.hpp"
#include "IGame.hpp"
#include "IPlayer.hpp"
#include "YanivPlayer.hpp"

namespace CardGames
{
    class GameYaniv : public IGame
    {
    public:
        GameYaniv(std::vector<std::shared_ptr<IPlayer>> players);
        virtual void startGame() override;
        virtual void endTurn() override;
        virtual bool checkWinCondition() override;
        virtual const GameInstance &getGameInstance() const override;

    private:
        std::shared_ptr<IDeck> m_deck; // just hold deck and yanivplayer?
        std::vector<std::shared_ptr<IPlayer>> m_players;
        GameInstance m_gameInstance;
    };

}

#endif // GameYaniv_H