#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define NUMBER 20000

void insertion(int n, int v[]){
    int i,j,x;
    for(j=1; j < n; j++){
        x = v[j];
        for(i = j-1; i >= 0 && v[i] > x;i--){
            v[i+1]=v[i];
        }
        v[i+1]=x;
    }
}


int main() {
    
    clock_t inicio, fim;
    double tempo_decorrido;

    struct timeval begin, end;
 
    
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Gera um número aleatório
    int numero_aleatorio[NUMBER];
    
    
    for(int i=0;i<NUMBER;i++){
        numero_aleatorio[i] = rand() % 100;
    }

    for(int i=0;i<NUMBER;i++){
        printf(" %d", numero_aleatorio[i]);
    }

    inicio = clock(); // Marca o início do loop
    gettimeofday(&begin, 0);

    insertion(NUMBER,numero_aleatorio);

    gettimeofday(&end, 0);
    fim = clock(); // Marca o fim do loop


    printf("\n ufa");
    for(int i=0;i<NUMBER;i++){
        printf(" %d", numero_aleatorio[i]);
    }
    tempo_decorrido = ((double) (fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo decorrido em segundos

    printf("\nTempo decorrido: %.3f segundos", tempo_decorrido);



    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    
    
    printf("\nTime measured: %.3f seconds.\n", elapsed);


    return 0;
}
