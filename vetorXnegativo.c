#include <stdio.h>

int main() {
    int X[10];

    // Leitura do vetor X
    for (int i = 0; i < 10; i++) {
        scanf("%d", &X[i]);
    }

    // Substituição de valores nulos e negativos por 1
    for (int i = 0; i < 10; i++) {
        if (X[i] <= 0) {
            X[i] = 1;
        }
    }

    // Impressão do vetor X resultante
    for (int i = 0; i < 10; i++) {
        printf("X[%d] = %d\n", i, X[i]);
    }

    return 0;
}