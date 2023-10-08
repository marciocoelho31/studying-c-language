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
    printf("\n\n\n");
    printf("               T~~\n");
    printf("               |\n");
    printf("              /"
           "\\\n");
    printf("      T~~     |'| T~~\n");
    printf("  T~~ |    T~ WWWW|\n");
    printf("  |  /\"\\   |  |  |/\\T~~\n");
    printf(" /\"\\ WWW  /\"\\ |' |WW|\n");
    printf("WWWWW/\\| /   \\|'/\\|/\"\\\n");
    printf("|   /__\\/]WWW[\\/__\\WWWW\n");
    printf("|\"  WWWW'|I_I|'WWWW'  |\n");
    printf("|   |' |/  -  \\|' |'  |\n");
    printf("|'  |  |LI=H=LI|' |   |\n");
    printf("|   |' | |[_]| |  |'  |\n");
    printf("|   |  |_|###|_|  |   |\n");
    printf("'---'--'-/___\\-'--'---'\n\n");

    printf("BEM VINDO AO JOGO DE ADIVINHAÇÃO!\n\n\n");

    int segundos = time(0); // segundos passados desde 01/01/1970
    srand(segundos);
    int numeroSecreto = rand() % 100;

    int chute;

    int tentativas = 1;

    double pontos = 1000;

    int acertou = 0;

    int nivel;
    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numeroDeTentativasPermitidas;
    switch (nivel)
    {
    case 1:
        numeroDeTentativasPermitidas = 20;
        break;
    case 2:
        numeroDeTentativasPermitidas = 15;
        break;
    default:
        numeroDeTentativasPermitidas = 6;
        break;
    }

    for (int i = 1; i <= numeroDeTentativasPermitidas; i++)
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

        acertou = (chute == numeroSecreto);
        int maior = (chute > numeroSecreto);

        if (acertou)
        {
            break;
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

    if (acertou)
    {

        printf("      _.-'''''-._\n");
        printf("    .'  _     _  '.\n");
        printf("   /   (_)   (_)   \\\n");
        printf("  |  ,           ,  |\n");
        printf("  |  \\`.       .`/  |\n");
        printf("   \\  '.`'\"\"'\"`.'  /\n");
        printf("    '.  `'---'`  .'\n");
        printf("      '-._____.-'\n\n");

        printf("Você ganhou!\n");
        printf("Você acertou na %da. tentativa!\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);
    }
    else
    {

        printf("  , ; ,   .-'\"\"\"'-.   , ; ,\n");
        printf("  \\|/  .'         '.  \\|//\n");
        printf("   \\-;-/   ()   ()   \\-;-/\n");
        printf("   // ;               ; \\\n");
        printf("  //__; :.         .; ;__\\\n");
        printf(" `-----\'.'-.....-'.'/-----'\n");
        printf("        '.'.-.-,_.'.'\n");
        printf("          '(  (..-'\n");
        printf("            '-'\n\n");

        printf("Você perdeu! Tente de novo!\n");
    }

    // Retorna codificação padrão do Windows
    SetConsoleOutputCP(CPAGE_DEFAULT);
}
