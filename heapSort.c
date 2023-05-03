#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define NUMBER 20000

void insereEmHeap(int m,int v[]){
    int f = m+1;
    while(f > 1 && v[f/2] < v[f]){
        int t = v[f/2];
        v[f/2] = v[f];
        v[f] = t;
        f = f/2; 
    }
}

void heapfy(int m, int v[]){
    int t, f = 2;
    while(f <= m){
        if(f < m && v[f] < v[f+1]) ++f;
        if(v[f/2] >= v[f]) break;
        t = v[f/2];
        v[f/2] = v[f];
        v[f] = t;
        f *= 2;
    }
}


void heapSort(int n, int v[]){
    int m;
    for(m = 1; m < n; m++){
        insereEmHeap(m,v);
    }
    for(m = n; m > 1; m--){
        int t = v[1];
        v[1] = v[m];
        v[m] = t;
        heapfy(m-1,v);
    }
}

int main() {
    
    clock_t inicio, fim;
    double tempo_decorrido;

    struct timeval begin, end;
   
   
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Gera um número aleatório
    int numero_aleatorio[NUMBER ];
    
    
    for(int i=0;i<NUMBER ;i++){
        numero_aleatorio[i] = rand() % 100;
    }

    for(int i=0;i<NUMBER ;i++){
        printf(" %d", numero_aleatorio[i]);
    }
    printf("\n ufa");
    
    
    inicio = clock(); // Marca o início do loop
    gettimeofday(&begin, 0);
    heapSort(NUMBER ,numero_aleatorio);
    // Stop measuring time and calculate the elapsed time
    gettimeofday(&end, 0);
    fim = clock(); // Marca o fim do loop


    for(int i=0;i<NUMBER ;i++){
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
