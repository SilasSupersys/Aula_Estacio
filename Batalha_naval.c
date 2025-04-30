#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

int main() {
    int matriz[LINHAS][COLUNAS];
    const int tamanhoBarco = 3;
    //constroi o barco 1
    int barco1Linha[3] = {4, 5, 6};
    int barco1Coluna[3] = {4, 5, 6};
    //constroi o barco 2
    int barco2Linha = 8;
    int barco2[3] = {3, 4, 5};

    //inicia a matriz
    printf(">>> TABULEIRO BATALHA NAVAL <<<\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matriz[i][j] = 0;
        }
    }
    //adiciona o barco 1
    for (int i = 0; i < tamanhoBarco; i++) {
        matriz[barco1Linha[i]][barco1Coluna[i]] = 3;
    }
    //adiciona barco 2
    for (int i = 0; i < tamanhoBarco; i++) {
        matriz[barco2Linha][barco2[i]] = 3;
    }    
    //exibe a matriz
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}