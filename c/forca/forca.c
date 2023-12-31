#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"

// variáveis globais - usar só quando for necessário
char palavraSecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesDados = 0;

void abertura()
{
    printf("*******************\n");
    printf("*  Jogo de Forca  *\n");
    printf("*******************\n\n");
}

void chuta()
{
    char chute;
    scanf(" %c", &chute); // espaço antes é pra ignorar o Enter que pode chegar

    chutes[chutesDados] = chute;
    chutesDados++;
}

int jaChutou(char letra)
{
    int achou = 0;
    for (int j = 0; j < chutesDados; j++)
    {
        if (chutes[j] == letra)
        {
            achou = 1;
            break;
        }
    }
    return achou;
}

void configuraCodificacaoUtf8(int saida)
{
    // Define o valor das páginas de código UTF8 e default do Windows
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    if (!saida)
    {
        // Define codificação como sendo UTF-8
        SetConsoleOutputCP(CPAGE_UTF8);
    }
    else
    {
        // Retorna codificação padrão do Windows
        SetConsoleOutputCP(CPAGE_DEFAULT);
    }
}

void desenhaForca()
{
    int erros = chutesErrados();

    printf("      _______     \n");
    printf("     |/      |    \n");
    printf("     |      %c%c%c\n",
           (erros >= 1 ? '(' : ' '),
           (erros >= 1 ? '_' : ' '),
           (erros >= 1 ? ')' : ' '));
    printf("     |      %c%c%c\n",
           (erros >= 3 ? '\\' : ' '),
           (erros >= 2 ? '|' : ' '),
           (erros >= 3 ? '/' : ' '));
    printf("     |       %c   \n", (erros >= 2 ? '|' : ' '));
    printf("     |      %c %c \n",
           (erros >= 4 ? '/' : ' '),
           (erros >= 4 ? '\\' : ' '));
    printf("     |            \n");
    printf("    _|___         \n");
    printf("\n\n");

    for (int i = 0; i < (int)strlen(palavraSecreta); i++)
    {
        int achou = jaChutou(palavraSecreta[i]);
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
}

void escolhePalavra()
{
    // sprintf(palavraSecreta, "MELANCIA");
    // ultimo caracter da string é um \0 - sinaliza final da string

    FILE *f;
    f = fopen("..\\palavras.txt", "r");
    if (f == 0)
    {
        printf("Desculpe, banco de dados não disponível\n\n");
        exit(1); // 0 saida ok, 1 saida com erro
    }

    int qtdPalavras;
    fscanf(f, "%d", &qtdPalavras); // leu a 1a linha

    srand(time(0));
    int randomico = rand() % qtdPalavras;

    // lê da 2a linha em diante
    for (int i = 0; i <= randomico; i++)
    {
        fscanf(f, "%s", palavraSecreta);
    }

    fclose(f);
}

int chutesErrados()
{
    int erros = 0;
    for (int i = 0; i < chutesDados; i++)
    {

        int existe = 0;
        for (int j = 0; j < (int)strlen(palavraSecreta); j++)
        {
            if (chutes[i] == palavraSecreta[j])
            {
                existe = 1;
                break;
            }
        }

        if (!existe)
        {
            erros++;
        }
    }
    return erros;
}

int enforcou()
{
    return chutesErrados() >= 5;
}

int acertou()
{
    for (int i = 0; i < (int)strlen(palavraSecreta); i++)
    {
        if (!jaChutou(palavraSecreta[i]))
        {
            return 0;
        }
    }
    return 1;
}

void adicionaPalavra()
{
    char quer;
    printf("Você deseja adicionar uma nova palavra ao jogo? (S/N)");
    scanf(" %c", &quer); // espaço antes do %c diz que eu quero pegar apenas um char
    if (quer == 'S')
    {
        char novaPalavra[TAMANHO_PALAVRA];
        printf("Qual a nova palavra? ");
        scanf("%s", novaPalavra);

        FILE *f;
        f = fopen("..\\palavras.txt", "r+");
        if (f == 0)
        {
            printf("Desculpe, banco de dados não disponível\n\n");
            exit(1); // 0 saida ok, 1 saida com erro
        }

        int qtdPalavras;
        fscanf(f, "%d", &qtdPalavras); // leu a 1a linha
        qtdPalavras++;

        // foi pra prox linha mas precisa voltar pra 1a pra gravar
        // a nova qtd de palavras
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtdPalavras);

        fseek(f, 0, SEEK_END); // posiciona no final do arquivo
        fprintf(f, "\n%s", novaPalavra);

        fclose(f);
    }
}

int main()
{
    configuraCodificacaoUtf8(0);
    escolhePalavra();
    abertura();

    do
    {
        desenhaForca();
        chuta();

    } while (!acertou() && !enforcou());

    if (acertou())
    {
        printf("\nParabéns, você ganhou!\n\n");

        printf("             ___________\n");
        printf("            '._==_==_=_.'\n");
        printf("            .-\\:      /-.\n");
        printf("           | (|:.     |) |\n");
        printf("            '-|:.     |-'\n");
        printf("              \\::.    /\n");
        printf("               '::. .'\n");
        printf("                 ) (\n");
        printf("               _.' '._\n");
        printf("              `\"\"\"\"\"\"\"`\n\n");
    }
    else
    {
        printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavraSecreta);

        printf("    _______________\n");
        printf("   /               \\\n");
        printf("  /                 \\\n");
        printf("//                   \\/\\\n");
        printf("\\|   XXXX     XXXX   | /\n");
        printf(" |   XXXX     XXXX   |/\n");
        printf(" |   XXX       XXX   |\n");
        printf(" |                   |\n");
        printf(" \\__      XXX      __/\n");
        printf("   |\\     XXX     /|\n");
        printf("   | |           | |\n");
        printf("   | I I I I I I I |\n");
        printf("   |  I I I I I I  |\n");
        printf("   \\_             _/\n");
        printf("     \\_         _/\n");
        printf("       \\_______/\n\n");
    }

    // adicionaPalavra();

    configuraCodificacaoUtf8(1);
}
