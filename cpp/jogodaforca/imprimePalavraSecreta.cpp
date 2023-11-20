#include <iostream>
#include <string>
#include <map>

extern std::string palavraSecreta;
extern std::map<char, bool> chutou;

void imprimePalavraSecreta()
{
    for (char letra : palavraSecreta)
    {
        if (chutou[letra])
        {
            std::cout << letra << " ";
        }
        else
        {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}
