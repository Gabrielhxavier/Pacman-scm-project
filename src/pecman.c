#include <stdio.h>
#include <stdlib.h>
#include "../include/pecman.h"
#include "../include/mapa.h"
#include <string.h>
#include <time.h>


MAPA m;



POSICAO heroi;
MAPA copia;

int destinofantasma(int xatual, int yatual, int* xdestino, int* ydestino){

    int direcaofantasma;
    srand(time(0));
    

    int opcoes[4][2] = {{xatual, yatual+1},
                        {xatual+1, yatual},
                        {xatual, yatual-1},
                        {xatual-1, yatual}
                        };

    
    for (int i = 0; i < 10; i++)
    {
        direcaofantasma  = rand() % 4;
        if (podeandarnomapa(&m,  opcoes[direcaofantasma][0], opcoes[direcaofantasma][1], FANTASMA)){
            *xdestino = opcoes[direcaofantasma][0];
            *ydestino = opcoes[direcaofantasma][1];
            return 1;
        }
    }
    return 0;
}

void fantasma(){

    copiamapa(&m, &copia);

    for (int i = 0; i < m.linhas; i++)
    {
        for (int j = 0; j < m.colunas; j++)
        {
            if (copia.matriz[i][j]  ==  FANTASMA)
            {
                int xdestino;
                int ydestino;
                int vaiandar =  destinofantasma(i,j,&xdestino, &ydestino);

                if(vaiandar == 1){
                    andanomapafantasma(&m, i, j, xdestino, ydestino, FANTASMA);
                }
            }
        }
    }
    liberamapa(&copia);
}

int acabou(){
    int encontrou = encontraheroi(&heroi, &m, HEROI);
    if (!encontrou)
    {
        return 1;
    }

return 0;
}

int ehvalido(char direcao){
    if(direcao == ESQUERDA || direcao == BAIXO || direcao == DIREITA || direcao == CIMA){
        return  1;
    }
    else{
        return 0;
    }
}

void move(char direcao){
    // fazendo o herói andar (w - sobe,a - esquerda,s - desce,d - direita)
    if( !ehvalido(direcao) ){
        return;
    }

    int proximox, proximoy;

    proximox = heroi.x;
    proximoy = heroi.y;


    switch (direcao)
    {
    case ESQUERDA:
        proximoy--;
        break;
       
    case DIREITA:
        proximoy++;
        break;

    case CIMA:
        proximox--;
        break;

    case BAIXO:
        proximox++;
        break;
    }

    if(!podeandarnomapa(&m, proximox, proximoy, HEROI)){
        return;
    }
 
    andanomapa(&m, &heroi.x, &heroi.y, &proximox, &proximoy, HEROI);

}
#ifndef TEST
int main() {

    lemapa(&m);

    encontraheroi(&heroi, &m, HEROI);

    do {
        imprimemapa(&m);                      // função para imprimir o mapa no loop

        char direcao;                       // char que vai armazenar a mudança de direção do herói

        scanf(" %c", &direcao); 
        
        move(direcao);

        fantasma();

    } 
    while(!acabou());

    
    

    liberamapa(&m);   

    return 0;  
}
#endif