#ifndef _FOGEFOGE_H_
#define _FOGEFOGE_H_

#define ACIMA 'w'
#define ABAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'
#define BOMBA 'b'

int acabou();
void move(char direcao);
int ehDirecao(char direcao);
void fantasmas();
int praOndeFantasmaVai(int xatual, int yatual, int *xdestino, int *ydestino);
void explodePilula();
void explodePilula2(int x, int y, int somax, int somay, int qtd);

#endif
