#include "YanivPile.hpp"
#include <iostream> // cout, endl

namespace CardGames
{

    std::shared_ptr<Card> YanivPile::GetPervCard(CardFromPile cardFromPile)
    {
        std::shared_ptr<Card> chosenCard;

        if (cardFromPile == CardFromPile::Top)
        {
            chosenCard = m_Prev.back();
        }
        else
        {
            chosenCard = m_Prev.front();
        }

        TakenFromDeck();

        return chosenCard;
    }

    void YanivPile::DiscardToPile(std::vector<std::shared_ptr<Card>> discarded) // make vector? seechatgpt
    {
        m_Prev = m_current;
        m_current = discarded;
    }

    void YanivPile::TakenFromDeck()
    {
        m_Prev = m_current;
    }

    void YanivPile::PrintPile()
    {

        std::cout << "\n last discarded:  " << std::endl;
        for (const auto &sharedCard : m_current)
        {
            sharedCard.get()->PrintCard();
        }
        std::cout << "\n prev discarded:  " << std::endl;
        for (const auto &sharedCard : m_Prev)
        {
            sharedCard.get()->PrintCard();
        }
        std::cout << std::endl;
    }

}
