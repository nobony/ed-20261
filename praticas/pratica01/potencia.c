#include <stdio.h>

int calcular_potencia(int base, int expoente) {
    int resultado = 1;
    
    for (int i = 0; i < expoente; i++) {
        resultado = resultado * base;
    }
    
    return resultado;
}

int main() {

    printf("--- TESTES DE POTENCIA ---\n");
    printf("2 elevado a 3 e: %d\n", calcular_potencia(2, 3));
    printf("5 elevado a 2 e: %d\n", calcular_potencia(5, 2));
    printf("10 elevado a 4 e: %d\n", calcular_potencia(10, 4));
    
    return 0;
}