#include <stdio.h>

int main() {
    int torre = 1,bispo = 1;
    //move a torre 5 casas para a direita
    while(torre <= 5){    
         printf("Direita %d \n",torre);
         torre ++;
    }

    //move o bispo 5 casas para cima e direita
    do{
        printf("Cima < Direita %d \n",bispo);
        bispo ++;
    }while(bispo <=5);

    //move a rainha 8 casas para a esquerda
    for(int i = 1;i<=8;i++){
        printf("Esquerda %d \n",i);

    }
}