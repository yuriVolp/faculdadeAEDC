//Yuri Yoshida Volpato 159518 Ex: Lista de amigos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char nome[50];
    struct no *prox;
} No;

// função para inserir um novo nó na lista
void inserir(No **inicio, char nome[]) {
    No *novo = (No*) malloc(sizeof(No)); // aloca um novo nó na memória
    strcpy(novo->nome, nome); // copia o nome para o campo nome do novo nó
    novo->prox = NULL; // define o próximo nó como NULL
    
    if (*inicio == NULL) { // caso a lista esteja vazia
        *inicio = novo; // o início da lista é o novo nó
    } else { // caso contrário, percorre a lista até o final e insere o novo nó lá
        No *aux = *inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

// função para imprimir os nomes da lista
void imprimir(No *inicio) {
    No *aux = inicio;
    while (aux != NULL) {
        printf("%s ", aux->nome);
        aux = aux->prox;
    }
    printf("\n");
}

// função para separar uma string em substrings usando um delimitador
void separar(char string[], char delimitador[], No **lista) {
    char *nome = strtok(string, delimitador); // a função strtok é usada para separar a string em substrings
    while (nome != NULL) { // enquanto houver substrings
        inserir(lista, nome); // insere a substring na lista
        nome = strtok(NULL, delimitador); // avança para a próxima substring
    }
}

// função para encontrar o último nó da lista
struct no* ultimo(struct no* lista) {
    if (lista == NULL) { // caso a lista esteja vazia
        return NULL;
    }

    struct no* atual = lista;
    while (atual->prox != NULL) { // percorre a lista até o último nó
        atual = atual->prox;
    }
    return atual;
}

// função para juntar duas listas em um determinado nó indicado
void juntar(No *lista1, No *lista2, char nome_indicado[]){
    No *atual = lista1;
    No *anterior = NULL;
    if(lista1 != NULL && lista2 != NULL){ // caso as duas listas não estejam vazias
        // percorre a lista 1 até encontrar o nome indicado ou o final da lista
        while(atual != NULL && strcmp(atual->nome, nome_indicado) != 0){
            anterior = atual;
            atual = atual->prox;
        }
        // se não encontrou o nome indicado, adiciona toda a lista 2 no final da lista 1
        if(atual == NULL){
            anterior->prox = lista2;
        }else{ // caso contrário, adiciona a lista 2 antes do nome indicado
            No *ultimo2 = ultimo(lista2);
            ultimo2->prox = atual; 
            anterior->prox = lista2;
        }
    }
}

int main() {
    char nomes[50],nomes_novos[50] ,delimitador[2] = " ", nome_indicado[20];
    No *lista = NULL;
    No *lista_novos_amigos = NULL;
  
  
    // lista de amigos inicial
    fgets(nomes, sizeof(nomes), stdin);
    nomes[strcspn(nomes, "\n")] = '\0'; // Remove o caractere de nova linha
    separar(nomes, delimitador, &lista);


    //lista nova de amigos 
    fgets(nomes_novos, sizeof(nomes_novos), stdin);
    nomes_novos[strcspn(nomes_novos, "\n")] = '\0'; // Remove o caractere de nova linha
    separar(nomes_novos, delimitador, &lista_novos_amigos);
    

    //indicação
    fgets(nome_indicado, sizeof(nome_indicado), stdin);
    nome_indicado[strcspn(nome_indicado, "\n")] = '\0'; // Remove o caractere de nova linha
 
    juntar(lista, lista_novos_amigos,nome_indicado);
    
    
    
    imprimir(lista);
    
    return 0;
}

