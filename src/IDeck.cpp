#include "IDeck.hpp"
#include <iostream>  // cout, endl
#include <algorithm> // shuffle
#include <random>    // mt19937, random_device

namespace CardGames
{
    void IDeck::shuffleDeckHelper(std::vector<std::shared_ptr<Card>> &deck)
    {
        std::random_device rd;
        std::mt19937 randNumGenerator(rd());

        std::shuffle(deck.begin(), deck.end(), randNumGenerator);
    }

    void IDeck::printDeckHelper(const std::vector<std::shared_ptr<Card>> &deck) const
    {
        for (const auto &sharedCard : deck)
        {
            sharedCard.get()->PrintCard();
        }
        std::cout << std::endl;
    }
}