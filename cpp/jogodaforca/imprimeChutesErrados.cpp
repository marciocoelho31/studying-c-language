#include <iostream>
#include <vector>

extern std::vector<char> chutesErrados;

void imprimeChutesErrados()
{
    if (chutesErrados.size() > 0)
    {
        std::cout << "Chutes errados: ";
        for (char letra : chutesErrados)
        {
            std::cout << letra << " ";
        }
        std::cout << std::endl;
    }
}
