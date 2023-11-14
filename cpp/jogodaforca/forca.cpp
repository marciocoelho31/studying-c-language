#include <iostream>
#include <string>
using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";

bool letraExiste(char chute)
{
    for (char letra : PALAVRA_SECRETA)
    {
        if (chute == letra)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    cout << PALAVRA_SECRETA << endl;

    bool naoEnforcou = true;
    bool naoAcertou = true;

    while (naoEnforcou && naoAcertou)
    {
        char chute;
        cin >> chute;

        if (letraExiste(chute))
        {
            cout << "Voce acertou! Seu chute esta na palavra." << endl;
        }
        else
        {
            cout << "Voce errou! Seu chute nao esta na palavra." << endl;
        }
    }
}
