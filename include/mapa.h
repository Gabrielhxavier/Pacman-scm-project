#define HEROI '@'
#define VAZIO '.'
#define BORDAV '|'
#define BORDAH '-'
#define FANTASMA 'F'

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

void liberamapa();
void lemapa();
void alocamapa();
void imprimemapa();
int encontraheroi(POSICAO* p, MAPA* m, char c);
int podeandarnomapa(MAPA* m, int x, int y, char personagem);
void andanomapa(MAPA* m, int* origemx, int* origemy, int* destinox, int* destinoy, char heroi);
void copiamapa(MAPA* original, MAPA* copia);
void andanomapafantasma(MAPA* m, int origemx, int origemy, int destinox, int destinoy, char heroi);
int ehparede(MAPA* m, int x, int y);
int ehpersonagem(MAPA* m, int x, int y, char personagem);
