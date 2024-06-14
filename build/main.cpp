#include <iostream> // cout, endl
#include <memory>
#include <sstream>
#include <cctype>

#include "IDeck.hpp"
#include "ITurn.hpp"
#include "IPlayer.hpp"
#include "Deck.hpp"
#include "YanivPlayer.hpp"
#include "IGame.hpp"
#include "GameYaniv.hpp"
#include "YanivPile.hpp"
#include "YanivTurn.hpp"

using namespace CardGames;
using namespace std;

int BasicDeckPlayerTest();
int PileTest();
int RuntimeTest();
// Function to convert a string to a number
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

vector<std::size_t> GetIToDiscard(const std::string &name)
{
    vector<std::size_t> lastCardIndex;

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

int main()
{
    RuntimeTest();

    return 0;
}

//    cout << "" << endl;

int RuntimeTest()
{
    shared_ptr<Deck> deckPtr = make_shared<Deck>();
    deckPtr->ShuffelDeck();
    deckPtr->PrintDeck();

    shared_ptr<YanivPlayer> daniel = make_shared<YanivPlayer>("dani");
    for (int i = 5; i > 0; --i)
    {
        daniel->addToHand(deckPtr->GetTopCard());
    }

    shared_ptr<YanivPlayer> chen = make_shared<YanivPlayer>("chu");
    for (int i = 5; i > 0; --i)
    {
        chen->addToHand(deckPtr->GetTopCard());
    }

    daniel->displayHand();
    chen->displayHand();

    shared_ptr<YanivPile> pile = make_shared<YanivPile>();
    YanivTurn chenturn(chen, pile, deckPtr);
    YanivTurn daniturn(daniel, pile, deckPtr);

    chenturn.PlayTurn();
    daniturn.PlayTurn();

    return 0;
}

int runtimeme()
{
    shared_ptr<IDeck> deckPtr = make_shared<Deck>();
    deckPtr->ShuffelDeck();
    deckPtr->PrintDeck();

    shared_ptr<YanivPlayer> daniel = make_shared<YanivPlayer>("dani");
    for (int i = 5; i > 0; --i)
    {
        daniel->addToHand(deckPtr->GetTopCard());
    }

    shared_ptr<YanivPlayer> chen = make_shared<YanivPlayer>("chu");
    for (int i = 5; i > 0; --i)
    {
        chen->addToHand(deckPtr->GetTopCard());
    }

    daniel->displayHand();
    chen->displayHand();

    YanivPile pile;

    vector<std::size_t> indexToDiscard = GetIToDiscard("dani");

    pile.DiscardToPile(daniel->discardFromHand(indexToDiscard));
    daniel->displayHand();
    pile.PrintPile();

    cout << " dani takes from deck:" << endl;
    daniel->addToHand(deckPtr->GetTopCard());
    daniel->displayHand();

    indexToDiscard = GetIToDiscard("chen");
    pile.DiscardToPile(chen->discardFromHand(indexToDiscard));
    chen->displayHand();
    pile.PrintPile();

    cout << " chen takes from pile:" << endl;
    chen->addToHand(pile.GetPervCard());
    chen->displayHand();
    pile.PrintPile();

    indexToDiscard = {daniel->GetHandSize() - 1};
    indexToDiscard.push_back(daniel->GetHandSize() - 1);

    pile.DiscardToPile(daniel->discardFromHand(indexToDiscard));
    daniel->displayHand();
    pile.PrintPile();
    return 0;
}

int PileTest()
{
    shared_ptr<IDeck> deckPtr = make_shared<Deck>();
    deckPtr->ShuffelDeck();
    deckPtr->PrintDeck();

    shared_ptr<YanivPlayer> daniel = make_shared<YanivPlayer>("dani");
    for (int i = 5; i > 0; --i)
    {
        daniel->addToHand(deckPtr->GetTopCard());
    }

    shared_ptr<YanivPlayer> chen = make_shared<YanivPlayer>("chu");
    for (int i = 5; i > 0; --i)
    {
        chen->addToHand(deckPtr->GetTopCard());
    }

    daniel->displayHand();
    chen->displayHand();

    YanivPile pile;

    cout << " dani first discard::" << endl;

    vector<std::size_t> lastCardIndex = {daniel->GetHandSize() - 1};
    pile.DiscardToPile(daniel->discardFromHand(lastCardIndex));
    daniel->displayHand();
    pile.PrintPile();

    cout << " dani takes from deck:" << endl;
    daniel->addToHand(deckPtr->GetTopCard());
    daniel->displayHand();

    cout << " chen first discard::" << endl;

    lastCardIndex = {chen->GetHandSize() - 1};
    pile.DiscardToPile(chen->discardFromHand(lastCardIndex));
    chen->displayHand();
    pile.PrintPile();

    cout << " chen takes from pile:" << endl;
    chen->addToHand(pile.GetPervCard());
    chen->displayHand();
    pile.PrintPile();

    cout << " dani discards of two cards: (no ruls at this point!)" << endl;

    lastCardIndex = {daniel->GetHandSize() - 1};
    lastCardIndex.push_back(daniel->GetHandSize() - 1);

    pile.DiscardToPile(daniel->discardFromHand(lastCardIndex));
    daniel->displayHand();
    pile.PrintPile();

    return 0;
}

int BasicDeckPlayerTest()
{
    shared_ptr<IDeck> deckPtr = make_shared<Deck>();
    deckPtr->ShuffelDeck();
    deckPtr->PrintDeck();

    shared_ptr<IPlayer> daniel = make_shared<YanivPlayer>("dani");
    cout << "player name:" << daniel->GetName() << endl;
    for (int i = 5; i > 0; --i)
    {
        daniel->addToHand(deckPtr->GetTopCard());
    }

    daniel->displayHand();

    shared_ptr<IPlayer> chen = make_shared<YanivPlayer>("chu");
    for (int i = 5; i > 0; --i)
    {
        chen->addToHand(deckPtr->GetTopCard());
    }

    cout << "the deck:   " << endl;
    deckPtr->PrintDeck();
    daniel->displayHand();
    chen->displayHand();

    return 0;
}
