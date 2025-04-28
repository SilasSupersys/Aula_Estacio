#include <stdio.h>

void moverTorre(int casas)
{
    if(casas > 0){
        moverTorre(casas -1);
        printf("Direita %d \n",casas);
    }
}
void moverBispo(int casas)
{
    if(casas > 0){
        moverBispo(casas -1);
        printf("Cima < Direita %d \n",casas);
    }
}
void moverRainha(int casas)
{
    if(casas > 0){
        moverRainha(casas -1);
        printf("Esquerda %d \n",casas);
    }
}
void moverCavalo(int casas)
{
    if(casas > 0){
        moverCavalo(casas -1);
        printf("Cima %d \n",casas);   
        if(casas==2){
            printf("Direita %d \n",casas-1);
        }
             
    }
}
int main() {
    int torre = 1,bispo = 1;
    //move a torre 5 casas para a direita
    /*while(torre <= 5){    
         printf("Direita %d \n",torre);
         torre ++;
    }*/
   moverTorre(5);

    //move o bispo 5 casas para cima e direita
    /*do{
        printf("Cima < Direita %d \n",bispo);
        bispo ++;
    }while(bispo <=5);*/
    moverBispo(5);

    //move a rainha 8 casas para a esquerda
    /*for(int i = 1;i<=8;i++){
        printf("Esquerda %d \n",i);

    }*/
   moverRainha(8);

   /*//move o cavalo para cima e dirreita
   for(int i = 1;i<=2;i++){
    printf("Cima 2\n");
    if(i==2){
        printf("Direita 1");
    }
   }*/
   moverCavalo(2);
}
