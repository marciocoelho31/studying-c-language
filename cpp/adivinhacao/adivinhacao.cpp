#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    cout << "*************************************" << endl;
    cout << "* Bem vindo ao jogo de adivinhacao! *" << endl;
    cout << "*************************************" << endl;

    cout << "Escolha o seu nivel de dificuldade: " << endl;
    cout << "Facil (F), Medio (M) ou Dificil (D)" << endl;

    char dificuldade;
    cin >> dificuldade;

    int numeroDeTentativas;
    if (dificuldade == 'F')
    {
        numeroDeTentativas = 15;
    }
    else if (dificuldade == 'M')
    {
        numeroDeTentativas = 10;
    }
    else
    {
        numeroDeTentativas = 5;
    }

    srand(time(0));
    const int NUMERO_SECRETO = rand() % 100;

    bool naoAcertou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    for (tentativas = 1; tentativas <= numeroDeTentativas; tentativas++)
    {
        int chute;
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual seu chute? ";
        cin >> chute;

        double pontosPerdidos = abs(chute - NUMERO_SECRETO) / 2.0;
        pontos -= pontosPerdidos;

        cout << "O valor do seu chute eh " << chute << endl;

        bool acertou = (chute == NUMERO_SECRETO);
        bool chuteMaior = (chute > NUMERO_SECRETO);

        if (acertou)
        {
            cout << "Parabens, voce acertou" << endl;
            naoAcertou = false;
            break;
        }
        else if (chuteMaior)
        {
            cout << "Seu chute foi maior do que o numero secreto" << endl;
        }
        else
        {
            cout << "Seu chute foi menor do que o numero secreto" << endl;
        }
    }

    cout << "Fim de jogo!" << endl;

    if (naoAcertou)
    {
        cout << "Voce perdeu! Tente novamente!" << endl;
    }
    else
    {
        cout << "Voce acertou o numero secreto em " << tentativas << " tentativas!" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuacao foi de " << pontos << " pontos" << endl;
    }
}