#ifndef YANIV_PLAYER_H
#define YANIV_PLAYER_H

#include <string>
#include <deque>
#include <vector>
#include <memory>

#include "Card.hpp"
#include "IPlayer.hpp"

namespace CardGames
{
    class YanivPlayer : public IPlayer
    {
    public:
        YanivPlayer(const std::string &name);
        virtual ~YanivPlayer();
        void addToHand(const std::shared_ptr<Card> card);
        // Method to discard one or more cards from the player's hand
        void discardFromHand(const std::vector<int> &indices);

        void displayHand() const override;
        std::string GetName() const override;
        int GetScore() const;
        void SetScore(int newScore);

    private:
        std::string m_name;
        std::deque<std::shared_ptr<Card>> m_hand;
        int m_score;
    };
}

#endif // YANIV_PLAYER_H