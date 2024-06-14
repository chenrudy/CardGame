#include "YanivTurn.hpp"
#include "YanivPile.hpp"

#include <vector>
#include <iostream>
#include <cctype>
#include <iostream>

namespace CardGames
{
    YanivTurn::YanivTurn(std::shared_ptr<YanivPlayer> player, std::shared_ptr<YanivPile> pile, std::shared_ptr<Deck> deck) : m_current_player(player), m_pile(pile), m_deck(deck)
    {
    }
    size_t stringToNumber(const std::string &str)
    {
        std::istringstream iss(str);
        size_t num;
        if (!(iss >> num))
        {
            return 0; // Conversion failed
        }
        return num;
    }
    // Function to check if a string represents a number in the range 1 to 7
    bool isValidInput(const std::string &str)
    {
        size_t num = stringToNumber(str);
        return (num >= 1 && num <= 7);
    }

    std::vector<std::size_t> YanivTurn::GetIToDiscard(const std::string &name)
    {
        std::vector<std::size_t> lastCardIndex;

        while (true)
        {
            std::string input;
            std::cout << name << ", choose a card/s to discard: ";
            std::cin >> input;

            // Check if the user wants to exit
            if (input == "e")
            {
                break; // Exit the loop
            }

            // Validate the input
            if (!isValidInput(input))
            {
                std::cout << "Invalid input. Please enter a number between 1 and 7." << std::endl;
                continue; // Prompt for input again
            }

            // Convert the input string to a number and add it to the vector
            lastCardIndex.push_back(stringToNumber(input) - 1);
        }

        return lastCardIndex;
    }
    bool YanivTurn::PickCardFrom()
    {
        std::string input;
        std::cout << "press 0 to pick from deck, or 1 to pick from pile";
        std::cin >> input;
        return stringToNumber(input);
    }

    int YanivTurn::PlayTurn()
    {
        std::vector<std::size_t> indexToDiscard = GetIToDiscard(m_current_player->GetName());

        m_pile->DiscardToPile(m_current_player->discardFromHand(indexToDiscard));
        bool cardFrom = PickCardFrom();
        std::cout << "takes from ";
        if (cardFrom)
        {
            std::cout << " pile " << std::endl;
            m_current_player->addToHand(m_pile->GetPervCard());
        }
        else
        {
            std::cout << " Deck " << std::endl;
            m_current_player->addToHand(m_deck->GetTopCard());
        }

        m_current_player->displayHand();
        return 0;
    }
    // לחלק ל2, זריקת הקלף.קלפים, לקיחת קלף או מהדק או מהערימה
}