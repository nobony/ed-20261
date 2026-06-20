#ifndef TABELA_HASH_H
#define TABELA_HASH_H

// Tipo opaco da Tabela Hash
typedef struct hash_t* TabelaHash;

// Protótipos das funções solicitadas
TabelaHash hash_criar(int tamanho);
void hash_inserir(TabelaHash h, int valor);
int hash_buscar(TabelaHash h, int valor);
void hash_remover(TabelaHash h, int valor);
void hash_exibir(TabelaHash h);
int hash_esta_vazia(TabelaHash h);
void hash_destruir(TabelaHash h);

#endif