#include <stdio.h>
#include <locale.h>
#include <windows.h>

int main()
{
    // Define o valor das páginas de código UTF8 e default do Windows
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();

    // Define codificação como sendo UTF-8
    SetConsoleOutputCP(CPAGE_UTF8);
    // imprime cabeçalho do jogo
    printf("***********\n");
    printf("* TABUADA *\n");
    printf("***********\n");

    int numero;

    printf("Digite um número inteiro:\n");
    scanf("%d", &numero);

    for (int i = 1; i <= 10; i++)
    {
        printf("%d x %d = %d\n", numero, i, numero * i);
    }

    // Retorna codificação padrão do Windows
    SetConsoleOutputCP(CPAGE_DEFAULT);

    return 0;
}