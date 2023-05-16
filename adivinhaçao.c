#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 1000

// Função que verifica se a sequência de operações é uma pilha
int eh_pilha(int n,int n_saida, int *sacola, int *sacola_saida) {
    int final_sacola,eh_pilha=0;
    final_sacola = n;
     for(int i = 2; i>0; i--){
            printf("sacola[%d] ", sacola[i]);
        }
        printf("\n");
        for(int i=0; i<n_saida; i++){
            printf("sacolasaida[%d] ", sacola_saida[i]);
        }
        

    for (int i = 0; i < n_saida; i++) {
        printf("%d %d",sacola_saida[i],sacola[final_sacola]);
        if (sacola_saida[i]==sacola[final_sacola])
        {
            eh_pilha++;
        }
        final_sacola--;
    }
    printf("\nehpilha:%d %d",eh_pilha,n_saida);
    if(eh_pilha == n_saida){
        return 1;
    } 
    return 0;
}

/// Função que verifica se a sequência de operações é uma fila
int eh_fila(int n_saida, int *sacola, int *sacola_saida) {
    int eh_fila=0;
    for (int i = 0; i < n_saida; i++) {
        if (sacola_saida[i]==sacola[i])
        {
            eh_fila++;
        }
    }
    printf("\nehfila:%d %d",eh_fila, n_saida);
    if(eh_fila == n_saida){
        return 1;
    } 
    return 0;
}

// Função que verifica se a sequência de operações é uma fila de prioridade
int eh_fila_prioridade(int n,int n_saida, int *sacola, int *sacola_saida) {
    int eh_fila_prioridade=0;
    for (int i = 0; i < n_saida; i++) {
        for(int j=0;j<n;j++){
            if(sacola_saida[i]==sacola[n]){
                eh_fila_prioridade++;
            }
        }
    }
    //printf("\nehfiladeprioridade:%d",eh_fila_prioridade);
     if(eh_fila_prioridade == n_saida){
        
        return 1;
    } 
    return 0;
}

int main() {
    int n,contador=0,contador_normal=0;
    int sacola[TAM_MAX], sacola_saida[TAM_MAX];
    int operacao, valor;

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {       
            scanf("%d %d", &operacao, &valor);
            if (operacao == 1) {
                sacola[contador_normal] = valor;
                contador_normal++;
            } else if (operacao == 2) {
                sacola_saida[contador] = valor;
                contador++;
            }
        }
        //sacola_saida[contador+1] = -1;
       /* for(int i=0; i<contador_normal; i++){
            printf("[%d] ", sacola[i]);
        }
        printf("\n");
        for(int i=0; i<contador; i++){
            printf("[%d] ", sacola_saida[i]);
        }*/
        
     
        int pilha = eh_pilha(contador_normal,contador, sacola,sacola_saida);
        int fila = eh_fila(contador, sacola,sacola_saida);
        int fila_prioridade = eh_fila_prioridade(contador_normal,contador, sacola,sacola_saida);
        printf("%d %d %d",pilha,fila,fila_prioridade);

        if (pilha==1 && fila==0 && fila_prioridade==0) {
            printf("stack\n");
        } else if (pilha==0 && fila==1 && fila_prioridade==0) {
            printf("queue\n");
        } else if (pilha==0 && fila==0 && fila_prioridade==1) {
            printf("priority queue\n");
        } else if (pilha==0 && fila==0 && fila_prioridade==0) {
            printf("impossible\n");
        } else {
            printf("not sure\n");
        }
        
        contador = 0;
        contador_normal = 0;
        for(int i=0;i<n;i++){
            sacola[i]=0;
            sacola_saida[i]=0;
        }
    }
    
    return 0;
}
