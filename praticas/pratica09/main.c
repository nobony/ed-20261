#include <stdio.h>
#include "arvore_binaria.h"

int main() {
    printf("=== Testando o TDA: Arvore Binaria de Busca ===\n\n");

    // 1. Criando a árvore
    Arvore minha_arvore = arvore_criar();

    // 2. Inserindo valores
    // Vamos inserir valores de forma a criar uma árvore equilibrada para testes
    printf("-> Inserindo valores: 50, 30, 70, 20, 40, 60, 80\n\n");
    arvore_inserir(minha_arvore, 50); // Raiz
    arvore_inserir(minha_arvore, 30);
    arvore_inserir(minha_arvore, 70);
    arvore_inserir(minha_arvore, 20);
    arvore_inserir(minha_arvore, 40);
    arvore_inserir(minha_arvore, 60);
    arvore_inserir(minha_arvore, 80);

    // 3. Exibindo percursos
    printf("-> Analisando os percursos da arvore:\n");
    arvore_exibir_pre_ordem(minha_arvore);
    arvore_exibir_em_ordem(minha_arvore);
    arvore_exibir_pos_ordem(minha_arvore);

    // 4. Destruindo a árvore
    printf("\n-> Liberando a memoria da arvore...\n");
    arvore_destruir(minha_arvore);
    printf("-> Sucesso!\n");

    return 0;
}