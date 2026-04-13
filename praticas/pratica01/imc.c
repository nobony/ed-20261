#include <stdio.h>

void calcular_imc(float peso, float altura) {

    float imc = peso / (altura * altura);
    
    printf("Peso: %.2f kg | Altura: %.2f m\n", peso, altura);
    printf("IMC calculado: %.2f -> ", imc);
    
    if (imc < 18.5) {
        printf("Abaixo do peso\n\n");
    } else if (imc < 25.0) {
        printf("Peso normal\n\n");
    } else if (imc < 30.0) {
        printf("Sobrepeso\n\n");
    } else {
        printf("Obesidade\n\n");
    }
}

int main() {

    printf("Teste imc\n");
    calcular_imc(50.0, 1.70);
    calcular_imc(70.0, 1.75);
    calcular_imc(85.0, 1.70);
    calcular_imc(100.0, 1.65);
    
    return 0;
}