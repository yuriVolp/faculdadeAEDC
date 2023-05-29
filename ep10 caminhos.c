//Yuri Yoshida Volpato 159518
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000
#define MAX_M 500000

// Estrutura para representar uma rota
typedef struct {
    int a;
    int b;
} Rota;

// Função para encontrar o menor número de horas necessário para ir de C a R sem passar por E
int menor_numero_horas(int N, int M, Rota* rotas, int C, int R, int E) {
    // Criando o grafo de adjacência
    int adj[MAX_N + 1][MAX_N + 1] = { 0 };
    for (int i = 0; i < M; i++) {
        int a = rotas[i].a;
        int b = rotas[i].b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    // Inicializando a fila de busca com a cidade C
    int fila[MAX_N];
    int inicio = 0;
    int fim = 0;
    fila[fim++] = C;

    // Inicializando o vetor de visitados
    int visitados[MAX_N + 1] = { 0 };
    visitados[E] = 1;

    // Inicializando o vetor de distâncias
    int distancia[MAX_N + 1] = { 0 };

    while (inicio < fim) {
        int cidade_atual = fila[inicio++];
        for (int i = 1; i <= N; i++) {
            if (adj[cidade_atual][i] && !visitados[i]) {
                visitados[i] = 1;
                distancia[i] = distancia[cidade_atual] + 1;
                fila[fim++] = i;
                if (i == R) {
                    // Encontrou o caminho até R, retorna a distância
                    return distancia[R];
                }
            }
        }
    }

    // Não foi possível encontrar um caminho até R
    return -1;
}

int main() {
    int N, M, C, R, E;
    Rota rotas[MAX_M];

    while (scanf("%d %d", &N, &M) != EOF) {
        for (int i = 0; i < M; i++) {
            scanf("%d %d", &rotas[i].a, &rotas[i].b);
        }
        scanf("%d %d %d", &C, &R, &E);

        int resultado = menor_numero_horas(N, M, rotas, C, R, E);
        printf("%d\n", resultado);
    }

    return 0;
}