#include "unity.h"
#include "mapa.h"


#include "unity.h"
#include "../include/mapa.h"
#include "../include/pecman.h"  
#include <stdlib.h>
#include <stdio.h>

//Para testar Primeiro compile: gcc -DTEST test_encontraheroi.c ../src/mapa.c ../src/pecman.c unity.c -I../include -o test_encontraheroi.exe
//Depois rode: ./test_encontraheroi.exe

MAPA m7;
POSICAO p;
void tearDown() {}
void setUp() {
    m7.linhas = 3;
    m7.colunas = 3;
    alocamapa(&m7);

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            m7.matriz[i][j] = '.';

    m7.matriz[1][1] = HEROI;   // <-- Agora sim
}

void test_encontraheroi_retorna_posicao_correta() {
    int achou = encontraheroi(&p, &m7, HEROI); // <-- Agora sim

    TEST_ASSERT_EQUAL_INT(1, achou);
    TEST_ASSERT_EQUAL_INT(1, p.x);
    TEST_ASSERT_EQUAL_INT(1, p.y);
}
int main(void) { 
    UNITY_BEGIN(); 
    RUN_TEST(test_encontraheroi_retorna_posicao_correta); 
    return UNITY_END(); 
}