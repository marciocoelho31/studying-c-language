#include <iostream>
#include <string>
#include <vector>
#include "leArquivo.hpp"
#include "salvaArquivo.hpp"

void adicionaPalavraAoBanco()
{
    std::cout << "Digite a nova palavra, usando letras maiusculas: " << std::endl;
    std::string novaPalavra;
    std::cin >> novaPalavra;

    std::vector<std::string> listaPalavras = leArquivo();
    listaPalavras.push_back(novaPalavra);

    salvaArquivo(listaPalavras);
}
