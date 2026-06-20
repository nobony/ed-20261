#include <stdio.h>
#include "lista_linear.h"

int main() {
    printf("=== Testando o TDA: Lista Linear ===\n\n");

    // Criação da lista
    Lista minha_lista = lista_criar();

    // Teste: Inserção e Exibição
    printf("1. Inserindo os valores 10, 20, 30 e 40...\n");
    lista_inserir(minha_lista, 10);
    lista_inserir(minha_lista, 20);
    lista_inserir(minha_lista, 30);
    lista_inserir(minha_lista, 40);
    lista_exibir(minha_lista);

    // Teste: Busca
    printf("\n2. Buscando o valor 30 na lista...\n");
    if (lista_buscar(minha_lista, 30)) {
        printf("-> O valor 30 foi ENCONTRADO na lista!\n");
    } else {
        printf("-> O valor 30 NAO foi encontrado.\n");
    }

    // Teste: Remoção
    printf("\n3. Removendo o valor 20...\n");
    lista_remover(minha_lista, 20);
    lista_exibir(minha_lista);

    // Teste: Remoção das pontas (primeiro e último)
    printf("\n4. Removendo as pontas (10 e 40)...\n");
    lista_remover(minha_lista, 10);
    lista_remover(minha_lista, 40);
    lista_exibir(minha_lista);

    // Teste: Destruição
    printf("\n5. Destruindo a lista e liberando a memoria...\n");
    lista_destruir(minha_lista);
    printf("-> Memoria liberada com sucesso!\n");

    return 0;
}