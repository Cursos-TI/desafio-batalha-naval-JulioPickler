#include <stdio.h>
#include <stdlib.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
        int tabuleiro[10][10];
    int NAVIO = 1;
    int HABILIDADE = 3;

    // Inicializa o tabuleiro com água (valor 0)
    for (int l = 0; l < 10; l++) {
        for (int c = 0; c < 10; c++) {
            tabuleiro[l][c] = 0;
        }
    }

    // POSICIONAMENTO DE NAVIOS 
    // Navio horizontal
    for (int i = 0; i < 3; i++) tabuleiro[1][1 + i] = NAVIO;

    // Navio vertical
    for (int i = 0; i < 3; i++) tabuleiro[2 + i][3] = NAVIO;

    // Navio diagonal 
    for (int i = 0; i < 3; i++) tabuleiro[2 + i][2 + i] = NAVIO;

    // Navio diagonal 
    for (int i = 0; i < 3; i++) tabuleiro[2 + i][6 - i] = NAVIO;

    //MATRIZES DE HABILIDADE 3x3

    int cone[3][3], cruz[3][3], losango[3][3];

    // Cone: 
    for (int  l = 0; l < 3; l++) {
        for (int c = 0; c < 3; c++) {
            cone[l][c] = (c >= 1 - l && c <= 1 + l) ? 1 : 0;
        }
    }

    // Cruz:
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 3; c++) {
            cruz[l][c] = (l == 1 || c == 1) ? 1 : 0;
        }
    }

    // Losango:
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 3; c++) {
            losango[l][c] = (abs(l - 1) + abs(c - 1) <= 1) ? 1 : 0;
        }
    }

    //  SOBREPOSIÇÃO 

    void aplicar(int matriz[3][3], int origem_l, int origem_c) 
    {
        for (int l = 0; l < 3; l++) {
            for (int c = 0; c < 3; c++) {
                int tab_l = origem_l - 1 + l;
                int tab_c = origem_c - 1 + c;
                if (matriz[l][c] == 1 &&
                    tab_l >= 0 && tab_l < 10 &&
                    tab_c >= 0 && tab_c < 10 &&
                    tabuleiro[tab_l][tab_c] == 0) {
                    tabuleiro[tab_l][tab_c] = HABILIDADE;
                }
            }
        }
    }

    // Aplica habilidades
    aplicar(cone, 4, 1);     // Cone centrado em (4,1)
    aplicar(cruz, 4, 5);     // Cruz centrada em (4,5)
    aplicar(losango, 4, 8);  // Losango centrado em (4,8)

    //EXIBIÇÃO DO TABULEIRO 

    printf("\nTabuleiro:\n\n");

    // Cabeçalho de colunas
    printf("   ");
    for (int c = 0; c < 10; c++) printf("%2d ", c);
    printf("\n");

    // Linhas com índice e conteúdo
    for (int l = 0; l < 10; l++) {
        printf("%2d ", l);
        for (int c = 0; c < 10; c++) {
            int v = tabuleiro[l][c];
            if (v == 0) printf(" ~ ");
            else if (v == NAVIO) printf(" N ");
            else if (v == HABILIDADE) printf(" 3 ");
        }
        printf("\n");
    }
    return 0;

}
