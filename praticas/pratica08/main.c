#include <stdio.h>
#include "fila.h"

int main() {
    printf("=== Testando o TDA: Fila (FIFO) ===\n\n");

    // 1. Criando a fila
    Fila minha_fila = fila_criar();

    // 2. Testando inserções (Enfileirar)
    printf("-> Chegaram na fila: 10, 20, 30 e 40\n");
    fila_enfileirar(minha_fila, 10);
    fila_enfileirar(minha_fila, 20);
    fila_enfileirar(minha_fila, 30);
    fila_enfileirar(minha_fila, 40);
    
    // Exibe (o 10 deve ser o primeiro da fila)
    fila_exibir(minha_fila);

    // 3. Consultando o Início
    printf("\n-> Elemento no inicio atual: %d\n", fila_inicio(minha_fila));

    // 4. Testando remoções (Desenfileirar)
    printf("\n-> Atendendo (removendo) o primeiro da fila...\n");
    fila_desenfileirar(minha_fila);
    fila_exibir(minha_fila);
    printf("-> Novo elemento no inicio: %d\n", fila_inicio(minha_fila));

    printf("\n-> Atendendo mais duas pessoas...\n");
    fila_desenfileirar(minha_fila);
    fila_desenfileirar(minha_fila);
    fila_exibir(minha_fila);

    // 5. Destruindo a fila
    printf("\n-> Liberando a memoria da fila...\n");
    fila_destruir(minha_fila);
    printf("-> Sucesso!\n");

    return 0;
}