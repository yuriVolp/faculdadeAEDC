//Yuri Yoshida Volpato 159518 - Lista de chamadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char nome[50];
    struct Node* prox; // ponteiro para o próximo nó da lista
};

// função que insere um novo nó no início da lista
void insere(struct Node** inicio, char* nome) {
    struct Node* novo = (struct Node*)malloc(sizeof(struct Node)); // aloca memória para o novo nó
    strcpy(novo->nome, nome); // copia o nome para o campo "nome" do novo nó
    novo->prox = *inicio; // faz o novo nó apontar para o que antes era o primeiro nó da lista
    *inicio = novo; // faz o ponteiro de início apontar para o novo nó
}

// função que ordena a lista em ordem alfabética
void ordena(struct Node** inicio) {
    int trocou;
    struct Node* atual;
    struct Node* anterior = NULL;

    do {
        trocou = 0;
        atual = *inicio;

        while (atual->prox != anterior) { // percorre a lista até o penúltimo nó
            if (strcmp(atual->nome, atual->prox->nome) > 0) { // compara o nome do nó atual com o nome do próximo nó
                char temp[50];
                strcpy(temp, atual->nome);
                strcpy(atual->nome, atual->prox->nome); // troca o nome do nó atual com o nome do próximo nó
                strcpy(atual->prox->nome, temp);
                trocou = 1;
            }
            atual = atual->prox;
        }
        anterior = atual;
    } while (trocou);
}

//libera a lista
void libera_lista(struct Node** inicio) {
    struct Node* atual = *inicio;
    while (atual != NULL) {
        struct Node* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    *inicio = NULL;
}


// função que busca um nó na lista pela sua posição
int busca(struct Node* inicio, int k) {
    int i = 1;
    struct Node* atual = inicio;

    while (atual != NULL && i < k) { // percorre a lista até encontrar o nó na posição k
        atual = atual->prox;
        i++;
    }

    if (atual == NULL) { // caso a posição k seja maior que o tamanho da lista
        // printf("Posicao invalida\n");
        return -1;
    } else { // caso a posição k seja válida
        printf("%s\n", atual->nome);
        return 0;
    }
}

int main() {
    struct Node* inicio = NULL;
    int n, k, i;
    char nome[50];

    scanf("%d %d", &n, &k);

    for (i = 0; i < n; i++) {
        scanf("%s", nome);
        insere(&inicio, nome); // insere um novo nó com o nome lido no início da lista
    }

    ordena(&inicio); // ordena a lista em ordem alfabética

    busca(inicio, k); // busca o nó na posição k da lista

    libera_lista(&inicio);// libera a lista


    return 0;
}
