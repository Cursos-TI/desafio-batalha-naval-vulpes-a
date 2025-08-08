#include <stdio.h>

#define LINHA 10      // Número de linhas do tabuleiro
#define COLUNA 10     // Número de colunas do tabuleiro
#define TAMANHO_NAVIO 3
#define AGUA 0        // Representação da água
#define NAVIO 3       // Representação do navio
#define HABILIDADE 5  // Representação da área de habilidade
#define ABS(x) ((x) < 0 ? -(x) : (x)) // Cálculo de valor absoluto sem bibliotecas extras

// Exibe o tabuleiro no console
void imprimirTabuleiro(int matriz[LINHA][COLUNA]) {
    char letras[LINHA] = {'A','B','C','D','E','F','G','H','I','J'};
    printf("   ");
    for (int j = 0; j < COLUNA; j++) printf("%c ", letras[j]);
    printf("\n  +");
    for (int j = 0; j < COLUNA; j++) printf("--");
    printf("\n");
    for (int i = 0; i < LINHA; i++) {
        printf("%2d|", i);
        for (int j = 0; j < COLUNA; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Gera matriz em forma de cone
void gerarCone(int tamanho, int matriz[tamanho][tamanho]) {
    int centro = tamanho / 2;
    for (int i = 0; i < tamanho; i++)
        for (int j = 0; j < tamanho; j++)
            matriz[i][j] = (j >= centro - i && j <= centro + i && i <= centro) ? 1 : 0;
}

// Gera matriz em forma de cruz
void gerarCruz(int tamanho, int matriz[tamanho][tamanho]) {
    int centro = tamanho / 2;
    for (int i = 0; i < tamanho; i++)
        for (int j = 0; j < tamanho; j++)
            matriz[i][j] = (i == centro || j == centro) ? 1 : 0;
}

// Gera matriz em forma de octaedro (losango)
void gerarOctaedro(int tamanho, int matriz[tamanho][tamanho]) {
    int centro = tamanho / 2;
    for (int i = 0; i < tamanho; i++)
        for (int j = 0; j < tamanho; j++)
            matriz[i][j] = (ABS(i - centro) + ABS(j - centro) <= centro) ? 1 : 0;
}

// Aplica habilidade no tabuleiro
void aplicarHabilidade(int tab[LINHA][COLUNA], int habTamanho, int hab[habTamanho][habTamanho], int origemL, int origemC) {
    int centro = habTamanho / 2;
    for (int i = 0; i < habTamanho; i++)
        for (int j = 0; j < habTamanho; j++)
            if (hab[i][j] == 1) { // Apenas nas áreas marcadas como 1
                int tabL = origemL + (i - centro);
                int tabC = origemC + (j - centro);
                // Verifica limites do tabuleiro
                if (tabL >= 0 && tabL < LINHA && tabC >= 0 && tabC < COLUNA)
                    if (tab[tabL][tabC] == AGUA) // Não sobrescreve navio
                        tab[tabL][tabC] = HABILIDADE;
            }
}

int main() {
    int tabuleiro[LINHA][COLUNA] = {0};

    // Posiciona navios fixos
    for (int i = 0; i < TAMANHO_NAVIO; i++) tabuleiro[7 + i][3] = NAVIO;
    for (int i = 0; i < TAMANHO_NAVIO; i++) tabuleiro[5][6 + i] = NAVIO;
    for (int i = 0; i < TAMANHO_NAVIO; i++) tabuleiro[0 + i][0 + i] = NAVIO;
    for (int i = 0; i < TAMANHO_NAVIO; i++) tabuleiro[9 - i][0 + i] = NAVIO;

    // Cria matrizes das habilidades
    int cone[5][5], cruz[5][5], octaedro[5][5];
    gerarCone(5, cone);
    gerarCruz(5, cruz);
    gerarOctaedro(5, octaedro);

    // Aplica habilidades no tabuleiro em pontos fixos
    aplicarHabilidade(tabuleiro, 5, cone, 2, 2);
    aplicarHabilidade(tabuleiro, 5, cruz, 5, 5);
    aplicarHabilidade(tabuleiro, 5, octaedro, 8, 8);

    // Mostra tabuleiro final
    imprimirTabuleiro(tabuleiro);
    return 0;
}
