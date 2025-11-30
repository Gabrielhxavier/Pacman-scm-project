#ifndef _MAPA_H_
#define _MAPA_H_

#define HEROI '@'
#define VAZIO '.'
#define BORDAV '|'
#define BORDAH '-'
#define FANTASMA 'F'

extern char desenhoparede[4][7];
extern char desenhofantasma[4][7];
extern char desenhoheroi[4][7];
extern char desenhovazio[4][7];

struct mapa
{
    char** matriz;
    int linhas;
    int colunas;
};

typedef struct mapa MAPA;

struct posicao
{
    int x;
    int y;
};

typedef struct posicao POSICAO;

void liberamapa(MAPA* m);
void lemapa(MAPA* m);
void alocamapa(MAPA* m);
void imprimemapa(MAPA* m);
void imprimeparte(char desenho[4][7], int parte);
int encontraheroi(POSICAO* p, MAPA* m, char c);
int podeandarnomapa(MAPA* m, int x, int y, char personagem);
void andanomapa(MAPA* m, int* origemx, int* origemy, int* destinox, int* destinoy, char heroi);
void copiamapa(MAPA* original, MAPA* copia);
void andanomapafantasma(MAPA* m, int origemx, int origemy, int destinox, int destinoy, char heroi);
int ehparede(MAPA* m, int x, int y);
int ehpersonagem(MAPA* m, int x, int y, char personagem);

#endif