/*
    Programa: Cadastro de Territórios - Nivel novato
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//estrutura do território
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

//funcao para simular um ataque entre dois territórios
void atacar(Territorio* atacante, Territorio* defensor) {
    //Verifica se o atacante ou defensor tem tropas suficientes

     if (atacante->tropas == 0 || defensor->tropas == 0) {
        printf("Território %s não possui tropas.\n",(atacante->tropas == 0) ? "Atacante" : "Defensor");

        if(defensor->tropas <= 0) {
            printf("🏴‍☠️ O território %s foi conquistado por %s!\n", defensor->nome, atacante->nome);
            strcpy(defensor->cor, atacante->cor);
            sprintf(defensor->nome, "%s (conquistado por: %s)", defensor->nome,atacante->nome);
            defensor->tropas = 1;
            atacante->tropas -= 1;
        }
        return;
     }

    if (atacante->tropas < 2) {
        printf("O território atacante (%s) não tem tropas suficientes para atacar!\n", atacante->nome);
        return;
    }

    printf("\nAtaque iniciado: %s (atacante) vs %s (defensor)\n", atacante->nome, defensor->nome);

    //define as variaveis dos dados
     int dadoAtacante = rand() % 5 + 1; 
     int dadoDefensor = rand() % 6 + 1;
    // Simulação dos dados, com vantagem para o território com mais tropas
    if(atacante->tropas < defensor->tropas) {        
        int dadoAtacante = rand() % 5 + 1; 
        int dadoDefensor = rand() % 6 + 1;   
    }else
    {
        int dadoAtacante = rand() % 6 + 1; 
        int dadoDefensor = rand() % 5 + 1;
    }

    printf("Dado do atacante: [%d] <==> Dado do defensor: %d \n", dadoAtacante, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("O atacante venceu esta rodada!\n");
        defensor->tropas -= 1;
        atacante->tropas -= 1;
        
        printf("\n--- RESULTADO DA BATALHA ---\n");
        printf("Territorio Atacante: %s -> Tropas: %d | Cor: %s\n", atacante->nome, atacante->tropas, atacante->cor);
        printf("Territorio Defensor: %s -> Tropas: %d | Cor: %s\n", defensor->nome, defensor->tropas, defensor->cor);
        printf("-----------------------------\n\n");
        
        // se o defensor nao tem mais tropas, perde o território
        if (defensor->tropas <= 0) {
            printf(" O território %s foi conquistado por %s!\n", defensor->nome, atacante->nome);
            strcpy(defensor->cor, atacante->cor);
            sprintf(defensor->nome, "%s (conquistado por: %s)", defensor->nome,atacante->nome);
            defensor->tropas = 1;
            atacante->tropas -= 1;
        }
    } else {
        printf("O defensor resistiu ao ataque!\n");
        atacante->tropas -= 1;
    }    
}

int main() {
    srand(time(NULL)); // inicializa o gerador de números aleatórios
    char continentes[5][30] = {
        "America",        
        "Europa",        
        "Asia",
        "Africa",
        "Oceania"
    };
    int n, i,continentesDisponiveis = 5;

    printf("[*] [*] [*] [*] BEM VINDOES AO WAR CONTINENTES [*] [*] [*] [*] \n");
    printf("[Jogadores escolherão um dos cinco continentes do game:] \n");
    printf("[1 - America] \n");
    printf("[2 - Europa] \n");
    printf("[3 - Asia] \n");
    printf("[4 - Africa] \n");
    printf("[5 - Oceania] \n\n");

    printf("[*] [*] [*] [*] ENTRADA DE JOGADORES [*] [*] [*] [*] \n");
    
    printf("Quantos jogadores serão cadastrados? Maximo de 5 jogadores: ");
    
    cadastro:
    scanf("%d", &n);
    if(n > 5 || n < 1) {
        printf("Número inválido de jogadores! O jogo suporta de 1 a 5 jogadores.\n");
        goto cadastro;
    }    
    getchar(); 

    //alocando a memória para os territórios
    Territorio* territorios = (Territorio*) calloc(n, sizeof(Territorio));
    if (territorios == NULL) {
        printf("Erro ao alocar memória, nao jogue em uma calculadora!\n");
        return 1;
    }
    //cadastrando 
   
    int escolha = 0;
    for (i = 0; i < n; i++) {
        printf("\n ====> JOGADOR  %d <==== \n\n", i + 1);
        
        printf("[*] [*] [*] [*] CONTINENTES DISPONIVEIS [*] [*] [*] [*] :\n");    
        for (int i = 0; i < continentesDisponiveis; i++) {
            printf("%d - %s  ", i, continentes[i]);
        }
        printf("\n Escolha um Continente: ");
        scanf("%d", &escolha);
        getchar(); 
        strcpy(territorios[i].nome, continentes[escolha]);
                
        printf("Cor do exército: ");
        fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';

        printf("Quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
        getchar(); // consome '\n'
                
        // Remove o continente deslocando os próximos
        for (int j = escolha; j < continentesDisponiveis - 1; j++) {
            strcpy(continentes[j], continentes[j + 1]);
        }
        continentesDisponiveis --;
    }

   //exibição dos dados cadastrados
    printf("[*] [*] [*] [*] Jogadores Cadastrados [*] [*] [*] [*] \n\n");

    for (i = 0; i < n; i++) {
        printf("%d > %s - [Exercito: %s | Tropas: %d ] \n", i + 1,territorios[i].nome, territorios[i].cor, territorios[i].tropas);    
    }

    printf("\n\nJogadores Definidos, vamos começar!\n");

    //ataque
    char continuar;
    do {
        printf("\n[*] [*] [*] [*] TURNOS DE ATAQUES [*] [*] [*] [*]\n");

        // territórios
        for (i = 0; i < n; i++) {
            printf("%d. %s (Cor: %s, Tropas: %d)\n", i + 1, territorios[i].nome, territorios[i].cor, territorios[i].tropas);
        }

        int getAtacante, getDefensor;
        printf("\n ATACANTE >>>> (1-%d): ", n);
        scanf("%d", &getAtacante);
        printf(" DEFENSOR <<<< (1-%d): ", n);
        scanf("%d", &getDefensor);
        getchar();

        // Validação
        if (getAtacante < 1 || getAtacante > n || getDefensor < 1 || getDefensor > n || getAtacante == getDefensor) {
            printf("ESCOLHA CORRETAMENTE!\n");
        } else {
            atacar(&territorios[getAtacante - 1], &territorios[getDefensor - 1]);
        }

        printf("Deseja realizar outro ataque? (s/n): ");
        scanf(" %c", &continuar);
        getchar();
    } while (continuar == 's' || continuar == 'S');

}
