#include "unity.h"
#include "mapa.h"
#include <stdio.h>


#include "unity.h"
#include "../include/mapa.h"
#include "../include/pecman.h"  
#include <stdlib.h>
#include <stdio.h>
//Para testar Primeiro compile: gcc -DTEST test_imprimemapa.c ../src/mapa.c ../src/pecman.c unity.c -I../include -o test_imprimemapa.exe
//Depois rode: ./test_imprimemapa.exe


MAPA m8;

void setUp() {
    m8.linhas = 2;
    m8.colunas = 2;
    alocamapa(&m8);
    m8.matriz[0][0] = 'X';
    m8.matriz[0][1] = '.';
    m8.matriz[1][0] = '.';
    m8.matriz[1][1] = 'H';
}

void tearDown() {
    liberamapa(&m8);
}

void test_imprimemapa_nao_crasha() {
    imprimemapa(&m8);
    TEST_PASS();
}


int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_imprimemapa_nao_crasha);



    return UNITY_END();
}