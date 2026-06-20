#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

// Estrutura interna de um nó da árvore
typedef struct no_t {
    int valor;
    struct no_t *esquerda;
    struct no_t *direita;
} no_t;

// Estrutura interna que controla a árvore
struct arvore_t {
    no_t *raiz;
};

Arvore arvore_criar() {
    Arvore a = (Arvore)malloc(sizeof(struct arvore_t));
    if (a != NULL) {
        a->raiz = NULL;
    }
    return a;
}

int arvore_esta_vazia(Arvore a) {
    if (a == NULL || a->raiz == NULL) {
        return 1; // 1 = Verdadeiro
    }
    return 0; // 0 = Falso
}

// --- FUNÇÕES AUXILIARES RECURSIVAS ---

// Função auxiliar para inserir ordenado (Árvore Binária de Busca)
no_t* inserir_no(no_t *raiz, int valor) {
    if (raiz == NULL) {
        no_t *novo = (no_t *)malloc(sizeof(no_t));
        if (novo != NULL) {
            novo->valor = valor;
            novo->esquerda = NULL;
            novo->direita = NULL;
        }
        return novo;
    }
    
    if (valor < raiz->valor) {
        raiz->esquerda = inserir_no(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir_no(raiz->direita, valor);
    }
    // Valores iguais são ignorados nesta implementação simples
    
    return raiz;
}

void pre_ordem(no_t *raiz) {
    if (raiz != NULL) {
        printf("[%d] ", raiz->valor); // Visita a raiz
        pre_ordem(raiz->esquerda);    // Visita a esquerda
        pre_ordem(raiz->direita);     // Visita a direita
    }
}

void em_ordem(no_t *raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esquerda);     // Visita a esquerda
        printf("[%d] ", raiz->valor); // Visita a raiz
        em_ordem(raiz->direita);      // Visita a direita
    }
}

void pos_ordem(no_t *raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esquerda);    // Visita a esquerda
        pos_ordem(raiz->direita);     // Visita a direita
        printf("[%d] ", raiz->valor); // Visita a raiz
    }
}

void destruir_nos(no_t *raiz) {
    if (raiz != NULL) {
        destruir_nos(raiz->esquerda); // Destrói sub-árvore esquerda
        destruir_nos(raiz->direita);  // Destrói sub-árvore direita
        free(raiz);                   // Libera o nó atual
    }
}

// --- FIM DAS FUNÇÕES AUXILIARES ---

void arvore_inserir(Arvore a, int valor) {
    if (a == NULL) return;
    a->raiz = inserir_no(a->raiz, valor);
}

void arvore_exibir_pre_ordem(Arvore a) {
    if (arvore_esta_vazia(a)) {
        printf("A arvore esta vazia.\n");
        return;
    }
    printf("Pre-ordem: ");
    pre_ordem(a->raiz);
    printf("\n");
}

void arvore_exibir_em_ordem(Arvore a) {
    if (arvore_esta_vazia(a)) {
        printf("A arvore esta vazia.\n");
        return;
    }
    // Como é uma árvore de busca, "em ordem" exibirá os números em ordem crescente!
    printf("Em ordem : ");
    em_ordem(a->raiz);
    printf("\n");
}

void arvore_exibir_pos_ordem(Arvore a) {
    if (arvore_esta_vazia(a)) {
        printf("A arvore esta vazia.\n");
        return;
    }
    printf("Pos-ordem: ");
    pos_ordem(a->raiz);
    printf("\n");
}

void arvore_destruir(Arvore a) {
    if (a != NULL) {
        destruir_nos(a->raiz);
        free(a);
    }
}