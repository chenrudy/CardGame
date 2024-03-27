#include "Card.hpp"
#include <iostream> // cout, endl

namespace CardGames
{

    Card::Card(Ranks RANK, Suits SUIT) : m_rank(RANK), m_suit(SUIT)
    {
        DetermineColor();
    }
    Card::~Card()
    {
        // Empty
    }

    Card::Ranks Card::GetRank() const
    {
        return m_rank;
    }
    Card::Suits Card::GetSuit() const
    {
        return m_suit;
    }
    int Card::GetFaceVal() const
    {
        if (m_rank <= TEN)
        {
            return static_cast<int>(m_rank);
        }

        return 10; // royalty are all 10
    }

    void Card::DetermineColor()
    {
        switch (m_suit)
        {
        case Card::HEARTS:
            m_color = RED;
            break;
        case Card::DIAMONDS:
            m_color = RED;
            break;
        case Card::CLUBS:
            m_color = BLACK;
            break;
        case Card::SPADES:
            m_color = BLACK;
            break;
        case Card::BLACK_JOCKER:
            m_color = BLACK;
            break;
        case Card::RED_JOCKER:
            m_color = RED;
            break;
        }
    }

    void Card::PrintCard() const
    {
        switch (this->GetRank())
        {
        case Card::ACE:
            std::cout << "Ace";
            break;
        case Card::TWO:
            std::cout << "Two";
            break;
        case Card::THREE:
            std::cout << "Three";
            break;
        case Card::FOUR:
            std::cout << "Four";
            break;
        case Card::FIVE:
            std::cout << "Five";
            break;
        case Card::SIX:
            std::cout << "Six";
            break;
        case Card::SEVEN:
            std::cout << "Seven";
            break;
        case Card::EIGHT:
            std::cout << "Eight";
            break;
        case Card::NINE:
            std::cout << "Nine";
            break;
        case Card::TEN:
            std::cout << "Ten";
            break;
        case Card::JACK:
            std::cout << "Jack";
            break;
        case Card::QUEEN:
            std::cout << "Queen";
            break;
        case Card::KING:
            std::cout << "King";
            break;
        case Card::JOKER:
            break;
        }

        // Print suit symbol
        switch (this->GetSuit())
        {
        case Card::HEARTS:
            std::cout << "\x1b[1;31m"
                         "\xe2\x99\xa5"
                         "\x1b[0m";
            break; // Heart symbol (♥)
        case Card::DIAMONDS:
            std::cout << "\x1b[1;31m"
                         "\xe2\x99\xa6"
                         "\x1b[0m";
            break; // Diamond symbol (♦)
        case Card::CLUBS:
            std::cout << "\x1b[0m"
                         "\xe2\x99\xa3";
            break; // Club symbol (♣)
        case Card::SPADES:
            std::cout << "\x1b[0m"
                         "\xe2\x99\xa0";
            break; // Spade symbol (♠)
        case Card::RED_JOCKER:
            std::cout << "\x1b[1;31m"
                         "Joker"
                         "\x1b[0m";
            break; // Diamond symbol (♦)
        case Card::BLACK_JOCKER:
            std::cout << "\x1b[0m"
                         "Joker";
            break; //
        }

        std::cout << "  ";
    }

}
