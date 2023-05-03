#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define NUMBER 20000

void intercala(int p, int q,int r, int v[]){
    int i,j,k,*w;
    w = malloc((r-p) * sizeof (int) );
    i = p;
    j = q;
    k = 0;
    while(i < q && j < r){
        if(v[i] <= v[j]){
            w[k++] = v[i++];
        }else{
            w[k++] = v[j++]; 
        }
    }
    while(i < q) w[k++] = v[i++];
    while(j < r) w[k++] = v[j++];
    for(i = p;i < r; i++){
        v[i] = w[i-p];
    }
    free (w);
}

void mergeSort(int p, int r, int v[]){
    if(p < r-1){
        int q = (r+p)/2;
        mergeSort(p,q,v);
        mergeSort(q,r,v);
        intercala(p,q,r,v);

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

    mergeSort(0,NUMBER,numero_aleatorio);

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
