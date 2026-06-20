#ifndef PILHA_H
#define PILHA_H

// Tipo opaco da Pilha
typedef struct pilha_t* Pilha;

// Protótipos das funções solicitadas
Pilha pilha_criar();
void pilha_empilhar(Pilha p, int valor);
void pilha_desempilhar(Pilha p);
int pilha_topo(Pilha p);
int pilha_esta_vazia(Pilha p);
void pilha_exibir(Pilha p);
void pilha_destruir(Pilha p);

#endif