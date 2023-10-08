#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Define o valor das páginas de código UTF8 e default do Windows
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();

    // Define codificação como sendo UTF-8
    SetConsoleOutputCP(CPAGE_UTF8);
    // imprime cabeçalho do jogo
    printf("******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");

    int segundos = time(0); // segundos passados desde 01/01/1970
    srand(segundos);
    int numeroSecreto = rand() % 100;

    int chute;

    int ganhou = 0;

    int tentativas = 1;

    double pontos = 1000;

    while (!ganhou)
    {
        printf("Tentativa %d\n", tentativas);
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);

        printf("Seu chute foi %d\n", chute);

        if (chute < 0)
        {
            printf("Você não pode chutar números negativos!\n");
            continue;
        }

        int acertou = (chute == numeroSecreto);
        int maior = (chute > numeroSecreto);

        if (acertou)
        {
            printf("Parabéns! Você acertou na %da. tentativa!\n", tentativas);
            ganhou = 1;
        }

        else if (maior)
        {
            printf("Seu chute foi maior do que o número secreto.\n");
        }

        else
        {
            printf("Seu chute foi menor do que o número secreto.\n");
        }

        tentativas++;

        double pontosPerdidos = abs(chute - numeroSecreto) / (double)2;
        pontos -= pontosPerdidos;
    }

    printf("Fim de jogo!\n");

    printf("Total de pontos: %.1f\n", pontos);

    // Retorna codificação padrão do Windows
    SetConsoleOutputCP(CPAGE_DEFAULT);
}
