#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

// Definição da struct interna do nó
typedef struct no_t {
    int valor;
    struct no_t *anterior;
    struct no_t *proximo;
} no_t;

// Definição da struct interna da lista
struct lista_t {
    no_t *primeiro;
    no_t *ultimo;
};

Lista lista_criar() {
    Lista l = (Lista)malloc(sizeof(struct lista_t));
    if (l != NULL) {
        l->primeiro = NULL;
        l->ultimo = NULL;
    }
    return l;
}

int lista_esta_vazia(Lista l) {
    if (l == NULL || l->primeiro == NULL) {
        return 1; // 1 significa Verdadeiro
    }
    return 0; // 0 significa Falso
}

void lista_inserir(Lista l, int valor) {
    if (l == NULL) return;

    no_t *novo = (no_t *)malloc(sizeof(no_t));
    if (novo == NULL) return;

    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = l->ultimo;

    // Se a lista estiver vazia, o novo nó é o primeiro
    if (lista_esta_vazia(l)) {
        l->primeiro = novo;
    } else {
        // Senão, o último nó atual aponta para o novo
        l->ultimo->proximo = novo;
    }
    // O novo nó passa a ser o último
    l->ultimo = novo;
}

void lista_remover(Lista l, int valor) {
    if (lista_esta_vazia(l)) return;

    no_t *atual = l->primeiro;

    // Procura o valor na lista
    while (atual != NULL && atual->valor != valor) {
        atual = atual->proximo;
    }

    if (atual == NULL) return; // Valor não encontrado

    // Se o elemento a remover for o primeiro
    if (atual == l->primeiro) {
        l->primeiro = atual->proximo;
    } else {
        atual->anterior->proximo = atual->proximo;
    }

    // Se o elemento a remover for o último
    if (atual == l->ultimo) {
        l->ultimo = atual->anterior;
    } else {
        atual->proximo->anterior = atual->anterior;
    }

    free(atual);
}

int lista_buscar(Lista l, int valor) {
    if (lista_esta_vazia(l)) return 0;

    no_t *atual = l->primeiro;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1; // Encontrou
        }
        atual = atual->proximo;
    }
    return 0; // Não encontrou
}

void lista_exibir(Lista l) {
    if (lista_esta_vazia(l)) {
        printf("A lista esta vazia.\n");
        return;
    }

    no_t *atual = l->primeiro;
    printf("Elementos da Lista: ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void lista_destruir(Lista l) {
    if (l != NULL) {
        no_t *atual = l->primeiro;
        while (atual != NULL) {
            no_t *prox = atual->proximo; // Guarda o próximo antes de apagar
            free(atual);                 // Apaga o nó atual
            atual = prox;                // Avança
        }
        free(l); // Apaga a estrutura principal da lista
    }
}