#include "unity.h"
#include "mapa.h"


#include "unity.h"
#include "../include/mapa.h"
#include "../include/pecman.h"  
#include <stdlib.h>
#include <stdio.h>

// Para testar Primeiro compile: gcc -DTEST test_andanomapafantasma.c ../src/mapa.c ../src/pecman.c unity.c -I../include -o test_andanomapafantasma.exe


//Depois rode: ./test_andanomapafantasma.exe


MAPA m3;

void setUp() {
    m3.linhas = 3;
    m3.colunas = 3;
    alocamapa(&m3);

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            m3.matriz[i][j] = '.';

    m3.matriz[1][1] = 'F';
}

void tearDown() {
    liberamapa(&m3);
}

void test_fantasma_se_move() {
    andanomapafantasma(&m3, 1, 1, 0, 1, 'F');

    TEST_ASSERT_EQUAL('.', m3.matriz[1][1]);
    TEST_ASSERT_EQUAL('F', m3.matriz[0][1]);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_fantasma_se_move);


    return UNITY_END();
}