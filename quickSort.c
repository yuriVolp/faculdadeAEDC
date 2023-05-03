#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define NUMBER 20000

int separa (int v[], int p, int r) {
   int c = v[r]; // pivô
   int t, j = p;
   for (int k = p; /*A*/ k < r; ++k)
      if (v[k] <= c) {
         t = v[j], v[j] = v[k], v[k] = t;
         ++j; 
      } 
   t = v[j], v[j] = v[r], v[r] = t;
   return j; 
}



void quicksort (int v[], int p, int r)
{
   if (p < r) {                   // 1
      int j = separa (v, p, r);   // 2
      quicksort (v, p, j-1);      // 3
      quicksort (v, j+1, r);      // 4
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

    quicksort(numero_aleatorio, 0, NUMBER);
     // Stop measuring time and calculate the elapsed time
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
