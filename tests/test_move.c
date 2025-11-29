#include "unity.h"
#include "../include/mapa.h"
#include "../include/pecman.h"

// Para testar Primeiro compile: gcc -DTEST test_move.c ../src/mapa.c ../src/pecman.c unity.c -I../include -o test_move.exe
//Depois rode: ./test_move.exe


extern MAPA m;
extern POSICAO heroi;

void setUp() {

    m.linhas = 3;
    m.colunas = 3;
    alocamapa(&m);


    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            m.matriz[i][j] = VAZIO;

    m.matriz[1][1] = HEROI;

    heroi.x = 1;
    heroi.y = 1;
}

void tearDown() {
    liberamapa(&m);
}

void test_move_anda_para_esquerda() {

    move(ESQUERDA);

    TEST_ASSERT_EQUAL(1, heroi.x);
    TEST_ASSERT_EQUAL(0, heroi.y);
    TEST_ASSERT_EQUAL(HEROI, m.matriz[1][0]);
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_move_anda_para_esquerda);

    return UNITY_END();
}
