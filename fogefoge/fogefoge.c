#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

int praOndeFantasmaVai(int xatual, int yatual, int *xdestino, int *ydestino)
{
    int opcoes[4][2] = {
        {xatual, yatual + 1},
        {xatual + 1, yatual},
        {xatual, yatual - 1},
        {xatual - 1, yatual}};

    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        int posicao = rand() % 4; // numero randomico de 0 a 3

        if (podeAndar(&m, FANTASMA, opcoes[posicao][0], opcoes[posicao][1]))
        {
            *xdestino = opcoes[posicao][0];
            *ydestino = opcoes[posicao][1];

            return 1;
        }
    }

    return 0;
}

void fantasmas()
{
    MAPA copia;
    copiaMapa(&copia, &m);

    for (int i = 0; i < m.linhas; i++)
    {
        for (int j = 0; j < m.colunas; j++)
        {
            if (copia.matriz[i][j] == FANTASMA)
            {
                int xdestino;
                int ydestino;
                int encontrou = praOndeFantasmaVai(i, j, &xdestino, &ydestino);

                if (encontrou)
                {
                    andaNoMapa(&m, i, j, xdestino, ydestino);
                }
            }
        }
    }

    liberaMapa(&copia);
}

int acabou()
{
    POSICAO pos;
    int encontrouFogeFoge = encontraMapa(&m, &pos, HEROI);
    return !encontrouFogeFoge;
}

int ehDirecao(char direcao)
{
    return direcao == ACIMA || direcao == ABAIXO || direcao == DIREITA || direcao == ESQUERDA;
}

void move(char direcao)
{
    if (!ehDirecao(direcao))
    {
        return;
    }

    int proximox = heroi.x;
    int proximoy = heroi.y;

    switch (direcao)
    {
    case ESQUERDA:
        proximoy--;
        break;
    case ACIMA:
        proximox--;
        break;
    case ABAIXO:
        proximox++;
        break;
    case DIREITA:
        proximoy++;
        break;
    }

    if (!podeAndar(&m, HEROI, proximox, proximoy))
    {
        return;
    }

    andaNoMapa(&m, heroi.x, heroi.y, proximox, proximoy);
    heroi.x = proximox;
    heroi.y = proximoy;
}

int main()
{
    leMapa(&m);
    encontraMapa(&m, &heroi, HEROI);

    do
    {
        imprimeMapa(&m);

        char comando;
        scanf(" %c", &comando);

        move(comando);

        fantasmas();

    } while (!acabou());

    liberaMapa(&m);
}