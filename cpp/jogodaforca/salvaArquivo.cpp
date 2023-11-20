#include <iostream>
#include <fstream>
#include "salvaArquivo.hpp"

void salvaArquivo(std::vector<std::string> novaLista)
{
    std::ofstream arquivo;
    arquivo.open("palavras.txt");
    if (arquivo.is_open())
    {
        arquivo << novaLista.size() << std::endl;
        for (std::string palavra : novaLista)
        {
            arquivo << palavra << std::endl;
        }
        arquivo.close();
    }
    else
    {
        std::cout << "Nao foi possivel acessar o banco de palavras." << std::endl;
        exit(0);
    }
}
