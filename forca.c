#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

// variáveis globais - usar só quando for necessário
char palavraSecreta[20];
char chutes[26];
int tentativas = 0;

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

    chutes[tentativas] = chute;
    tentativas++;
}

int jaChutou(char letra)
{
    int achou = 0;
    for (int j = 0; j < tentativas; j++)
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
    sprintf(palavraSecreta, "MELANCIA");
    // ultimo caracter da string é um \0 - sinaliza final da string
}

int main()
{
    int acertou = 0;
    int enforcou = 0;

    configuraCodificacaoUtf8(0);
    escolhePalavra();
    abertura();

    do
    {
        desenhaForca();
        chuta();

    } while (!acertou && !enforcou);

    configuraCodificacaoUtf8(1);
}
