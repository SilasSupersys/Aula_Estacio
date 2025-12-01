#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_FILA 5
#define TAM_PILHA 3

//variaveis globais para fila e pilha
Peca fila[TAM_FILA];
int frente = 0;
int tras = 0;
int quantidadeFila = 0;

Peca pilha[TAM_PILHA];
int topo = -1;
int geradorID = 1;

//peça estrutura
typedef struct {
    char nome;
    int id;
} Peca;


//gerar peça aleatória
Peca gerarPeca() {
    Peca p;
    char tipos[] = {'I', 'O', 'T', 'L'};
    p.nome = tipos[rand() % 4];
    p.id = geradorID++;
    return p;
}

//enfileirar (adicionar no final)
void enfileirar(Peca p) {
    if (quantidadeFila == TAM_FILA) return;

    fila[tras] = p;
    tras = (tras + 1) % TAM_FILA;
    quantidadeFila++;
}

//desenfileirar (remover do início)
Peca desenfileirar() {
    Peca removida = fila[frente];
    frente = (frente + 1) % TAM_FILA;
    quantidadeFila--;
    return removida;
}

//push na pilha
void push(Peca p) {
    if (topo < TAM_PILHA - 1) {
        topo++;
        pilha[topo] = p;
    }
}

//pop da pilha
Peca pop() {
    Peca p = pilha[topo];
    topo--;
    return p;
}

//exibir fila
void exibirFila() {
    printf("Fila: ");
    for (int i = 0, idx = frente; i < quantidadeFila; i++) {
        printf("[%c-%d] ", fila[idx].nome, fila[idx].id);
        idx = (idx + 1) % TAM_FILA;
    }
    printf("\n");
}

//exibir pilha
void exibirPilha() {
    printf("Pilha: ");
    for (int i = 0; i <= topo; i++) {
        printf("[%c-%d] ", pilha[i].nome, pilha[i].id);
    }
    printf("\n");
}

//exibir estado atual
void exibirEstado() {
    printf("\n [*]  [*]  [*] ESTADO ATUAL  [*]  [*]  [*] \n");
    exibirFila();
    exibirPilha();
    printf(" [*]  [*]  [*]  [*]  [*]  [*]  [*]  [*]  [*] \n");
}

//preencher fila até o máximo
void manterFilaCheia() {
    while (quantidadeFila < TAM_FILA) {
        enfileirar(gerarPeca());
    }
}

//jogar peça (dequeue)
void jogarPeca() {
    if (quantidadeFila == 0) {
        printf("Fila vazia!\n");
        return;
    }

    Peca usada = desenfileirar();
    printf("Peça jogada: %c-%d\n", usada.nome, usada.id);

    manterFilaCheia();
}

// Reservar peça (push)
void reservarPeca() {
    if (quantidadeFila == 0) {
        printf("Fila vazia!\n");
        return;
    }
    if (topo == TAM_PILHA - 1) {
        printf("Pilha cheia! Não é possível reservar.\n");
        return;
    }

    Peca p = desenfileirar();
    push(p);

    printf("Peça reservada: %c-%d\n", p.nome, p.id);

    manterFilaCheia();
}

// Usar peça reservada (pop)
void usarReservada() {
    if (topo < 0) {
        printf("Pilha vazia!\n");
        return;
    }

    Peca p = pop();
    printf("Peça reservada usada: %c-%d\n", p.nome, p.id);
}

// Trocar peça atual (topo ↔ frente)
void trocarAtual() {
    if (topo < 0) {
        printf("Pilha vazia, não há peça para troca.\n");
        return;
    }

    if (quantidadeFila == 0) {
        printf("Fila vazia!\n");
        return;
    }

    int idx = frente;

    Peca aux = fila[idx];
    fila[idx] = pilha[topo];
    pilha[topo] = aux;

    printf("Troca realizada entre a frente da fila e o topo da pilha.\n");
}

// Troca múltipla (3 peças)
void trocaMultipla() {
    if (quantidadeFila < 3 || topo < 2) {
        printf("Não há peças suficientes para a troca múltipla.\n");
        return;
    }

    for (int i = 0; i < 3; i++) {
        int idx = (frente + i) % TAM_FILA;

        Peca aux = fila[idx];
        fila[idx] = pilha[topo - i];
        pilha[topo - i] = aux;
    }

    printf("Troca múltipla realizada.\n");
}

//-----------------------------------------
// MENU PRINCIPAL
//-----------------------------------------
int main() {
    srand(time(NULL));

    // Inicializa a fila cheia
    manterFilaCheia();

    int opcao;
    do {
        exibirEstado();

        printf("\n [*]  [*]  [*] MENU [*]  [*]  [*] \n");
        printf("1 - Jogar peça (dequeue)\n");
        printf("2 - Reservar peça (fila -> pilha)\n");
        printf("3 - Usar peça reservada (pop)\n");
        printf("4 - Trocar peça atual (frente <-> topo)\n");
        printf("5 - Troca múltipla (3 peças)\n");
        printf("6 - Visualizar estado\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: jogarPeca(); break;
            case 2: reservarPeca(); break;
            case 3: usarReservada(); break;
            case 4: trocarAtual(); break;
            case 5: trocaMultipla(); break;
            case 6: exibirEstado(); break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opção inválida!\n"); break;
        }

    } while (opcao != 0);

    return 0;
}
