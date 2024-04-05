#include <random>
#include <sstream>
#include <iomanip>

#include "GameInstance.hpp"
// assign a unique identifier to each game instance when it is created.

namespace CardGames
{
    GameInstance::GameInstance() : m_id(generateRandomId()) {}

    std::string GameInstance::getId() const { return m_id; }

    std::string GameInstance::generateRandomId() const
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 15);

        std::stringstream ss;
        ss << std::hex;
        for (int i = 0; i < 16; ++i)
        {
            ss << std::uppercase << std::setw(2) << std::setfill('0') << dis(gen);
        }
        return ss.str();
    }

}