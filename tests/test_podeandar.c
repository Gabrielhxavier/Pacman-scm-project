

#include "unity.h"
#include "../include/mapa.h"
#include "../include/pecman.h"  
#include <stdlib.h>
#include <stdio.h>


MAPA m;


void setUp(void) {
    
    m.linhas = 5;
    m.colunas = 5;

    m.matriz = (char**) malloc(sizeof(char*) * m.linhas);
    if (m.matriz == NULL) {
        perror("malloc falhou");
        exit(1);
    }

    for (int i = 0; i < m.linhas; ++i) {
        m.matriz[i] = (char*) malloc(sizeof(char) * m.colunas);
        if (m.matriz[i] == NULL) {
            perror("malloc falhou");
            
            for (int k = 0; k < i; ++k) free(m.matriz[k]);
            free(m.matriz);
            exit(1);
        }
    }

    for (int i = 0; i < m.linhas; ++i)
        for (int j = 0; j < m.colunas; ++j)
            m.matriz[i][j] = VAZIO;
}

void tearDown(void) {
    if (m.matriz != NULL) {
        for (int i = 0; i < m.linhas; ++i) {
            if (m.matriz[i] != NULL) {
                free(m.matriz[i]);
                m.matriz[i] = NULL;
            }
        }
        free(m.matriz);
        m.matriz = NULL;
    }
    m.linhas = m.colunas = 0;
}


void test_podeandar_posicao_livre(void) {
    
    m.matriz[2][2] = VAZIO;

    int resultado = podeandarnomapa(&m, 2, 2, HEROI);
    TEST_ASSERT_TRUE_MESSAGE(resultado, "esperava que pudesse andar na posição livre");
}

void test_podeandar_parede(void) {
  
    m.matriz[1][1] = BORDAV; 

    int resultado = podeandarnomapa(&m, 1, 1, HEROI);
    TEST_ASSERT_FALSE_MESSAGE(resultado, "esperava que não pudesse andar em parede");
}

void test_podeandar_fora_do_mapa(void) {
  
    int resultado = podeandarnomapa(&m, -1, 3, HEROI);
    TEST_ASSERT_FALSE_MESSAGE(resultado, "esperava que posição fora do mapa não permitisse andar");
}


int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_podeandar_posicao_livre);
    RUN_TEST(test_podeandar_parede);
    RUN_TEST(test_podeandar_fora_do_mapa);

    return UNITY_END();
}
