#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

int main()
{
    // Define o valor das páginas de código UTF8 e default do Windows
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();

    // Define codificação como sendo UTF-8
    SetConsoleOutputCP(CPAGE_UTF8);

    char palavraSecreta[20];

    sprintf(palavraSecreta, "MELANCIA");
    // ultimo caracter da string é um \0 - sinaliza final da string

    int acertou = 0;
    int enforcou = 0;

    char chutes[26];
    int tentativas = 0;

    do
    {
        // começar o jogo

        for (int i = 0; i < (int)strlen(palavraSecreta); i++)
        {

            int achou = 0;
            for (int j = 0; j < tentativas; j++)
            {
                if (chutes[j] == palavraSecreta[i])
                {
                    achou = 1;
                    break;
                }
            }

            if (achou)
            {
                printf("%c ", palavraSecreta[i]);
            }
            else
            {
                printf("_ ");
            }
        }
        printf("\n");

        char chute;
        scanf(" %c", &chute); // espaço antes é pra ignorar o Enter que pode chegar

        chutes[tentativas] = chute;
        tentativas++;

    } while (!acertou && !enforcou);

    // Retorna codificação padrão do Windows
    SetConsoleOutputCP(CPAGE_DEFAULT);
}
