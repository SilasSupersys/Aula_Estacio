#include <stdio.h>

#define LINHAS_TABULEIRO 10
#define COLUNAS_TABULEIRO 10
#define LINHAS_ATAQUE 3
#define COLUNAS_ATAQUE 5
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
int validaAtaque(int mtz[LINHAS_TABULEIRO][COLUNAS_TABULEIRO], int lPosicao,int cPosicao)
{
    int retorno = 0;
    for (int i = 0; i < 3; i++) {
        int l = lPosicao + i;
        for(int j = 0;j<5;j++){
            int c = cPosicao +j;
            if (mtz[l][c] != 0) {    
                retorno = 1;                
            }
        }
    }  
    return retorno;   
}
int main() {
    //matriz geral
    int matriz[LINHAS_TABULEIRO][COLUNAS_TABULEIRO];
    
    //matriz de habilidade
    int cone[LINHAS_ATAQUE][COLUNAS_ATAQUE];
    int cruz[LINHAS_ATAQUE][COLUNAS_ATAQUE];
    int octaedro[LINHAS_ATAQUE][COLUNAS_ATAQUE];

    //define variaveis de controle
    int linhaPosicao,colunaPosicao;
    int direcao;
    const int tamanhoBarco = 3;
    int QtdBarcos = 4;
    //variaves para o ataque
    int tipoAtaque,PosicaoLinha,PosicaoColuna;
    //inicia a matriz
    printf(">>> TABULEIRO BATALHA NAVAL <<<\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matriz[i][j] = 0;
        }
    }
    //inicia matriz de ataque
    //cone
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            cone[i][j] = 0;
            if( (j == 2) || (i == 1 && j == 1) || (i == 1 && j == 3) || i == 2){
                cone[i][j] = 5;                 
            }
        }
    }
    //cruz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            cruz[i][j] = 0;
            if( (j == 2) || i == 1){
                cruz[i][j] = 5;                 
            }
        }
    }
    //octaedro
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            octaedro[i][j] = 0;
            if(j == 2 || (i == 1 && j == 1) || (i == 1 && j == 3)){                                
                octaedro[i][j] = 5;                            
            }
        }
    }
    for(int m = 1;m <= QtdBarcos;m++){
        
        menu:
        if(m == 1 || m==2){
            printf("Escolha a direcao do barco %d: 1 = direita -  2 = esquerda: ",m);
            scanf("%d", &direcao);
            if(direcao < 1 || direcao > 2){
                printf("Opcao de direcao invalida, tente novamente!\n");
                goto menu;
            }
        }
        printf("Escolha a posicao inicial da linha do barco [%d] de (0 a 9): ",m);
        scanf("%d", &linhaPosicao);
        printf("Escolha a posicao inicial da coluna do barco [%d] de (0 a 9): ",m);
        scanf("%d", &colunaPosicao);
        
        //valida se e permitido o valor da linha ou coluna
        if (validaPosicao(tamanhoBarco,linhaPosicao,direcao,colunaPosicao) == 0)
        {
            goto menu;
        }            
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
    printf("\n >>> ESCOLHA O TIPO DE ATAQUE E APOS ISSO A DIRECAO <<<\n\n");
    printf("Escolha o tipo de ataque: [%d] (1 - Cone | 2 - Cruz | 3 - Octaedro | 0 - Cancelar): ",tipoAtaque);
    scanf("%d", &tipoAtaque);
    if(tipoAtaque != 1 && tipoAtaque != 2 && tipoAtaque != 3 && tipoAtaque != 0){
        printf("Tipo de ataque invalido!");
        goto ataque;
    }else {
        if(tipoAtaque != 0){
            printf("Escolha a coordenada (linha) do ataque [%d] de (0 a 9): ",PosicaoLinha);
            scanf("%d", &PosicaoLinha);
            printf("Escolha a coordenada (coluna) do ataque [%d] de (0 a 9): ",PosicaoColuna);
            scanf("%d", &PosicaoColuna);
            direcao = 0;
            //valida se e permitido o valor da linha ou coluna
            if (validaPosicao(tamanhoBarco,PosicaoLinha,direcao,PosicaoColuna) == 0)
            {
                goto ataque;
            }
            for (int i = 0; i < LINHAS_ATAQUE; i++) {
                for (int j = 0; j < COLUNAS_ATAQUE; j++) {
                    if(tipoAtaque == 1){
                        if (validaAtaque(matriz,PosicaoLinha,PosicaoColuna) == 1){
                            if ((PosicaoLinha + i) < LINHAS_TABULEIRO && (PosicaoColuna + j) < COLUNAS_TABULEIRO) {
                                matriz[PosicaoLinha + i][PosicaoColuna + j] = cone[i][j];
                            }
                        }else{
                            printf("\nErrooooooooooooooooooooh!\n"); 
                            goto ataque;
                        }
                    }
                    if(tipoAtaque == 2){
                        if (validaAtaque(matriz,PosicaoLinha,PosicaoColuna) == 1){
                            if ((PosicaoLinha + i) < LINHAS_TABULEIRO && (PosicaoColuna + j) < COLUNAS_TABULEIRO) {
                                matriz[PosicaoLinha + i][PosicaoColuna + j] = cruz[i][j];
                            }
                        }else{
                            printf("\nErrooooooooooooooooooooh!\n"); 
                            goto ataque;
                        }
                    }
                    if(tipoAtaque == 3){
                    if (validaAtaque(matriz,PosicaoLinha,PosicaoColuna) == 1){
                        if ((PosicaoLinha + i) < LINHAS_TABULEIRO && (PosicaoColuna + j) < COLUNAS_TABULEIRO) {
                            matriz[PosicaoLinha + i][PosicaoColuna + j] = octaedro[i][j];
                        }
                    }else{
                            printf("\nErrooooooooooooooooooooh!\n"); 
                            goto ataque;
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
            goto ataque;
        }
    }
    return 0;
}