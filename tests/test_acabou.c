#include "unity.h"
#include "../include/mapa.h"
#include "../include/pecman.h"  
#include <stdlib.h>
#include <stdio.h>

// Para testar Primeiro compile: gcc -DTEST test_acabou.c ../src/mapa.c ../src/pecman.c unity.c -I../include -o test_acabou.exe
//Depois rode: ./test_acabou.exe

void setUp() {}
void tearDown() {}

void test_acabou_retorna_0_ou_1() {
    int r = acabou();
    TEST_ASSERT_TRUE(r == 0 || r == 1);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_acabou_retorna_0_ou_1);


    return UNITY_END();
}
