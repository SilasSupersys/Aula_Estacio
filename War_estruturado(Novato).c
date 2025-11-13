/*
    Programa: Cadastro de Territórios - Nivel novato
*/

#include <stdio.h>   
#include <string.h>  

//estrutura do território
struct Territorio {
    char nome[30];   
    char cor[10];    
    int tropas;      
};

int main() {
    //definição do array de territórios
    struct Territorio territorios[5];  
    int i;

    printf("=== === Cadastro de Territórios === ===\n\n");
    // ------------------------------------------------------
    // Entrada de dados dos territórios
    for (i = 0; i < 5; i++) {
        printf("Território %d:\n", i + 1);

        printf("Digite o nome do território: ");
        fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';

        printf("Digite a cor do exército: ");
        fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);

        getchar();// Limpar o buffer do teclado

        printf("\n");
    }

    //exibição dos dados cadastrados
    printf("=== === Territórios Cadastrados === ===\n\n");

    for (i = 0; i < 5; i++) {
        printf("Território %d\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exército: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
        printf("-----------------------------\n");
    }

    printf("\nCadastro concluído com sucesso!\n");

    return 0;
}
