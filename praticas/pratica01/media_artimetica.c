#include <stdio.h>

float calcular_media(int n, float numeros[]) {

    if (n > 100) {
        printf("Erro: O valor maximo para n e 100.\n");
        return 0.0;
    }
    
    float soma = 0;
    
    for (int i = 0; i < n; i++) {
        soma = soma + numeros[i];
    }
    
    return soma / n;
}

int main() {
    printf("Media simples\n");
    
    // Teste 1 Passando 4 notas
    float notas_aluno1[] = {7.5, 8.0, 9.5, 6.0};
    int n1 = 4;
    float media1 = calcular_media(n1, notas_aluno1);
    printf("A media do aluno 1 e: %.2f\n", media1);
    
    // Teste 2 Passando 3 notas
    float notas_aluno2[] = {5.0, 6.5, 5.5};
    int n2 = 3;
    float media2 = calcular_media(n2, notas_aluno2);
    printf("A media do aluno 2 e: %.2f\n", media2);
    
    return 0;
}