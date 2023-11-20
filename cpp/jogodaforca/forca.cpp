#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "letraExiste.hpp"
#include "naoAcertou.hpp"
#include "imprimeCabecalho.hpp"
#include "adicionaPalavraAoBanco.hpp"
#include "chuta.hpp"
#include "imprimeChutesErrados.hpp"
#include "imprimePalavraSecreta.hpp"
#include "leArquivo.hpp"
#include "naoEnforcou.hpp"
#include "salvaArquivo.hpp"
#include "sorteiaPalavra.hpp"

using namespace std;

string palavraSecreta;
map<char, bool> chutou;
vector<char> chutesErrados;

int main()
{
    imprimeCabecalho();

    leArquivo();
    sorteiaPalavra();

    while (naoEnforcou() && naoAcertou())
    {
        imprimeChutesErrados();

        imprimePalavraSecreta();

        chuta();
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era " << palavraSecreta << endl;

    if (naoAcertou())
    {
        cout << "Voce perdeu! Tente novamente!" << endl;
    }
    else
    {
        cout << "Parabens, voce acertou a palavra secreta!" << endl;

        cout << "Voce deseja adicionar uma palavra ao banco? (S/N) ";
        char resposta;
        cin >> resposta;
        if (resposta == 'S')
        {
            adicionaPalavraAoBanco();
        }
    }
}
