#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    int tabuleiro[10][10];
    int navio = 3;//tamanho do navio

    // Inicializa o tabuleiro com zeros
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    //colocar navios
    int navio_horizontal[3] = {3,3,3};
    int navio_vertical[3] = {3,3,3};

    //cordenadas no navio
    int linha_h = 2, coluna_h = 4;
    int linha_v = 6, coluna_v = 1;

    // Verifica se há sobreposição
    int sobreposicao = 0;
    for (int i = 0; i < navio; i++) {
        if (tabuleiro[linha_h][coluna_h + i] == 3 || tabuleiro[linha_v + i][coluna_v] == 3) {
            sobreposicao = 1;
            break;
        }
    }

    if (!sobreposicao) {
        // Posiciona navio horizontal
        for (int i = 0; i < navio; i++) {
            tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i];
        }

        // Posiciona navio vertical
        for (int i = 0; i < navio; i++) {
            tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
        }
    } else {
        printf("Erro: os navios se sobrepõem.\n");
        return 1;
    }

    

    // Cabeçalho com letras A-J
    printf("   ");
    for (char letra = 'A'; letra <= 'J'; letra++) {
        printf(" %c", letra);
    }
    printf("\n");

    // Imprime linhas numeradas com conteúdo do tabuleiro
    for (int i = 0; i < 10; i++) {
        printf("%2d", i + 1);
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

}
