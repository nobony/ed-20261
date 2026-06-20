#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Estrutura interna de um nó da fila
typedef struct no_t {
    int valor;
    struct no_t *proximo;
} no_t;

// Estrutura interna que controla a fila
struct fila_t {
    no_t *inicio;
    no_t *fim;
};

Fila fila_criar() {
    Fila f = (Fila)malloc(sizeof(struct fila_t));
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
    }
    return f;
}

int fila_esta_vazia(Fila f) {
    if (f == NULL || f->inicio == NULL) {
        return 1; // 1 = Verdadeiro
    }
    return 0; // 0 = Falso
}

void fila_enfileirar(Fila f, int valor) {
    if (f == NULL) return;

    no_t *novo = (no_t *)malloc(sizeof(no_t));
    if (novo == NULL) return;

    novo->valor = valor;
    novo->proximo = NULL;

    // Se a fila estiver vazia, o novo nó é o início e o fim
    if (fila_esta_vazia(f)) {
        f->inicio = novo;
    } else {
        // Se já tem elementos, o nó atual do fim aponta para o novo
        f->fim->proximo = novo;
    }
    
    // O novo nó passa a ser o fim oficial da fila
    f->fim = novo;
}

void fila_desenfileirar(Fila f) {
    if (fila_esta_vazia(f)) return;

    // Guarda o nó do início atual
    no_t *aux = f->inicio;
    
    // O início avança para o próximo da fila
    f->inicio = f->inicio->proximo;

    // Se a fila ficou vazia após remover, o fim também precisa ser NULL
    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    // Libera a memória do nó removido
    free(aux);
}

int fila_inicio(Fila f) {
    if (fila_esta_vazia(f)) {
        printf("Aviso: A fila esta vazia. Retornando valor invalido.\n");
        return -1; 
    }
    return f->inicio->valor;
}

void fila_exibir(Fila f) {
    if (fila_esta_vazia(f)) {
        printf("A fila esta vazia.\n");
        return;
    }

    no_t *atual = f->inicio;
    printf("Fila (Inicio -> Fim): ");
    while (atual != NULL) {
        printf("[%d] ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void fila_destruir(Fila f) {
    if (f != NULL) {
        // Desenfileira todos os elementos até esvaziar
        while (!fila_esta_vazia(f)) {
            fila_desenfileirar(f);
        }
        // Libera a estrutura principal
        free(f);
    }
}