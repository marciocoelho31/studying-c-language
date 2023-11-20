#include <vector>
#include <string>
#include <ctime>
#include "leArquivo.hpp"

extern std::string palavraSecreta;

void sorteiaPalavra()
{
    std::vector<std::string> palavras = leArquivo();

    srand(time(NULL));
    int indiceSorteado = rand() & palavras.size();

    palavraSecreta = palavras[indiceSorteado];
}
