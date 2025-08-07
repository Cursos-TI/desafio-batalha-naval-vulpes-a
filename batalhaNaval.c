#include <stdio.h>

#define LINHA 10
#define COLUNA 10
#define TAMANHO_NAVIO 3
#define AGUA 0

int main() {

    //Variável que será usada para numeração das colunas
    int v = 0;

    //Criando matriz
    int matriz[LINHA][COLUNA] = {0};

    char linha[10]= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    //Criando a coluna numérica de 1 - 10
    printf("   ");
    for (int j = 0; j < LINHA; j++){
        printf("%c ", linha[j]);
    }
    printf("\n");
    printf("  +");
    for (int j = 0; j < LINHA; j++){
        printf("--", linha[j]);
    }
    printf("\n");

    //Navio vertical
    int barcoL2 = 7;
    int barcoC2 = 3;
    for (int i = TAMANHO_NAVIO; i > 0; i--) {
            matriz[barcoL2 + i - 1][barcoC2] = 3;
    }

    //Navio horizontal
    int barcoL1 = 5;
    int barcoC1 = 6;
    for (int i = TAMANHO_NAVIO; i > 0; i--) {
            matriz[barcoL1][barcoC1 + i - 1] = 3;
        }

    //Navio diagonal 1
    int barcoL3 = 0;
    int barcoC3 = 0;
    for (int i = TAMANHO_NAVIO; i > 0; i--) {
        for (int j = TAMANHO_NAVIO; j > 0; j--) {
            matriz[barcoL3 + i - 1][barcoC3 + i - 1] = 3;
        }
    }

    //Navio diagonal 2
    int barcoL4 = 9;
    int barcoC4 = 0;
    for (int i = TAMANHO_NAVIO; i > 0; i--) {
        for (int j = TAMANHO_NAVIO; j > 0; j--) {
            matriz[barcoL4 - i][barcoC4 + i] = 3;
        }
    }

    //Imprimindo a matriz
    for (int i = 0; i < COLUNA; i++) {
        printf("%d |", v++);
        for (int j = 0; j < LINHA; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
