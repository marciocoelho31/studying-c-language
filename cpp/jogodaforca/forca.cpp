#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

string palavraSecreta = "MELANCIA";
map<char, bool> chutou;
vector<char> chutesErrados;

bool letraExiste(char chute)
{
    for (char letra : palavraSecreta)
    {
        if (chute == letra)
        {
            return true;
        }
    }

    return false;
}

bool naoAcertou()
{
    for (char letra : palavraSecreta)
    {
        if (!chutou[letra])
        {
            return true;
        }
    }
    return false;
}

bool naoEnforcou()
{
    return (chutesErrados.size() < 5);
}

void imprimeCabecalho()
{
    cout << "*********************" << endl;
    cout << "*** Jogo da Forca ***" << endl;
    cout << "*********************" << endl;
    cout << endl;
}

void imprimeChutesErrados()
{
    if (chutesErrados.size() > 0)
    {
        cout << "Chutes errados: ";
        for (char letra : chutesErrados)
        {
            cout << letra << " ";
        }
        cout << endl;
    }
}

void imprimePalavraSecreta()
{
    for (char letra : palavraSecreta)
    {
        if (chutou[letra])
        {
            cout << letra << " ";
        }
        else
        {
            cout << "_ ";
        }
    }
    cout << endl;
}

void chuta()
{
    cout << "Seu chute: ";

    char chute;
    cin >> chute;

    chutou[chute] = true;

    if (letraExiste(chute))
    {
        cout << "Voce acertou! Seu chute esta na palavra." << endl;
    }
    else
    {
        cout << "Voce errou! Seu chute nao esta na palavra." << endl;
        chutesErrados.push_back(chute);
    }
    cout << endl;
}

vector<string> leArquivo()
{
    ifstream arquivo; // (input file stream)
    arquivo.open("palavras.txt");

    if (arquivo.is_open())
    {
        int quantidadePalavras;
        arquivo >> quantidadePalavras;
        // cout << "O arquivo possui " << quantidadePalavras << " palavras." << endl;

        vector<string> palavrasDoArquivo;

        for (int i = 0; i < quantidadePalavras; i++)
        {
            string palavraLida;
            arquivo >> palavraLida;
            // cout << "Na linha " << i << ": " << palavraLida << endl;
            palavrasDoArquivo.push_back(palavraLida);
        }

        arquivo.close();

        return palavrasDoArquivo;
    }
    else
    {
        cout << "Nao foi possivel acessar o banco de palavras." << endl;
        exit(0);
    }
}

void sorteiaPalavra()
{
    vector<string> palavras = leArquivo();

    srand(time(NULL));
    int indiceSorteado = rand() & palavras.size();

    palavraSecreta = palavras[indiceSorteado];
}

void salvaArquivo(vector<string> novaLista)
{
    ofstream arquivo;
    arquivo.open("palavras.txt");
    if (arquivo.is_open())
    {
        arquivo << novaLista.size() << endl;
        for (string palavra : novaLista)
        {
            arquivo << palavra << endl;
        }
        arquivo.close();
    }
    else
    {
        cout << "Nao foi possivel acessar o banco de palavras." << endl;
        exit(0);
    }
}

void adicionaPalavraAoBanco()
{
    cout << "Digite a nova palavra, usando letras maiusculas: " << endl;
    string novaPalavra;
    cin >> novaPalavra;

    vector<string> listaPalavras = leArquivo();
    listaPalavras.push_back(novaPalavra);

    salvaArquivo(listaPalavras);
}

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
