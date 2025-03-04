#include <stdio.h>

#define TAMANHO 10

void adicionar_habilidade_cone(int tabuleiro[TAMANHO][TAMANHO], int x, int y) {
    if (x >= 2 && y >= 1 && y < TAMANHO - 1) {
        tabuleiro[x][y] = 5;
        tabuleiro[x - 1][y - 1] = 5;
        tabuleiro[x - 1][y] = 5;
        tabuleiro[x - 1][y + 1] = 5;
        tabuleiro[x - 2][y] = 5;
    }
}

void adicionar_habilidade_cruz(int tabuleiro[TAMANHO][TAMANHO], int x, int y) {
    if (x >= 1 && x < TAMANHO - 1 && y >= 1 && y < TAMANHO - 1) {
        tabuleiro[x][y] = 5;
        tabuleiro[x - 1][y] = 5;
        tabuleiro[x + 1][y] = 5;
        tabuleiro[x][y - 1] = 5;
        tabuleiro[x][y + 1] = 5;
    }
}

void adicionar_habilidade_octaedro(int tabuleiro[TAMANHO][TAMANHO], int x, int y) {
    if (x >= 1 && x < TAMANHO - 1 && y >= 1 && y < TAMANHO - 1) {
        tabuleiro[x][y] = 5;
        tabuleiro[x - 1][y] = 5;
        tabuleiro[x + 1][y] = 5;
        tabuleiro[x][y - 1] = 5;
        tabuleiro[x][y + 1] = 5;
        if (x >= 2) tabuleiro[x - 2][y] = 5;
        if (x < TAMANHO - 2) tabuleiro[x + 2][y] = 5;
        if (y >= 2) tabuleiro[x][y - 2] = 5;
        if (y < TAMANHO - 2) tabuleiro[x][y + 2] = 5;
    }
}

int main(){
    char linha[TAMANHO]= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // 1. CRIANDO O TABULEIRO (MATRI Z 10X10)
    int tabuleiro[TAMANHO][TAMANHO];

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
     }


     // Exibindo o tabuleiro
    printf("TABULEIRO BATALHA NAVAL\n");
    printf("  ");
    for (int j = 0; j < 10; j++){
        printf("%c ", linha[j]); //imprime os números das colunas
    }
      printf("\n");

      //Navios na vertical
      for (int i = 1; i < 4; i++){
        tabuleiro[i][1] = 3;
      }

      //Navios na Horinzontal
      for (int j = 4; j < 7; j++){
        tabuleiro[4][j] = 3;
      }

       // Adicionando habilidades
    adicionar_habilidade_cone(tabuleiro, 6, 5);
    adicionar_habilidade_cruz(tabuleiro, 7, 7);
    adicionar_habilidade_octaedro(tabuleiro, 3, 3);



      //linhas numeradas
      for (int i = 0; i < 10; i++){
        printf("%2d ", i + 1); //número da linha
        for (int j = 0; j < 10; j++){
        printf("%d ", tabuleiro[i][j]); // Valor do tabuleiro 
        }
        printf("\n"); //nova linha da matriz
      }
      

    return 0;

}