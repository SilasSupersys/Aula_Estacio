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

//estrutura do jogador
typedef struct {
    char nome[30];
    char cor[10];
    char* missao;
} Jogador;

void cadastrarTerritorios(Territorio* mapa, int n,int continentesDisponiveis, char continentes[5][40]);
void exibirMapa(Territorio* mapa, int n);
void atacar(Territorio* atacante, Territorio* defensor);
void atribuirMissao(char* destino, char* missoes[], int totalMissoes);
int verificarMissao(char* missao, Territorio* mapa, int n, char* corJogador);
void liberarMemoria(Jogador* jogadores, int total);

//cadastro dos territórios
void cadastrarTerritorios(Territorio* mapa, int n,int continentesDisponiveis, char continentes[5][40]) {    
    int escolha = 0;
    for (int i = 0; i < n; i++) {
        printf("\n[*] [*] [*] [*] JOGADOR  %d [*] [*] [*] [*] \n\n", i + 1);
        
        printf("[*] [*] [*] [*] CONTINENTES DISPONIVEIS [*] [*] [*] [*] :\n");    
        for (int j = 0; j < continentesDisponiveis; j++) {
            printf("%d - %s  ", j, continentes[j]);
        }
        printf("\n Escolha um Continente: ");
        scanf("%d", &escolha);
        getchar(); 
        strcpy(mapa[i].nome, continentes[escolha]);
                
        printf("Cor do exército: ");
        fgets(mapa[i].cor, sizeof(mapa[i].cor), stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';

        printf("Quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);
        getchar(); // consome '\n'
                
        // Remove o continente deslocando os próximos
        for (int k = escolha; k < continentesDisponiveis - 1; k++) {
            strcpy(continentes[k], continentes[k + 1]);
        }
        continentesDisponiveis --;
    }

   //exibição dos dados cadastrados
    printf("[*] [*] [*] [*] Jogadores Cadastrados [*] [*] [*] [*] \n\n");

    for (int i = 0; i < n; i++) {
        printf("%d > %s - [Exercito: %s | Tropas: %d ] \n", i + 1,mapa[i].nome, mapa[i].cor, mapa[i].tropas);    
    }

    printf("\n\nJogadores Definidos, vamos começar!\n");

}

//exibição do mapa
void exibirMapa(Territorio* mapa, int n) {
    printf("\n[*] [*] [*] [*]  SITUAÇÃO DO MAPA [*] [*] [*] [*] \n");
    for (int i = 0; i < n; i++) {
        printf("%d. %-15s | Cor: %-10s | Tropas: %d\n",
               i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

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

//atribuição de missões
void atribuirMissao(char* destino, char* missoes[], int totalMissoes) {
    int indice = rand() % totalMissoes;
    strcpy(destino, missoes[indice]);
}

//verificação de missão
int verificarMissao(char* missao, Territorio* mapa, int n, char* corJogador) {
    
    if (strcmp(missao, "Conquistar 3 territorios") == 0) {
        int conquistas = 0;
        for (int i = 0; i < n; i++) {
            if (strcmp(mapa[i].cor, corJogador) == 0)
                conquistas++;
        }
        if (conquistas >= 3)
            return 1;
    }

    if (strcmp(missao, "Eliminar todas as tropas vermelhas") == 0) {
        for (int i = 0; i < n; i++) {
            if (strcmp(mapa[i].cor, "Vermelho") == 0 && mapa[i].tropas > 0)
                return 0;
        }
        return 1;
    }
    
     if (strcmp(missao, "Controlar todos os territorios azuis") == 0) {
        int conquistas = 0;
        for (int i = 0; i < n; i++) {
            if (strcmp(mapa[i].cor, corJogador) == 0)
                conquistas++;
        }
        if (conquistas = 5)
            return 1;
            
    }

    if (strcmp(missao, "Manter pelo menos 10 tropas ativas") == 0) {
        int totalTropas = 0;
        for (int i = 0; i < n; i++) {
            if (strcmp(mapa[i].cor, corJogador) == 0)
                totalTropas += mapa[i].tropas;
        }
        if (totalTropas >= 10)
            return 1;
    }
    if (strcmp(missao, "Conquistar dois territorios seguidos") == 0) {
        int conquistasSeguidas = 0;
        for (int i = 0; i < n - 1; i++) {
            if (strcmp(mapa[i].cor, corJogador) == 0 && strcmp(mapa[i + 1].cor, corJogador) == 0) {
                conquistasSeguidas++;
                if (conquistasSeguidas >= 2)
                    return 1;
            } else {
                conquistasSeguidas = 0;
            }
        }
    }
    return 0;
}

//liberação de memória
void liberarMemoria(Jogador* jogadores, int total) {
    for (int i = 0; i < total; i++) {
        free(jogadores[i].missao);
    }
}

int main() {
    srand(time(NULL)); 
    int n, i,continentesDisponiveis = 5,nJogadores;

    char continentes[5][40] = {
        "America",        
        "Europa",        
        "Asia",
        "Africa",
        "Oceania"
    };
    
    

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

    //cadastro dos territórios
    cadastrarTerritorios(territorios, n,continentesDisponiveis, continentes);

    Jogador* jogadores = (Jogador*) calloc(nJogadores, sizeof(Jogador));
    if (!jogadores) {
        printf("Erro ao alocar memória, nao jogue em uma calculadora!\n");
        free(territorios);
        return 1;
    }

    //vetor de missões
     char* missoes[] = {
        "Conquistar 3 territorios",
        "Eliminar todas as tropas vermelhas",
        "Controlar todos os territorios azuis",
        "Manter pelo menos 10 tropas ativas",
        "Conquistar dois territorios seguidos"
    };
    int totalMissoes = 5;

    //cadastro dos jogadores e atribuição das missões
    for (int i = 0; i < nJogadores; i++) {
        printf("\n[*] [*] [*] [*] JOGADOR [*] [*] [*] [*]  %d\n", i + 1);
        printf("Nome: ");
        fgets(jogadores[i].nome, sizeof(jogadores[i].nome), stdin);
        jogadores[i].nome[strcspn(jogadores[i].nome, "\n")] = '\0';

        printf("Cor do exército: ");
        fgets(jogadores[i].cor, sizeof(jogadores[i].cor), stdin);
        jogadores[i].cor[strcspn(jogadores[i].cor, "\n")] = '\0';

        jogadores[i].missao = (char*) malloc(100 * sizeof(char));
        atribuirMissao(jogadores[i].missao, missoes, totalMissoes);

        printf("Missão de %s: %s\n", jogadores[i].nome, jogadores[i].missao);
    }

    //ataque
    char continuar;
    do {
        exibirMapa(territorios, 5);

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

         // Verificar se algum jogador cumpriu sua missão
        for (int i = 0; i < nJogadores; i++) {
            if (verificarMissao(jogadores[i].missao, territorios, 5, jogadores[i].cor)) {
                printf("\n %s VENCEU! >>> MISSÃO COMPLETA <<<<: %s\n", jogadores[i].nome, jogadores[i].missao);
                liberarMemoria(jogadores, nJogadores);
                free(territorios);
                free(jogadores);
                return 0;
            }
        }

        printf("Deseja realizar outro ataque? (s/n): ");
        scanf(" %c", &continuar);
        getchar();
    } while (continuar == 's' || continuar == 'S');

}
