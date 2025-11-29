#include "unity.h"
#include "../include/mapa.h"
#include "../include/pecman.h"  
#include <stdlib.h>
#include <stdio.h>

//Para testar Primeiro compile: gcc -DTEST test_ehvalido.c ../src/mapa.c ../src/pecman.c unity.c -I../include -o test_ehvalido.exe
//Depois rode: ./test_ehvalido.exe

void setUp() {}
void tearDown() {}
MAPA m6; 

void test_ehvalido_direcoes_validas() {
    TEST_ASSERT_TRUE(ehvalido('a'));
    TEST_ASSERT_TRUE(ehvalido('d'));
    TEST_ASSERT_TRUE(ehvalido('w'));
    TEST_ASSERT_TRUE(ehvalido('s'));
}

void test_ehvalido_invalido() {
    TEST_ASSERT_FALSE(ehvalido('x'));
}


int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_ehvalido_invalido);
    RUN_TEST(test_ehvalido_direcoes_validas);


    return UNITY_END();
}
