#include "unity.h"
#include "mapa.h"

#include "unity.h"
#include "../include/mapa.h"
#include "../include/pecman.h"  
#include <stdlib.h>
#include <stdio.h>

// Para testar Primeiro compile: gcc -DTEST test_andanomapa.c ../src/mapa.c ../src/pecman.c unity.c -I../include -o test_andanomapa.exe


//Depois rode: ./test_andanomapa.exe

MAPA m2;

int ox = 1, oy = 1, dx = 1, dy = 2;

void setUp() {
    m2.linhas = 3;
    m2.colunas = 3;
    alocamapa(&m2);

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            m2.matriz[i][j] = '.';

    m2.matriz[1][1] = 'H';
}

void tearDown() {
    liberamapa(&m2);
}

void test_andanomapa_move_personagem() {
    andanomapa(&m2, &ox, &oy, &dx, &dy, 'H');

    TEST_ASSERT_EQUAL('.', m2.matriz[1][1]); 
    TEST_ASSERT_EQUAL('H', m2.matriz[1][2]);  
}


int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_andanomapa_move_personagem);


    return UNITY_END();
}