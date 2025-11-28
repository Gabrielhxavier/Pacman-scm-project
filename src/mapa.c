#include <stdio.h>
#include <stdlib.h>
#include "../include/mapa.h"
#include "../include/pecman.h"
#include <string.h>

void copiamapa(MAPA* original, MAPA* copia){
    copia->linhas = original->linhas;
    copia->colunas = original->colunas;

    alocamapa(copia);

    for (int i = 0; i < copia->linhas; i++)
    {
        strcpy(copia->matriz[i], original->matriz[i]);
    }
}

void andanomapafantasma(MAPA* m, int origemx, int origemy, int destinox, int destinoy, char heroi){
    m->matriz[destinox][destinoy] = heroi;
    m->matriz[origemx][origemy] = VAZIO;
}

void andanomapa(MAPA* m, int* origemx, int* origemy, int* destinox, int *destinoy, char heroi){
    m->matriz[*destinox][*destinoy] = heroi;
    m->matriz[*origemx][*origemy] = VAZIO;

    *origemx = *destinox;
    *origemy = *destinoy;

}

int ehparede(MAPA* m, int x, int y){
    if(m->matriz[x][y] == BORDAH || m->matriz[x][y] == BORDAV){
        return 1;
    }
return 0;
}

int ehpersonagem(MAPA* m, int x, int y, char personagem){
    if(m->matriz[x][y] == personagem){
        return 1;
    }
return 0;
}
int podeandarnomapa(MAPA* m, int x, int y, char personagem){

    // 1. VERIFICA POSIÇÕES INVÁLIDAS (NEGATIVAS OU MAIORES QUE O MAPA)
    if (x < 0 || x >= m->linhas) 
        return 0;

    if (y < 0 || y >= m->colunas) 
        return 0;

    // 2. SE FOR PAREDE → NÃO PODE ANDAR
    if (ehparede(m, x, y))
        return 0;

    // 3. NÃO PODE ANDAR SOBRE O MESMO PERSONAGEM
    if (ehpersonagem(m, x, y, personagem))
        return 0;

    return 1;
}


int encontraheroi(POSICAO* p, MAPA* m, char c){
    for (int i = 0; i < m->linhas; i++)
    {
        for (int j = 0; j < m->colunas; j++)
        {
            if (m->matriz[i][j] == HEROI)
            {
                p-> x = i;
                p-> y = j;
                return 1;
            }
        }  
    }
    return 0;
}

void liberamapa(MAPA* m){
    for (int i = 0; i < m->linhas; i++)
    {
        free(m->matriz[i]);
    }
    free(m->matriz); 
}

void lemapa(MAPA* m){
    FILE* f;                                    //  declarando o tipo da variável como file (ponteiro) para abrir o arquivo
    
    f = fopen("mapa.txt","r");        
    if (f==0){
        printf("erro.\n");
        exit(1);
    }
    
    fscanf(f,"%d %d", &(m->linhas), &(m->colunas));

    alocamapa(m);

    for (int i=0; i < m->linhas; i++){
        fscanf(f,"%s", m->matriz[i]);
    }
    
    fclose(f);                                  // realizando o fechamento do arquivo

}

void alocamapa(MAPA* m){
    m->matriz =  malloc(sizeof(char *)* m->linhas);
    for (int i=0; i< m->linhas; i++){
        m->matriz[i] = malloc(sizeof(char)*(m->colunas+1));
    }
}

void imprimemapa(MAPA* m){
    for (int i=0; i < m->linhas; i++){
        printf("%s", m->matriz[i]);
        printf("\n");
    }
}