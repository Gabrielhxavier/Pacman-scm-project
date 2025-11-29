#include "../include/mapa.h"
#include "../include/pecman.h"  
#include <stdlib.h>
#include <stdio.h>
#include "unity.h"
 

// Para testar Primeiro compile: gcc -DTEST test_alocamapa.c ../src/mapa.c ../src/pecman.c unity.c -I../include -o test_alocamapa.exe

//Depois rode: ./test_alocamapa.exe




void setUp() {}
void tearDown() {}

void test_alocamapa_cria_matriz_com_dimensoes_corretas() {
    MAPA m1;
    m1.linhas = 5;
    m1.colunas = 7;

    alocamapa(&m1);

    TEST_ASSERT_NOT_NULL(m1.matriz);
    for(int i = 0; i < m1.linhas; i++) {
        TEST_ASSERT_NOT_NULL(m1.matriz[i]);
    }

    liberamapa(&m1);
}



int main() {
    UNITY_BEGIN();

    RUN_TEST(test_alocamapa_cria_matriz_com_dimensoes_corretas);


    return UNITY_END();
}
