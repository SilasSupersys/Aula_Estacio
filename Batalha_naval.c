#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

int validaPosicao(int tamanho,int lPosicao,int diagonal,int cPosicao)
{
    for (int i = 0; i < tamanho; i++) {
        int l = lPosicao + i;
        int c = (diagonal == 1) ? cPosicao + i : cPosicao - i;

        if (l < 0 || l >= 10 || c < 0 || c >= 10) {
            printf("Coordenada ou posicao invalida!\n");      
            return 0;   
        }else{
            return 1;
        }
    } 
    
}

int main() {
    //matriz geral
    int matriz[LINHAS][COLUNAS];
    
    //matriz de habilidade
    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];


    //define variaveis de controle
    int linhaPosicao,colunaPosicao;
    int direcao;
    const int tamanhoBarco = 3;
    int QtdBarcos = 4;
    //variaves para o ataque
    int tipoAtaque,PosicaoAtaque;
    //inicia a matriz
    printf(">>> TABULEIRO BATALHA NAVAL <<<\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matriz[i][j] = 0;
        }
    }
    for(int m = 1;m <= QtdBarcos;m++){
        
        menu:
        if(m == 1 || m==2){
            printf("Escolha a direcao do barco %d: 1 = direita -  2 = esquerda: ",m);
            scanf("%d", &direcao);
            if(direcao < 1 || direcao > 2){
                printf("Opcao de direcao invalida, tente novamente!");
                goto menu;
            }
        }
        printf("Escolha a posicao inicial da linha do barco [%d] de (0 a 9): ",m);
        scanf("%d", &linhaPosicao);
        printf("Escolha a posicao inicial da coluna do barco [%d] de (0 a 9): ",m);
        scanf("%d", &colunaPosicao);
        
        //valida se e permitido o valor da linha ou coluna
        if (valida(tamanhoBarco,linhaPosicao,direcao,colunaPosicao))
        {
            goto menu;
        }
        /*
        for (int i = 0; i < tamanhoBarco; i++) {
            int l = linhaPosicao + i;
            int c = (direcao == 1) ? colunaPosicao + i : colunaPosicao - i;
    
            if (l < 0 || l >= 10 || c < 0 || c >= 10) {
                printf("Coordenada ou posicao invalida!\n");                
            }
        }   */     
        if(m == 1){
            //adiciona o barco 1
            for (int i = 0; i < tamanhoBarco; i++) {
                int l = linhaPosicao + i;
                int c = (direcao == 1) ? colunaPosicao + i : colunaPosicao - i;                
                matriz[l][c] = 1;
            }            
        }
        if(m == 2){
            //adiciona barco 2
            for (int i = 0; i < tamanhoBarco; i++) {
                int l = linhaPosicao + i;
                int c = (direcao == 1) ? colunaPosicao + i : colunaPosicao - i;
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        if(matriz[i][j] == 3){
                            if(l == i && c == j){
                            printf("Coordenada ja possui um barco posicionado, escolha novas!\n");
                            goto menu;
                            }
                        }                        
                    }
                }
                matriz[l][c] = 2;
            }   
        }
        if(m == 3){
            //adiciona barco 3
            for (int i = 0; i < tamanhoBarco; i++) {         
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        if(matriz[i][j] == 3){
                            if(linhaPosicao == i && colunaPosicao +i == j){
                            printf("Coordenada ja possui um barco posicionado, escolha novas!\n");
                            goto menu;
                            }
                        }                        
                    }
                }       
                matriz[linhaPosicao ][colunaPosicao +i] = 3;
            }   
        }
        if(m == 4){
            //adiciona barco 4
            for (int i = 0; i < tamanhoBarco; i++) {         
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        if(matriz[i][j] == 3){
                            if(linhaPosicao +i == i && colunaPosicao  == j){
                            printf("Coordenada ja possui um barco posicionado, escolha novas!\n");
                            goto menu;
                            }
                        }                        
                    }
                }         
                matriz[linhaPosicao +i][colunaPosicao ] = 4;
            }   
        }
    }
    //exibe a matriz
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    //chama menus de ataque
    ataque:
    printf(">>> ESCOLHA O TIPO DE ATAQUE E APOS ISSO A DIRECAO <<<\n\n");
    printf("Escolha o tipo de ataque: [%d] (1 - Cone | 2 - Cruz | 3 - Octaedro | 0 - Cancelar): ",tipoAtaque);
    scanf("%d", &tipoAtaque);
    if(tipoAtaque != 1 || tipoAtaque != 2 || tipoAtaque != 3 || tipoAtaque != 0){
        printf("Tipo de ataque invalido!");
        goto ataque;
    }

    printf("Escolha a coordenada do ataque [%d] de (0 a 9): ",PosicaoAtaque);
    scanf("%d", &PosicaoAtaque);

    return 0;
}