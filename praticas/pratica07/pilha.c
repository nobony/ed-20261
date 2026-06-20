#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Estrutura interna de um nó da pilha
typedef struct no_t {
    int valor;
    struct no_t *proximo;
} no_t;

// Estrutura interna que controla a pilha
struct pilha_t {
    no_t *topo;
};

Pilha pilha_criar() {
    Pilha p = (Pilha)malloc(sizeof(struct pilha_t));
    if (p != NULL) {
        p->topo = NULL;
    }
    return p;
}

int pilha_esta_vazia(Pilha p) {
    if (p == NULL || p->topo == NULL) {
        return 1; // 1 = Verdadeiro
    }
    return 0; // 0 = Falso
}

void pilha_empilhar(Pilha p, int valor) {
    if (p == NULL) return;

    no_t *novo = (no_t *)malloc(sizeof(no_t));
    if (novo == NULL) return;

    novo->valor = valor;
    // O novo nó aponta para o antigo topo
    novo->proximo = p->topo;
    // O topo da pilha passa a ser o novo nó
    p->topo = novo;
}

void pilha_desempilhar(Pilha p) {
    if (pilha_esta_vazia(p)) return;

    // Guarda o nó do topo atual
    no_t *aux = p->topo;
    // O topo avança para o próximo nó abaixo dele
    p->topo = p->topo->proximo;
    // Libera a memória do nó removido
    free(aux);
}

int pilha_topo(Pilha p) {
    if (pilha_esta_vazia(p)) {
        printf("Aviso: A pilha esta vazia. Retornando valor invalido.\n");
        return -1; 
    }
    return p->topo->valor;
}

void pilha_exibir(Pilha p) {
    if (pilha_esta_vazia(p)) {
        printf("A pilha esta vazia.\n");
        return;
    }

    no_t *atual = p->topo;
    printf("Pilha (Topo -> Base): ");
    while (atual != NULL) {
        printf("[%d] ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void pilha_destruir(Pilha p) {
    if (p != NULL) {
        // Desempilha todos os elementos até esvaziar
        while (!pilha_esta_vazia(p)) {
            pilha_desempilhar(p);
        }
        // Libera a estrutura principal
        free(p);
    }
}