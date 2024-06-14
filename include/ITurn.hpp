
#ifndef I_TURN
#define I_TURN

namespace CardGames
{
    class ITurn
    {
    public:
        virtual ~ITurn() {}
        virtual int PlayTurn() = 0;
    };
};

#endif // I_TURN