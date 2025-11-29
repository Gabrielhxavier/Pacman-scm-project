#include "unity.h"
#include "../include/mapa.h"
#include "../include/pecman.h"  
#include <stdlib.h>
#include <stdio.h>
//Para testar Primeiro compile: gcc -DTEST test_copiamapa.c ../src/mapa.c ../src/pecman.c unity.c -I../include -o test_copiamapa.exe
//Depois rode: ./test_copiamapa.exe
MAPA m1, m2;


void setUp() {
    m1.linhas = 2;
    m1.colunas = 2;

    alocamapa(&m1);
    m1.matriz[0][0] = 'A';
    m1.matriz[1][1] = 'B';

    m2.linhas = 2;
    m2.colunas = 2;
    alocamapa(&m2);
}

void tearDown() {
    liberamapa(&m1);
    liberamapa(&m2);
}

void test_copiamapa_copia_conteudo() {
    copiamapa(&m1, &m2);

    TEST_ASSERT_EQUAL('A', m2.matriz[0][0]);
    TEST_ASSERT_EQUAL('B', m2.matriz[1][1]);
}


int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_copiamapa_copia_conteudo);


    return UNITY_END();
}
