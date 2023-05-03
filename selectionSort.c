#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define NUMBER 20000



void selection(int n, int v[]){
    int x, j, min,i;
    for(i=0; i < n-1; i++){
        min = i;
        for(j = i+1; j < n; j++){
            if(v[j] < v[min]){
                min = j;
            }
        }
        x = v[i];
        v[i] = v[min];
        v[min] = x;
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
    printf("\n ufa");

    inicio = clock(); // Marca o início do loop
    gettimeofday(&begin, 0);

    selection(NUMBER,numero_aleatorio);

    gettimeofday(&end, 0);
    fim = clock(); // Marca o fim do loop


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
