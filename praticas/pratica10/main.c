#include <stdio.h>
#include "tabela_hash.h"

int main() {
    printf("=== Testando o TDA: Tabela Hash com Encadeamento ===\n\n");

    // 1. Criando a tabela hash com tamanho 7
    int tamanho_inicial = 7;
    TabelaHash minha_tabela = hash_criar(tamanho_inicial);

    // Verificando se está vazia inicialmente
    if (hash_esta_vazia(minha_tabela)) {
        printf("-> Tabela Hash criada com sucesso e mapeada como VAZIA.\n");
    }

    // 2. Inserindo elementos (Valores que geram colisões propositais para testes)
    printf("\n-> Inserindo valores: 15, 11, 22, 36, 8, 43\n");
    hash_inserir(minha_tabela, 15); // 15 % 7 = Pos 1
    hash_inserir(minha_tabela, 11); // 11 % 7 = Pos 4
    hash_inserir(minha_tabela, 22); // 22 % 7 = Pos 1 (Colisao!)
    hash_inserir(minha_tabela, 36); // 36 % 7 = Pos 1 (Colisao!)
    hash_inserir(minha_tabela, 8);  // 8  % 7 = Pos 1 (Colisao!)
    hash_inserir(minha_tabela, 43); // 43 % 7 = Pos 1 (Colisao!)

    // Exibe o estado da tabela para ver o encadeamento funcionando
    hash_exibir(minha_tabela);

    // 3. Testando as Buscas
    printf("\n-> Executando testes de busca:\n");
    int busca = 22;
    if (hash_buscar(minha_tabela, busca)) {
        printf("   - Valor %d: ENCONTRADO na tabela.\n", busca);
    } else {
        printf("   - Valor %d: NAO encontrado.\n", busca);
    }

    busca = 99;
    if (hash_buscar(minha_tabela, busca)) {
        printf("   - Valor %d: ENCONTRADO na tabela.\n", busca);
    } else {
        printf("   - Valor %d: NAO encontrado.\n", busca);
    }

    // 4. Testando as Remoções
    printf("\n-> Removendo o valor 22 (elemento do meio na Posicao 1)...\n");
    hash_remover(minha_tabela, 22);
    
    printf("-> Removendo o valor 11 (unico elemento na Posicao 4)...\n");
    hash_remover(minha_tabela, 11);

    // Reexibe a tabela modificada
    hash_exibir(minha_tabela);

    // 5. Destruição da Tabela
    printf("\n-> Destruindo a tabela hash e limpando os nós da memoria...\n");
    hash_destruir(minha_tabela);
    printf("-> Memoria totalmente liberada. Sucesso!\n");

    return 0;
}