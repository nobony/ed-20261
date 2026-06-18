#include <stdio.h>
#include <time.h>

#define TAM 10
#define TOTAL_ELEMENTOS 100

int main(){
    int matriz[TAM][TAM];
    clock_t inicio, fim;
    double tempo_aninhado, tempo_simples;
    volatile int leitura_temp;

    for (int i = 0; i < TAM; i++){

        for (int j = 0; j < TAM; j++){
            matriz[i][j] = (i * TAM) + j + 1;
        }        
    }

    inicio = clock();
    for (int i = 0; i < TAM; i++){

        for (int j = 0; j < TAM; j++){
            leitura_temp = matriz[i][j];
        }
    }
    fim = clock();
    tempo_aninhado = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    // ABORDAGEM 2: Apenas um laço
    int *ponteiro_matriz = &matriz[0][0]; 
    
    inicio = clock();
    for (int k = 0; k < TOTAL_ELEMENTOS; k++) {
        leitura_temp = ponteiro_matriz[k]; 
        }

    fim = clock();
    tempo_simples = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Resultados de Tempo de Execucao\n");
    printf("1. Abordagem com laco aninhado: %f segundos\n", tempo_aninhado);
    printf("2. Abordagem com laco simples:  %f segundos\n", tempo_simples);

    return 0;
}