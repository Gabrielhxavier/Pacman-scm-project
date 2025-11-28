#include "unity.h"
#include "../include/mapa.h"
#include "../include/pecman.h"

// Para testar Primeiro compile: gcc -DTEST test_fantasma.c ../src/mapa.c ../src/pecman.c unity.c -I../include -o test_fantasma.exe

//Depois rode: ./test_fantasma.exe

#include "unity.h"
#include "../include/mapa.h"
#include "../include/pecman.h"
#include <stdlib.h>
#include <time.h>

MAPA m5;

void setUp() {
    m5.linhas = 3;
    m5.colunas = 3;
    alocamapa(&m5);

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            m5.matriz[i][j] = '.';

  
    m5.matriz[1][1] = FANTASMA;
}

void tearDown() {
    liberamapa(&m5);
}


void test_fantasma_copia_e_move_ou_nao_quebra() {

    srand(1);

    fantasma();

    int count = 0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(m5.matriz[i][j] == FANTASMA)
                count++;

    TEST_ASSERT_EQUAL(1, count); 
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_fantasma_copia_e_move_ou_nao_quebra);
    return UNITY_END();
}
