#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASH_SIZE 101

//estruturas de dados

// Nó da árvore de cômodos (mansão)
typedef struct Sala {
    char *nome;
    struct Sala *esq;
    struct Sala *dir;
} Sala;

// Nó da BST para pistas coletadas (ordenada por string)
typedef struct PistaNode {
    char *pista;
    struct PistaNode *esq;
    struct PistaNode *dir;
} PistaNode;

// Nó para lista encadeada (encadeamento em hash)
typedef struct HashNode {
    char *chave;      // pista
    char *suspeito;   // suspeito associado
    struct HashNode *prox;
} HashNode;

// Tabela hash (vetor de ponteiros para HashNode)
typedef struct HashTable {
    HashNode *buckets[HASH_SIZE];
} HashTable;

/***********************
 * Assinaturas (APIs)  *
 ***********************/

// Cria dinamicamente uma sala.
Sala* criarSala(const char *nome);

// Explora salas de forma interativa 
void explorarSalas(Sala *raiz, PistaNode **arvorePistas, HashTable *hash);

// Insere pista na BST 
PistaNode* inserirPista(PistaNode *raiz, const char *pista);

// Inserir associação pista -> suspeito na tabela hash.
void inserirNaHash(HashTable *ht, const char *pista, const char *suspeito);

// Buscar suspeito correspondente a uma pista na hash.
char* encontrarSuspeito(HashTable *ht, const char *pista);

// Verifica o suspeito final (fase de julgamento).
void verificarSuspeitoFinal(PistaNode *arvorePistas, HashTable *ht);

// Funções auxiliares
void listarPistasInOrder(PistaNode *raiz);
int pistaExiste(PistaNode *raiz, const char *pista);
unsigned long djb2_hash(const char *str);
void initHash(HashTable *ht);
char* getPistaParaSala(const char *nomeSala);
void freePistaTree(PistaNode *raiz);
void freeSalaTree(Sala *raiz);
void freeHash(HashTable *ht);

//implementações

//cria sala
Sala* criarSala(const char *nome) {
    Sala *s = (Sala*) malloc(sizeof(Sala));
    if (!s) {
        perror("Erro ao alocar sala");
        exit(EXIT_FAILURE);
    }
    s->nome = strdup(nome);
    s->esq = s->dir = NULL;
    return s;
}

// Define pistas fixas para cada sala (pode ser expandido)
char* getPistaParaSala(const char *nomeSala) {
    if (strcmp(nomeSala, "Entrada") == 0) {
        return "Pegada de lama";
    } else if (strcmp(nomeSala, "Sala de Estar") == 0) {
        return "Copo quebrado";
    } else if (strcmp(nomeSala, "Biblioteca") == 0) {
        return "Página rasgada";
    } else if (strcmp(nomeSala, "Cozinha") == 0) {
        return "Fio de cabelo loiro";
    } else if (strcmp(nomeSala, "Jardim de Inverno") == 0) {
        return "Sementes pisoteadas";
    } else if (strcmp(nomeSala, "Quarto Principal") == 0) {
        return "Perfume caro";
    } else if (strcmp(nomeSala, "Escritório") == 0) {
        return "Carta ameaçadora";
    } else if (strcmp(nomeSala, "Despensa") == 0) {
        return "Luvas manchadas";
    }
    return NULL;
}
// Inicializa a tabela hash
void initHash(HashTable *ht) {
    for (int i = 0; i < HASH_SIZE; ++i) ht->buckets[i] = NULL;
}

// Função hash djb2    
unsigned long djb2_hash(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash;
}

// Inserir na hash (pista -> suspeito)
void inserirNaHash(HashTable *ht, const char *pista, const char *suspeito) {
    unsigned long h = djb2_hash(pista) % HASH_SIZE;
    HashNode *novo = (HashNode*) malloc(sizeof(HashNode));
    if (!novo) { perror("malloc"); exit(EXIT_FAILURE); }
    novo->chave = strdup(pista);
    novo->suspeito = strdup(suspeito);
    novo->prox = ht->buckets[h];
    ht->buckets[h] = novo;
}

// Buscar suspeito na hash pela pista
char* encontrarSuspeito(HashTable *ht, const char *pista) {
    unsigned long h = djb2_hash(pista) % HASH_SIZE;
    HashNode *it = ht->buckets[h];
    while (it) {
        if (strcmp(it->chave, pista) == 0) return it->suspeito;
        it = it->prox;
    }
    return NULL;
}

// Verifica se a pista já existe na BST
int pistaExiste(PistaNode *raiz, const char *pista) {
    if (!raiz) return 0;
    int cmp = strcmp(pista, raiz->pista);
    if (cmp == 0) return 1;
    if (cmp < 0) return pistaExiste(raiz->esq, pista);
    else return pistaExiste(raiz->dir, pista);
}

// Insere pista na BST
PistaNode* inserirPista(PistaNode *raiz, const char *pista) {
    if (!raiz) {
        PistaNode *n = (PistaNode*) malloc(sizeof(PistaNode));
        if (!n) { perror("malloc"); exit(EXIT_FAILURE); }
        n->pista = strdup(pista);
        n->esq = n->dir = NULL;
        return n;
    }
    int cmp = strcmp(pista, raiz->pista);
    if (cmp == 0) return raiz; // já existe
    if (cmp < 0) raiz->esq = inserirPista(raiz->esq, pista);
    else raiz->dir = inserirPista(raiz->dir, pista);
    return raiz;
}

// Lista pistas em ordem alfabética (in-order)
void listarPistasInOrder(PistaNode *raiz) {
    if (!raiz) return;
    listarPistasInOrder(raiz->esq);
    printf(" - %s\n", raiz->pista);
    listarPistasInOrder(raiz->dir);
}

// Exploração interativa das salas
void explorarSalas(Sala *raiz, PistaNode **arvorePistas, HashTable *hash) {
    Sala *atual = raiz;
    char linha[128];

    printf("\n--- Início da exploração da mansão ---\n");
    while (1) {
        if (!atual) {
            printf("Você está em um corredor vazio (NULL). Não há sala aqui.\n");
        } else {
            printf("\nVocê entrou na sala: %s\n", atual->nome);
            char *pista = getPistaParaSala(atual->nome);
            if (pista) {
                if (!pistaExiste(*arvorePistas, pista)) {
                    printf("Você encontrou uma pista: \"%s\". Ela foi adicionada ao seu relatório.\n", pista);
                    *arvorePistas = inserirPista(*arvorePistas, pista);
                } else {
                    printf("Você já havia coletado a pista desta sala: \"%s\".\n", pista);
                }
            } else {
                printf("Nenhuma pista óbvia nesta sala.\n");
            }
        }

        printf("\nEscolha onde ir: (e) esquerda, (d) direita, (s) sair e finalizar exploração\n");
        printf("Digite a opção: ");
        if (!fgets(linha, sizeof(linha), stdin)) break;
        char op = tolower(linha[0]);

        if (op == 's') {
            printf("Encerrando exploração...\n");
            break;
        } else if (op == 'e') {
            if (atual && atual->esq) {
                atual = atual->esq;
            } else {
                printf("Não há sala à esquerda. Permanece na sala atual.\n");
            }
        } else if (op == 'd') {
            if (atual && atual->dir) {
                atual = atual->dir;
            } else {
                printf("Não há sala à direita. Permanece na sala atual.\n");
            }
        } else {
            printf("Opção inválida. Use 'e', 'd' ou 's'.\n");
        }
    }
    printf("\n--- Fim da exploração ---\n");
}

// Verifica o suspeito final (fase de julgamento)
void verificarSuspeitoFinal(PistaNode *arvorePistas, HashTable *ht) {
    char linha[256];
    if (!arvorePistas) {
        printf("Você não coletou nenhuma pista. Não é possível acusar ninguém.\n");
        return;
    }
    printf("\nPistas coletadas (ordenadas):\n");
    listarPistasInOrder(arvorePistas);

    printf("\nQuem você deseja acusar? Digite o nome do suspeito: ");
    if (!fgets(linha, sizeof(linha), stdin)) return;
    // remover newline
    linha[strcspn(linha, "\r\n")] = 0;
    // trim de espaços iniciais/finais
    char *start = linha;
    while (isspace((unsigned char)*start)) start++;
    char *end = start + strlen(start) - 1;
    while (end > start && isspace((unsigned char)*end)) { *end = '\0'; end--; }
    if (strlen(start) == 0) {
        printf("Nome inválido.\n");
        return;
    }
    int contador = 0;
    extern int countMatches(PistaNode *raiz, HashTable *ht, const char *suspeito);
    contador = countMatches(arvorePistas, ht, start);

    printf("\nVocê acusou: %s\n", start);
    printf("Número de pistas que apontam para %s: %d\n", start, contador);

    if (contador >= 2) {
        printf("\nResultado: Acusação válida! Há pistas suficientes para responsabilizar %s.\n", start);
    } else {
        printf("\nResultado: Acusação fraca. Não há pistas suficientes para provar que %s é o culpado.\n", start);
    }
}
// Conta quantas pistas na BST apontam para o suspeito dado 
int countMatches(PistaNode *raiz, HashTable *ht, const char *suspeito) {
    if (!raiz) return 0;
    int left = countMatches(raiz->esq, ht, suspeito);
    int right = countMatches(raiz->dir, ht, suspeito);
    char *s = encontrarSuspeito(ht, raiz->pista);
    int here = (s && strcmp(s, suspeito) == 0) ? 1 : 0;
    return left + here + right;
}

// Libera recursivamente árvore de Pistas.
void freePistaTree(PistaNode *raiz) {
    if (!raiz) return;
    freePistaTree(raiz->esq);
    freePistaTree(raiz->dir);
    free(raiz->pista);
    free(raiz);
}

// Libera recursivamente árvore de Salas.
void freeSalaTree(Sala *raiz) {
    if (!raiz) return;
    freeSalaTree(raiz->esq);
    freeSalaTree(raiz->dir);
    free(raiz->nome);
    free(raiz);
}

// Libera tabela hash
void freeHash(HashTable *ht) {
    for (int i = 0; i < HASH_SIZE; ++i) {
        HashNode *it = ht->buckets[i];
        while (it) {
            HashNode *tmp = it;
            it = it->prox;
            free(tmp->chave);
            free(tmp->suspeito);
            free(tmp);
        }
        ht->buckets[i] = NULL;
    }
}

//-----------------------------------------
int main(void) {
    Sala *entrada = criarSala("Entrada");
    Sala *salaEstar = criarSala("Sala de Estar");
    Sala *biblioteca = criarSala("Biblioteca");
    Sala *cozinha = criarSala("Cozinha");
    Sala *jardim = criarSala("Jardim de Inverno");
    Sala *quarto = criarSala("Quarto Principal");
    Sala *escritorio = criarSala("Escritório");
    Sala *despensa = criarSala("Despensa");

    // ligações
    entrada->esq = salaEstar;
    entrada->dir = biblioteca;
    salaEstar->esq = cozinha;
    salaEstar->dir = jardim;
    cozinha->esq = despensa;
    biblioteca->esq = quarto;
    biblioteca->dir = escritorio;

    // 2) Criar tabela hash e inserir pares pista->suspeito (fixos)
    HashTable ht;
    initHash(&ht);

    // Mapeamentos de pistas para suspeitos (exemplo):
    inserirNaHash(&ht, "Pegada de lama", "Jardineiro");
    inserirNaHash(&ht, "Copo quebrado", "Criada");
    inserirNaHash(&ht, "Página rasgada", "Bibliotecário");
    inserirNaHash(&ht, "Fio de cabelo loiro", "Herança");
    inserirNaHash(&ht, "Sementes pisoteadas", "Jardineiro");
    inserirNaHash(&ht, "Perfume caro", "Herança");
    inserirNaHash(&ht, "Carta ameaçadora", "Advogado");
    inserirNaHash(&ht, "Luvas manchadas", "Cozinheiro");

    // 3) BST vazia para armazenar pistas coletadas
    PistaNode *arvorePistas = NULL;

    // 4) Explicar as regras ao jogador
    printf("Bem-vindo(a) a Detective Quest - Capítulo Final!\n");
    printf("Explore a mansão digitando 'e' (esquerda) ou 'd' (direita).\n");
    printf("Quando quiser encerrar a exploração e ir ao julgamento, digite 's'.\n");
    printf("Colete pistas e no final acuse o suspeito que você acredita ser o culpado.\n");
    printf("Boa sorte, detetive!\n");

    // 5) Iniciar exploração interativa
    explorarSalas(entrada, &arvorePistas, &ht);

    // 6) Ir para julgamento final
    verificarSuspeitoFinal(arvorePistas, &ht);

    // 7) Limpeza
    freePistaTree(arvorePistas);
    freeHash(&ht);
    freeSalaTree(entrada);

    printf("\nObrigado por jogar Detective Quest! Fim do programa.\n");
    return 0;
}
