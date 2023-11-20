#include <vector>

extern std::vector<char> chutesErrados;

bool naoEnforcou()
{
    return (chutesErrados.size() < 5);
}
