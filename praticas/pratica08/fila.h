#ifndef FILA_H
#define FILA_H

// Tipo opaco da Fila
typedef struct fila_t* Fila;

// Protótipos das funções solicitadas
Fila fila_criar();
void fila_enfileirar(Fila f, int valor);
void fila_desenfileirar(Fila f);
int fila_inicio(Fila f);
void fila_exibir(Fila f); // Ajustado de lista_exibir para fila_exibir
int fila_esta_vazia(Fila f);
void fila_destruir(Fila f);

#endif