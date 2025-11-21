#define ESQUERDA 'a'
#define DIREITA 'd'
#define BAIXO 's'
#define CIMA 'w'


int acabou();
void move(char direcao);
int ehvalido(char direcao);
void fantasma();
int destinofantasma(int xatual, int yatual, int* xdestino, int* ydestino);




