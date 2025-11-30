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

int gameon(){

    system("clear || cls");

    printf("=====================================\n");
    printf("=               PECMAN              =\n");
    printf("=====================================\n");
    printf("=        Controles do jogo:         =\n");
    printf("=  W - Mover para cima              =\n");
    printf("=  A - Mover para esquerda          =\n");
    printf("=  S - Mover para baixo             =\n");
    printf("=  D - Mover para direita           =\n");
    printf("=====================================\n");
    printf("=  P - Pausar o jogo                =\n");
    printf("=====================================\n");
    printf("=      Pressione qualquer tecla     =\n");
    printf("=         para iniciar o jogo       =\n");  
    printf("=====================================\n");
    getchar();
    system("clear || cls");

    return 0;
}

void pause(char direcao) {

    system("clear || cls");
    int gameover(void);
    
    if (direcao == 'p' || direcao == 'P') {  
        
        printf("=====================================\n");
        printf("=           Jogo Pausado            =\n");
        printf("=====================================\n");
        printf("    Qualquer letra para continuar   =\n");
        printf("=                ou                 =\n");  
        printf("=            Q para SAIR            =\n");  
        printf("=====================================\n");

        char input;
        scanf(" %c", &input);
        
        while (getchar() != '\n');

        if (input == 'q' || input == 'Q') {
            system("clear || cls");
            gameover();
            
        }
        
        system("clear || cls");
    }
}

int gameover(){

    char retry = '\n';      
    
    printf("              ██████████             \n");
    printf("             █          █            \n");
    printf("            █   ██   ██  █           \n");
    printf("            █   ██   ██  █           \n");
    printf("             █          █            \n");
    printf("              █  █  █  █             \n");
    printf("              █  █  █  █             \n");
    printf("                                     \n");
    printf("=====================================\n");  
    printf("=              GAME OVER            =\n");
    printf("=====================================\n");
    printf("=        R - Jogar novamente        =\n");
    printf("=  Qualquer outra tecla para SAIR   =\n");
    printf("=====================================\n");
    
    scanf(" %c", &retry);

    if (retry == 'R' || retry == 'r') {
        lemapa(&m);
        return 1;
    }
        system("clear || cls");
        printf("=====================================\n");  
        printf("=            JOGO ENCERRADO         =\n");
        printf("=====================================\n");
        exit(0); 
}

#ifndef TEST
int main() {

    int pagina = 0;
    int loop = 1;

    while (loop){
   
        switch (pagina){

            case 0:
                gameon();
                lemapa(&m);
                encontraheroi(&heroi, &m, HEROI);

                do {
                    limpatela();
                    imprimemapa(&m);                      // função para imprimir o mapa no loop

                    char direcao;                       // char que vai armazenar a mudança de direção do herói

                    scanf(" %c", &direcao); 
            
                    pause(direcao);
                    move(direcao);
                    fantasma();

                } 
                while(!acabou());
                liberamapa(&m);   
            pagina = 1;
            break;

            case 1:

                if (gameover()) {
                    pagina = 0; // Reinicia o jogo
                    } else {
                    exit(0); // Encerra o programa
                    }
            break;

        }
    }
    return 0;  
}
#endif