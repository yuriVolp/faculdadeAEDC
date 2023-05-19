//Yuri Volpato 159518
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 53

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Cria um novo nó com o dado fornecido
struct Node* criarNo(char data) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    novoNo->data = data;
    novoNo->left = NULL;
    novoNo->right = NULL;
    return novoNo;
}

// Busca o índice de um valor no array a partir de um intervalo
int buscarIndice(char arr[], int inicio, int fim, char valor) {
    for (int i = inicio; i <= fim; i++) {
        if (arr[i] == valor)
            return i;
    }
    return -1;
}

// Constrói a árvore binária a partir dos percursos infixo e prefixo
struct Node* construirArvore(char in[], char pre[], int inicio, int fim) {
    static int preIndex = 0;

    if (inicio > fim)
        return NULL;

    struct Node* novoNo = criarNo(pre[preIndex++]);

    if (inicio == fim)
        return novoNo;

    int inIndex = buscarIndice(in, inicio, fim, novoNo->data);

    novoNo->left = construirArvore(in, pre, inicio, inIndex - 1);
    novoNo->right = construirArvore(in, pre, inIndex + 1, fim);

    return novoNo;
}

// Realiza o percurso posfixo da árvore
void percursoPosfixo(struct Node* no) {
    if (no == NULL)
        return;

    percursoPosfixo(no->left);
    percursoPosfixo(no->right);
    printf("%c", no->data);
}

int main() {
    int C;
    scanf("%d", &C);

    while (C--) {
        int N;
        scanf("%d", &N);

        char pre[MAX], in[MAX];
        scanf("%s %s", pre, in);

        struct Node* pilha[MAX];
        int topo = -1;

        // Cria o nó raiz da árvore com o primeiro elemento do percurso prefixo
        struct Node* raiz = criarNo(pre[0]);
        pilha[++topo] = raiz;

        // Percorre os elementos restantes do percurso prefixo
        for (int i = 1, j = 0; i < N; i++) {
            struct Node* temp = NULL;

            // Popula a subárvore direita do último nó desempilhado
            // até encontrar o próximo elemento do percurso infixo
            while (topo != -1 && pilha[topo]->data == in[j]) {
                temp = pilha[topo--];
                j++;
            }

            // Cria um novo nó com o elemento atual do percurso prefixo
            struct Node* novoNo = criarNo(pre[i]);

            // Verifica se o último nó desempilhado possui uma subárvore direita vazia
            // Caso possua, o novo nó será adicionado como a subárvore direita do último nó desempilhado
            // Caso contrário, o novo nó será adicionado como a subárvore esquerda do último nó desempil
