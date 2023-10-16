#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

int acabou()
{
    return 0; // por enquanto o jogo nao acaba
}

void move(char direcao)
{
    int x;
    int y;

    m.matriz[heroi.x][heroi.y] = '.';

    switch (direcao)
    {
    case 'a':
        /* esquerda */
        m.matriz[heroi.x][heroi.y - 1] = '@';
        heroi.y--;
        break;
    case 'w':
        /* cima */
        m.matriz[heroi.x - 1][heroi.y] = '@';
        heroi.x--;
        break;
    case 's':
        /* baixo */
        m.matriz[heroi.x + 1][heroi.y] = '@';
        heroi.x++;
        break;
    case 'd':
        /* direita */
        m.matriz[heroi.x][heroi.y + 1] = '@';
        heroi.y++;
        break;
    }
}

int main()
{
    leMapa(&m);
    encontraMapa(&m, &heroi, '@');

    do
    {
        imprimeMapa(&m);

        char comando;
        scanf(" %c", &comando);
        move(comando);

    } while (!acabou());

    liberaMapa(&m);
}