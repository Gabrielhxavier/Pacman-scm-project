#include "unity.h"
#include "../include/mapa.h"
#include "../include/pecman.h"  
#include <stdlib.h>
#include <stdio.h>

//Para testar Primeiro compile: gcc -DTEST test_lemapa.c ../src/mapa.c ../src/pecman.c unity.c -I../include -o test_lemapa.exe
//Depois rode: ./test_lemapa.exe

MAPA m9;

void setUp() {}
void tearDown() {}

void test_lemapa_carrega_mapa_valido() {
    lemapa(&m9);

    TEST_ASSERT_GREATER_THAN(0, m9.linhas);
    TEST_ASSERT_GREATER_THAN(0, m9.colunas);
    TEST_ASSERT_NOT_NULL(m9.matriz);
}


int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_lemapa_carrega_mapa_valido);



    return UNITY_END();
}
