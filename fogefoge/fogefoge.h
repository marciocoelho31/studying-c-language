#define ACIMA 'w'
#define ABAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'

int acabou();
void move(char direcao);
int ehDirecao(char direcao);
void fantasmas();
int praOndeFantasmaVai(int xatual, int yatual, int *xdestino, int *ydestino);
