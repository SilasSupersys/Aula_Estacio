/*
    DESAFIO NIVEL MESTRE FREE FIRE
    ALUNO : SILASMAR JUNIOR DA SILVA
    OBS: EU JA FIZ AS 3 FASES DO PROJETO (NOVATO, AVENTUREIRO E MESTRE DE UMA VEZ POR QUE ESTOU SEM TEMPO DE FAZER CADA UMA SEPARADAMENTE)
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h> 

#define MAX_COMPONENTES 20
#define MAX_NOME 30
#define MAX_TIPO 20

// Estrutura do componente
typedef struct {
    char nome[MAX_NOME];
    char tipo[MAX_TIPO];
    int quantidade;
    int prioridade;
} Componente;

// Algoritmos de ordenação (cada um conta comparações e mede tempo)
void ordenacao(Componente comps[], int n, long *comparacoes, double *tempo,int tipo);

// substituir item na mochila
void combateEGerarDrop(Componente comps[], int *n);
void substituirItemMochila(Componente comps[], int n, Componente novo);
void mostrarComponentes(Componente comps[], int n);
void excluirItemMochila(Componente mochila[], int *qtd);
// Busca binária por nome (precisa ordenar por nome antes)
int buscaBinariaPorNome(Componente comps[], int n, const char chave[], long *comparacoes, double *tempo);

// Função auxiliar para medir e imprimir resultados de uma ordenação
void aplicarEMedir(void (*algoritmo)(Componente*, int, long*, double*), Componente comps[], int n, const char *titulo);

// Funções auxiliares
void limparBuffer(void);

// Funcao: Buscar peças na ilha
void buscarPecasIlha(Componente comps[], int *n) {
    srand(time(NULL));
    int evento = rand() % 2; // 0 = BOX, 1 = inimigo,
    char cadastrar;
    printf("\n[*] [*] [*] [*] [*] [*] [*] [*] [*] [*] [*] [*] \n");
    printf("\n[*] [*] [*] BUSCANDO PEÇAS NA ILHA  [*] [*] [*] \n");
    printf("\n[*] [*] [*] [*] [*] [*] [*] [*] [*] [*] [*] [*] \n");

    if (evento == 0) {
        // BOX encontrada
        printf("Você encontrou uma BOX de suprimentos!\n");
        // Vetor base de 10 componentes possíveis para drop
        Componente baseDrops[10] = {
        {"MICROCHIP", "ELETRONICO", 2},
        {"SUPORTE DE TITANIO", "SUPORTE", 4},
        {"ITEM DE CURA", "CURA", 1},
        {"MODULO DE ENERGIA", "ENERGIA", 3},
        {"PAINEL OPTICO", "SENSOR", 5},
        {"NUCLEO MAGNETICO", "CONTROLE", 2},
        {"CARCAÇA REFORÇADA", "ESTRUTURA", 6},
        {"ESCUDO DE ENERGIA", "DEFESA", 4},
        {"CHIP RESERVA", "CONTROLE", 3},
        {"ANEL ESTABILIZADOR", "SUPORTE", 2}
    };

    int idx = rand() % 10;
    if (*n < MAX_COMPONENTES) {
        comps[*n] = baseDrops[idx];
        (*n)++;
        printf("==========================================\n");
        printf("=========ITEM ENCONTRADO NA BOX!==========\n");
        printf("==========================================\n");
        printf("%s | %s | %d (adicionado à mochila)\n", baseDrops[idx].nome, baseDrops[idx].tipo, baseDrops[idx].prioridade);
    } else {
        printf("Mochila cheia! Não foi possível adicionar o item.\n");
        printf("Deseja substituir um item? (s/n): ");
        scanf(" %c", &cadastrar);
        if (cadastrar == 's' || cadastrar == 'S') {
            comps[*n] = baseDrops[idx];
            substituirItemMochila(comps, *n, baseDrops[idx]);
        }
        getchar();
    }

} else {
    // inimigo encontrado
    printf("==========================================\n");
    printf("============INIMIGO ENCONTRADO============!\n");
    printf("==========================================\n");
    combateEGerarDrop(comps, n);
    }
}
int main() {
    Componente comps[MAX_COMPONENTES]; // vetor original
    Componente trabalho[MAX_COMPONENTES]; // vetor de trabalho
    int n = 0;
    int opcao;
    printf("==========================================\n"); 
    printf("===== BEM VINDO A ILHA =====\n\n");
    printf("Voce caiu em uma ilha que esta preste a receber um ataque nuclear.\n");
    printf("Seu objetivo e reperar a torre de comunicação e enviar um pedido de socorro!\n");
    printf("Mas cuidado! Seu inimigo tambem esta tentando escapar, sendo assim, voce deve destruilo e pegar suas peças para efetuar o reparo.\n");
    printf("Guarde na mochila os componentes que voce conseguiu recuperar do inimigo, são necessário 4 componentes para concertar a torre:\n");
    printf("[1] MICROCHIP  [2] MODULO DE ENERGIA  [3] PAINEL OPTICO  [4] ANEL ESTABILIZADOR\n");
    printf("Quando estive em posse dos componentes, execute a missao de reparo.");
    printf("\nBoa sorte!\n");
    printf("==========================================\n");

    while(1) {
        printf("\nMenu:\n");
        printf("1 - BUSCAR POR PEÇAS NA ILHA\n");
        printf("2 - EXIBIR COMPONENTES ATUAIS\n");        
        printf("3 - ORGANIZAR A MOCHILA (NOME, TIPO, PRIORIDADE)\n");
        printf("4 - BUSCA ITEM NA MOCHILA (POR NOME)\n");
        printf("5 - EXECUTAR A MISSAO\n");
        printf("6 - ECLUIR ITEM DA MOCHILA\n");
        printf("0 - Sair\n");
        printf("==========================================\n");
        printf("============ESCOLHA UMA OPÇÃO=============\n");
        printf("==========================================\n");
        if (scanf("%d", &opcao) < 0 || opcao > 6) {
            limparBuffer();
            printf("Entrada invalida. Tente novamente.\n");
            continue;
        }
        limparBuffer();

        if (opcao == 0) break;

        if (opcao == 1) {
            buscarPecasIlha(comps, &n);

        } else if (opcao == 2) {
            mostrarComponentes(comps, n);
        } else if (opcao == 3) {
            int tipoOrdenacao;
            printf("Escolha o tipo de ordenacao:\n");
            printf("1 - Nome\n");
            printf("2 - Tipo\n");
            printf("3 - Prioridade\n");
            printf("Opcao: ");
            if (scanf("%d", &tipoOrdenacao) < 0 || tipoOrdenacao < 1 || tipoOrdenacao > 3) {
                limparBuffer();
                printf("Entrada invalida. Tente novamente.\n");
                continue;
            }
            limparBuffer();
            long comparacoes = 0;
            double tempo = 0.0;
            ordenacao(comps, n, &comparacoes, &tempo, tipoOrdenacao);
            printf("Ordenacao concluida em %.6f segundos com %ld comparacoes.\n", tempo, comparacoes);
        } else if (opcao == 4) {
            char nomeBusca[MAX_NOME];
            printf("Digite o nome do componente para busca: ");
            fgets(nomeBusca, MAX_NOME, stdin);
            nomeBusca[strcspn(nomeBusca, "\n")] = '\0';
            for (int i = 0; nomeBusca[i] != '\0'; i++)
                nomeBusca[i] = toupper(nomeBusca[i]);

            long comparacoes = 0;
            double tempo = 0.0;
            // Certifique-se de que o vetor esteja ordenado por nome antes da busca binária
            ordenacao(comps, n, &comparacoes, &tempo, 1); // Ordena por nome
            int indice = buscaBinariaPorNome(comps, n, nomeBusca, &comparacoes, &tempo);
            if (indice != -1) {
                printf("Componente encontrado: %s | %s | %d\n", comps[indice].nome, comps[indice].tipo, comps[indice].prioridade);
            } else {
                printf("Componente nao encontrado na mochila.\n");
            }
            printf("Busca concluida em %.6f segundos com %ld comparacoes.\n", tempo, comparacoes);
        } else if (opcao == 5) {
            // Verificar se o jogador tem os 4 componentes necessários
            int temMicrochip = 0, temModuloEnergia = 0, temPainelOptico = 0, temAnelEstabilizador = 0;
            for (int i = 0; i < n; i++) {
                if (strcmp(comps[i].nome, "MICROCHIP") == 0) temMicrochip = 1;
                else if (strcmp(comps[i].nome, "MODULO DE ENERGIA") == 0) temModuloEnergia = 1;
                else if (strcmp(comps[i].nome, "PAINEL OPTICO") == 0) temPainelOptico = 1;
                else if (strcmp(comps[i].nome, "ANEL ESTABILIZADOR") == 0) temAnelEstabilizador = 1;
            }
            if (temMicrochip && temModuloEnergia && temPainelOptico && temAnelEstabilizador) {
                printf("Parabens! Voce reuniu todos os componentes necessarios e reparou a torre de comunicacao!\n");
                printf("O resgate esta a caminho. Voce venceu!\n");
                break;
            } else {
                printf("Voce ainda nao possui todos os componentes necessarios para reparar a torre.\n");
                printf("Componentes faltando:\n");
                if (!temMicrochip) printf("- MICROCHIP\n");
                if (!temModuloEnergia) printf("- MODULO DE ENERGIA\n");
                if (!temPainelOptico) printf("- PAINEL OPTICO\n");
                if (!temAnelEstabilizador) printf("- ANEL ESTABILIZADOR\n");
            }
        } else if (opcao == 6) {
            excluirItemMochila(comps, &n);
        } else if (opcao == 0) {
            break;
        } else {
            printf("Opcao invalida. Tente novamente.\n");
        }
    } 

    printf("\nSAINDO DO GAME!\n");
    return 0;
}

// Implementacoes
void mostrarComponentes(Componente comps[], int n) {
    printf("\nIndice | Nome                          | Tipo               | Prioridade\n");
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%5d | %-28s | %-18s | %9d\n", i, comps[i].nome, comps[i].tipo, comps[i].prioridade);
    }
}

void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//ordenacao generica
void ordenacao(Componente comps[], int n, long *comparacoes, double *tempo,int tipo) {
    clock_t inicio = clock();
    *comparacoes = 0;
    if(tipo==1){
    int trocou;
    //ordena por nome
    for (int pass = 0; pass < n - 1; pass++) {
        trocou = 0;
        for (int j = 0; j < n - pass - 1; j++) {
            (*comparacoes)++;
            if (strcmp(comps[j].nome, comps[j+1].nome) > 0) {
                Componente tmp = comps[j];
                comps[j] = comps[j+1];
                comps[j+1] = tmp;
                trocou = 1;
            }
        }
        if (!trocou) break; // otimização
    }
   }else if (tipo ==2)
   {//ordena por tipo
    for (int i = 1; i < n; i++) {
        Componente key = comps[i];
        int j = i - 1;
        while (j >= 0) {
            (*comparacoes)++;
            if (strcmp(comps[j].tipo, key.tipo) > 0) {
                comps[j+1] = comps[j];
                j--;
            } else {
                break;
            }
        }
        comps[j+1] = key;
    }
   }else if (tipo==3)
   {//ordena por prioridade
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            (*comparacoes)++;
            if (comps[j].prioridade < comps[minIdx].prioridade) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            Componente tmp = comps[i];
            comps[i] = comps[minIdx];
            comps[minIdx] = tmp;
        }
    }
   }else{
    printf("Tipo de ordenacao invalido\n");
   }
   clock_t fim = clock();
    *tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;      
}

// Selection Sort por prioridade (int) - crescente
void selectionSortPrioridade(Componente comps[], int n, long *comparacoes, double *tempo) {
    clock_t inicio = clock();
    *comparacoes = 0;
}

// Busca binária por nome, assume vetor ordenado por nome em ordem crescente
int buscaBinariaPorNome(Componente comps[], int n, const char chave[], long *comparacoes, double *tempo) {
    clock_t inicio = clock();
    *comparacoes = 0;

    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        (*comparacoes)++;
        int cmp = strcmp(comps[mid].nome, chave);
        if (cmp == 0) {
            clock_t fim = clock();
            *tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            return mid;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    clock_t fim = clock();
    *tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    return -1;
}
// Sistema de combate simples
void combateEGerarDrop(Componente comps[], int *n) {
    char cadastrar;
    printf("=== COMBATE INICIADO! ===\n");
    int vidaJogador = 30, vidaInimigo = 20;
    int danoJog = 6, danoIni = 4;
    while (vidaJogador > 0 && vidaInimigo > 0) {
    printf("Voce ataca e causa %d de dano!\n", danoJog);
    vidaInimigo -= danoJog;
    if (vidaInimigo <= 0) break;
    printf("Inimigo ataca e causa %d de dano!\n", danoIni);
    vidaJogador -= danoIni;
    }
    if (vidaJogador <= 0) {
    printf("Voce foi derrotado. Sem drops.\n");
    return;
    }
    printf("==========================================\n");
    printf("====INIMIGO DERROTADO! Escolha 1 drop:====\n");
    printf("==========================================\n");
    
    Componente baseDrops[10] = {
        {"MICROCHIP", "ELETRONICO", 2},
        {"SUPORTE DE TITANIO", "SUPORTE", 4},
        {"ITEM DE CURA", "CURA", 1},
        {"MODULO DE ENERGIA", "ENERGIA", 3},
        {"PAINEL OPTICO", "SENSOR", 5},
        {"NUCLEO MAGNETICO", "CONTROLE", 2},
        {"CARCAÇA REFORÇADA", "ESTRUTURA", 6},
        {"ESCUDO DE ENERGIA", "DEFESA", 4},
        {"CHIP RESERVA", "CONTROLE", 3},
        {"ANEL ESTABILIZADOR", "SUPORTE", 2}
    };

    // Gerar 3 opções aleatórias
    srand(time(NULL));
    Componente op[3];
    for (int i = 0; i < 3; i++) {
        int idx = rand() % 10;
        op[i] = baseDrops[idx];
    }
    for (int i = 0; i < 3; i++) {
        printf("%d - %s | %s | %d\n", i+1, op[i].nome, op[i].tipo, op[i].prioridade);
    }
    int escolha=0;
    printf("Digite a opcao desejada: ");
    scanf("%d", &escolha); limparBuffer();
    if (escolha < 1 || escolha > 3) {
        printf("Escolha invalida. Drop perdido.\n");
    return;
    }
    if (*n < MAX_COMPONENTES) {
    comps[*n] = op[escolha - 1];
    (*n)++;
    printf("Drop adicionado à mochila!\n");
    } else {
        printf("Mochila cheia! Não foi possível adicionar o item.\n");
        printf("Deseja substituir um item? (s/n): ");
        scanf(" %c", &cadastrar);
        
        if (cadastrar == 's' || cadastrar == 'S') {
            comps[*n] = op[escolha - 1];
            substituirItemMochila(comps, *n, op[escolha - 1]);
        }
        getchar();
    }
}
// Remover/substituir item da mochila
void substituirItemMochila(Componente comps[], int n, Componente novo) {
if (n == 0) {
printf("Mochila vazia. Nada para substituir.\n");
return;
}


mostrarComponentes(comps, n);


int idx;
printf("\nA mochila está cheia! Escolha o índice do item que deseja substituir pelo novo drop: ");
if (scanf("%d", &idx) != 1) {
limparBuffer();
printf("Entrada inválida. Operação cancelada.\n");
return;
}
limparBuffer();


if (idx < 0 || idx >= n) {
printf("Índice inválido. Operação cancelada.\n");
return;
}


// Substitui diretamente pelo novo item
comps[idx] = novo;


printf("Item substituído com sucesso! Novo item adicionado: %s | %s | %d\n",
novo.nome, novo.tipo, novo.prioridade);
}
void excluirItemMochila(Componente mochila[], int *qtd) {
    if (*qtd == 0) {
        printf("Mochila vazia, nada para excluir.");
        return;
    }
    printf("Escolha um item para excluir:\n");
    for (int i = 0; i < *qtd; i++) {
    printf("%d - %s (Qtd: %d)", i + 1, mochila[i].nome, mochila[i].quantidade);
    }

    int escolha;
    do {
    printf("Remover qual item? ");
    scanf("%d", &escolha);
    } while (escolha < 1 || escolha > *qtd);

    // Desloca itens após o removido
    for (int i = escolha - 1; i < *qtd - 1; i++) {
    mochila[i] = mochila[i + 1];
    }
    (*qtd)--;
        printf("Item removido com sucesso!\n");
}