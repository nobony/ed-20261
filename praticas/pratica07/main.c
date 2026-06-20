#include <stdio.h>
#include "pilha.h"

int main() {
    printf("=== Testando o TDA: Pilha (FILO) ===\n\n");

    // 1. Criando a pilha
    Pilha minha_pilha = pilha_criar();

    // 2. Testando inserções (Push)
    printf("-> Empilhando: 10, 20, 30 e 40\n");
    pilha_empilhar(minha_pilha, 10);
    pilha_empilhar(minha_pilha, 20);
    pilha_empilhar(minha_pilha, 30);
    pilha_empilhar(minha_pilha, 40);
    
    // Exibe (o 40 deve ser o primeiro a aparecer por estar no topo)
    pilha_exibir(minha_pilha);

    // 3. Consultando o Topo
    printf("\n-> Elemento no topo atual: %d\n", pilha_topo(minha_pilha));

    // 4. Testando remoções (Pop)
    printf("\n-> Desempilhando um elemento...\n");
    pilha_desempilhar(minha_pilha);
    pilha_exibir(minha_pilha);
    printf("-> Novo elemento no topo: %d\n", pilha_topo(minha_pilha));

    printf("\n-> Desempilhando mais dois elementos...\n");
    pilha_desempilhar(minha_pilha);
    pilha_desempilhar(minha_pilha);
    pilha_exibir(minha_pilha);

    // 5. Destruindo a pilha
    printf("\n-> Liberando a memoria da pilha...\n");
    pilha_destruir(minha_pilha);
    printf("-> Sucesso!\n");

    return 0;
}