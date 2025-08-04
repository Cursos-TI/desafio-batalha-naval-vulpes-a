#include <stdio.h>

int main() {
    int mar[10][10] = {0};
    char colunas[] = "ABCDEFGHIJ";

    // Barco horizontal
    int linhaH = 1; 
    int colInicioH = 2;
    for (int i = 0; i < 5; i++) {
        mar[linhaH][colInicioH + i] = 3;
    }

    // Barco vertical
    int colV = 5; 
    int linhaInicioV = 4; 
    for (int i = 0; i < 3; i++) {
        mar[linhaInicioV + i][colV] = 3;
    }

    // Imprime o cabeçalho
    printf("   ");
    for (int i = 0; i < 10; i++) {
        printf("%c ", colunas[i]);
    }
    printf("\n");

    printf("  +");
    for (int i = 0; i < 10; i++) {
        printf("--");
    }
    printf("\n");

    // Imprime a matriz
    for (int linha = 0; linha < 10; linha++) {
        printf("%2d|", linha + 1);
        for (int col = 0; col < 10; col++) {
            printf("%d ", mar[linha][col]);
        }
        printf("\n");
    }

    return 0;
}
