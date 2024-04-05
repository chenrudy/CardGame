#include <iostream> // cout, endl
#include <memory>

#include "IDeck.hpp"
#include "IPlayer.hpp"
#include "Deck.hpp"
#include "YanivPlayer.hpp"
#include "IGame.hpp"
#include "GameYaniv.hpp"
#include "YanivPile.hpp"

using namespace CardGames;
using namespace std;

int BasicDeckPlayerTest();
int PileTest();

int main()
{
    PileTest();

    // std::shared_ptr<IGame> daniel = std::make_shared<GameYaniv>();

    return 0;
}

//    cout << "" << endl;

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
