#ifndef YANIV_TURN_H
#define YANIV_TURN_H

#include <vector>
#include <memory>
#include <sstream>

#include "ITurn.hpp"
#include "Deck.hpp"
#include "YanivPlayer.hpp"
#include "YanivPile.hpp"

namespace CardGames
{
    class YanivTurn : public ITurn
    {
    public:
        enum PickCardFrom
        {
            PILE = 1,
            DECK
        };

        YanivTurn(std::shared_ptr<YanivPlayer> player, std::shared_ptr<YanivPile> pile, std::shared_ptr<Deck> deck);
        virtual ~YanivTurn() {}
        int PlayTurn() override;

    private:
        std::vector<std::size_t> GetIToDiscard(const std::string &name);
        bool PickCardFrom();
        std::shared_ptr<YanivPlayer> m_current_player;
        std::shared_ptr<YanivPile> m_pile;
        std::shared_ptr<Deck> m_deck;
    };
}

#endif // YANIV_TURN_H