#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

// Estrutura interna de um nó para encadeamento (lista ligada)
typedef struct no_t {
    int valor;
    struct no_t *proximo;
} no_t;

// Estrutura interna que controla a tabela hash
struct hash_t {
    no_t **tabela; // Vetor de ponteiros para nós (listas)
    int tamanho;
};

// Função hash interna (privada)
static int funcao_hash(int valor, int tamanho) {
    int pos = valor % tamanho;
    if (pos < 0) {
        pos += tamanho; // Garante índice positivo
    }
    return pos;
}

TabelaHash hash_criar(int tamanho) {
    if (tamanho <= 0) return NULL;

    TabelaHash h = (TabelaHash)malloc(sizeof(struct hash_t));
    if (h != NULL) {
        h->tamanho = tamanho;
        // Aloca o vetor de ponteiros para os nós
        h->tabela = (no_t **)malloc(tamanho * sizeof(no_t *));
        
        if (h->tabela == NULL) {
            free(h);
            return NULL;
        }

        // Inicializa todas as posições da tabela como vazias (NULL)
        for (int i = 0; i < tamanho; i++) {
            h->tabela[i] = NULL;
        }
    }
    return h;
}

int hash_esta_vazia(TabelaHash h) {
    if (h == NULL || h->tabela == NULL) return 1;

    // Se encontrar qualquer elemento em alguma das posições, não está vazia
    for (int i = 0; i < h->tamanho; i++) {
        if (h->tabela[i] != NULL) {
            return 0; // 0 = Falso
        }
    }
    return 1; // 1 = Verdadeiro
}

void hash_inserir(TabelaHash h, int valor) {
    if (h == NULL || h->tabela == NULL) return;

    int pos = funcao_hash(valor, h->tamanho);

    // Cria o novo nó
    no_t *novo = (no_t *)malloc(sizeof(no_t));
    if (novo == NULL) return;
    
    novo->valor = valor;

    // Insere no início da lista encadeada daquela posição (Tratamento de Colisão)
    novo->proximo = h->tabela[pos];
    h->tabela[pos] = novo;
}

int hash_buscar(TabelaHash h, int valor) {
    if (h == NULL || h->tabela == NULL) return 0;

    int pos = funcao_hash(valor, h->tamanho);
    no_t *atual = h->tabela[pos];

    // Percorre a lista encadeada na posição calculada
    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1; // Encontrou (1 = Verdadeiro)
        }
        atual = atual->proximo;
    }
    return 0; // Não encontrou (0 = Falso)
}

void hash_remover(TabelaHash h, int valor) {
    if (h == NULL || h->tabela == NULL) return;

    int pos = funcao_hash(valor, h->tamanho);
    no_t *atual = h->tabela[pos];
    no_t *anterior = NULL;

    // Procura o elemento na lista encadeada da posição
    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) return; // Valor não foi encontrado

    // Se o elemento a ser removido for o primeiro da lista daquela posição
    if (anterior == NULL) {
        h->tabela[pos] = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
}

void hash_exibir(TabelaHash h) {
    if (h == NULL || h->tabela == NULL) {
        printf("Tabela Hash invalida.\n");
        return;
    }

    printf("\n------- ESPELHO DA TABELA HASH -------\n");
    for (int i = 0; i < h->tamanho; i++) {
        printf("Posicao [%d]: ", i);
        no_t *atual = h->tabela[i];
        
        if (atual == NULL) {
            printf("NULL");
        } else {
            while (atual != NULL) {
                printf("[%d] -> ", atual->valor);
                atual = atual->proximo;
            }
            printf("NULL");
        }
        printf("\n");
    }
    printf("--------------------------------------\n");
}

void hash_destruir(TabelaHash h) {
    if (h != NULL) {
        if (h->tabela != NULL) {
            // Libera a memória de cada nó de cada uma das listas
            for (int i = 0; i < h->tamanho; i++) {
                no_t *atual = h->tabela[i];
                while (atual != NULL) {
                    no_t *aux = atual->proximo;
                    free(atual);
                    atual = aux;
                }
            }
            // Libera o vetor de ponteiros
            free(h->tabela);
        }
        // Libera a estrutura principal
        free(h);
    }
}