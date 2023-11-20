#include <iostream>
#include <fstream>
#include "leArquivo.hpp"

std::vector<std::string> leArquivo()
{
    std::ifstream arquivo; // (input file stream)
    arquivo.open("palavras.txt");

    if (arquivo.is_open())
    {
        int quantidadePalavras;
        arquivo >> quantidadePalavras;
        // cout << "O arquivo possui " << quantidadePalavras << " palavras." << endl;

        std::vector<std::string> palavrasDoArquivo;

        for (int i = 0; i < quantidadePalavras; i++)
        {
            std::string palavraLida;
            arquivo >> palavraLida;
            // cout << "Na linha " << i << ": " << palavraLida << endl;
            palavrasDoArquivo.push_back(palavraLida);
        }

        arquivo.close();

        return palavrasDoArquivo;
    }
    else
    {
        std::cout << "Nao foi possivel acessar o banco de palavras." << std::endl;
        exit(0);
    }
}
