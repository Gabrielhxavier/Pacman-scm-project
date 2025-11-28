#include "unity.h"
#include "mapa.h"


#include "unity.h"
#include "../include/mapa.h"
#include "../include/pecman.h"  
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//Para testar Primeiro compile: gcc -DTEST test_ehparede.c ../src/mapa.c ../src/pecman.c unity.c -I../include -o test_ehparede.exe
//Depois rode: ./test_ehparede.exe

MAPA m4;

void setUp() {
    m4.linhas = 3;
    m4.colunas = 3;

    alocamapa(&m4);

    strcpy(m4.matriz[0], "---");
    strcpy(m4.matriz[1], "-.-");
    strcpy(m4.matriz[2], "---");
}

void tearDown() {
    liberamapa(&m4);
}

void test_ehparede() {
    TEST_ASSERT_TRUE(ehparede(&m4, 0, 0));
    TEST_ASSERT_FALSE(ehparede(&m4, 1, 1));
}


int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_ehparede);


    return UNITY_END();
}