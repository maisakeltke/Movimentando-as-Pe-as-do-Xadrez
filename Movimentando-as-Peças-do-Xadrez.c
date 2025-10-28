#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 8

// Função para inicializar o tabuleiro
void inicializarTabuleiro(char tabuleiro[SIZE][SIZE]) {
    char inicial[8] = {'R','N','B','Q','K','B','N','R'}; // Peças da 1ª linha
    for(int i=0; i<SIZE; i++) {
        tabuleiro[0][i] = inicial[i];   // Peças pretas
        tabuleiro[1][i] = 'P';          // Peões pretos
        tabuleiro[6][i] = 'p';          // Peões brancos
        tabuleiro[7][i] = tolower(inicial[i]); // Peças brancas
    }
    for(int i=2; i<6; i++)
        for(int j=0; j<SIZE; j++)
            tabuleiro[i][j] = '.';
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(char tabuleiro[SIZE][SIZE]) {
    printf("\n  a b c d e f g h\n");
    for(int i=0; i<SIZE; i++) {
        printf("%d ", 8-i);
        for(int j=0; j<SIZE; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("%d\n", 8-i);
    }
    printf("  a b c d e f g h\n");
}

// Função para mover uma peça
void moverPeca(char tabuleiro[SIZE][SIZE], int x1, int y1, int x2, int y2) {
    tabuleiro[x2][y2] = tabuleiro[x1][y1];
    tabuleiro[x1][y1] = '.';
}

int main() {
    char tabuleiro[SIZE][SIZE];
    inicializarTabuleiro(tabuleiro);

    char origemCol, destinoCol;
    int origemLin, destinoLin;

    while(1) {
        imprimirTabuleiro(tabuleiro);

        printf("\nDigite a posição da peça que deseja mover (ex: e2): ");
        scanf(" %c%d", &origemCol, &origemLin);

        printf("Digite a posição para mover a peça (ex: e4): ");
        scanf(" %c%d", &destinoCol, &destinoLin);

        int x1 = 8 - origemLin;
        int y1 = origemCol - 'a';
        int x2 = 8 - destinoLin;
        int y2 = destinoCol - 'a';

        moverPeca(tabuleiro, x1, y1, x2, y2);
    }

    return 0;
}
