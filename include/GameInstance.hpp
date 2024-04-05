#include <string>

namespace CardGames
{
    class GameInstance
    {
    public:
        GameInstance();
        std::string getId() const;

    private:
        std::string generateRandomId() const;

        std::string m_id;
    };
}