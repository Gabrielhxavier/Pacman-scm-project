#include "unity.h"
#include "mapa.h"


#include "unity.h"
#include "../include/mapa.h"
#include "../include/pecman.h"  
#include <stdlib.h>
#include <stdio.h>


//Para testar Primeiro compile: gcc -DTEST test_ehpersonagem.c ../src/mapa.c ../src/pecman.c unity.c -I../include -o test_ehpersonagem.exe
//Depois rode: ./test_ehpersonagem.exe
MAPA m5;

void setUp() {
    m5.linhas = 2;
    m5.colunas = 2;
    alocamapa(&m5);

    m5.matriz[0][1] = 'H';
}

void tearDown() {
    liberamapa(&m5);
}

void test_ehpersonagem() {
    TEST_ASSERT_TRUE(ehpersonagem(&m5, 0, 1, 'H'));
    TEST_ASSERT_FALSE(ehpersonagem(&m5, 0, 0, 'H'));
}


int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_ehpersonagem);


    return UNITY_END();
}