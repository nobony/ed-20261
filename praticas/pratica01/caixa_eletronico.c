#include <stdio.h>

void processar_saque(int valor) {

    if (valor > 1000) {
        printf("Tentativa de saque: R$ %d -> Erro: Valor maximo permitido e 1000.\n\n", valor);
        return;
    }
    
    printf("Valor do saque: R$ %d\n", valor);
    
    int notas[] = {200, 100, 50, 20, 10, 5, 2};
    int resto = valor;
    int quantidade_notas;
    
    for (int i = 0; i < 7; i++) {
        quantidade_notas = resto / notas[i];
        
        if (quantidade_notas > 0) {
            printf("%d nota(s) de R$ %d\n", quantidade_notas, notas[i]);
            resto = resto % notas[i];
        }
    }
    
    if (resto != 0) {
        printf("Aviso: Nao foi possivel sacar R$ %d (sem notas disponiveis).\n", resto);
    }
    printf("\n");
}

int main() {
    printf("TESTE\n");
    
    processar_saque(587);  // Teste de saque normal
    processar_saque(100);  // Teste com valor redondo
    processar_saque(1500); // Teste simulando o erro de limite
    
    return 0;
}