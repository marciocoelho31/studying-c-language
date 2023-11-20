#include <iostream>
#include <vector>
#include <map>
#include "letraExiste.hpp"

extern std::map<char, bool> chutou;
extern std::vector<char> chutesErrados;

void chuta()
{
    std::cout << "Seu chute: ";

    char chute;
    std::cin >> chute;

    chutou[chute] = true;

    if (letraExiste(chute))
    {
        std::cout << "Voce acertou! Seu chute esta na palavra." << std::endl;
    }
    else
    {
        std::cout << "Voce errou! Seu chute nao esta na palavra." << std::endl;
        chutesErrados.push_back(chute);
    }
    std::cout << std::endl;
}
