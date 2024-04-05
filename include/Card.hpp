#ifndef CARD_H
#define CARD_H

namespace CardGames
{
    class Card
    {
    public:
        enum Ranks
        {
            ACE = 1,
            TWO,
            THREE,
            FOUR,
            FIVE,
            SIX,
            SEVEN,
            EIGHT,
            NINE,
            TEN,
            JACK,
            QUEEN,
            KING,
            JOKER
        };

        enum Suits
        {
            HEARTS = 3,
            DIAMONDS,
            CLUBS,
            SPADES,
            BLACK_JOCKER,
            RED_JOCKER
        }; // ASCII

        enum Color
        {
            RED = 0,
            BLACK
        };

        Card(Ranks RANK, Suits SUIT);
        virtual ~Card();

        Ranks GetRank() const;
        Suits GetSuit() const;
        Color GetColor() const;         // impl
        virtual int GetFaceVal() const; // some games the card have diff val
        void PrintCard() const;

    private:
        Ranks m_rank;
        Suits m_suit;
        Color m_color;

        void DetermineColor();
    };

}

#endif // CARD_H