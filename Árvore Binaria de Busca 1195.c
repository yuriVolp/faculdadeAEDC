#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    int chave;
    struct arvore *esq;
    struct arvore *dir;
}Arvore;



void imprimePos(Arvore *r){
    if(r != NULL){
        imprimePos(r->esq);
        imprimePos(r->dir);
        printf(" %d", r->chave);
    }
}

void imprimeInf(Arvore *r){
    if(r != NULL){
        imprimePos(r->esq);
        printf(" %d", r->chave);
        imprimePos(r->dir);
    }
}

void imprimePre(Arvore *r){
    if(r != NULL){
        printf(" %d", r->chave);
        imprimePos(r->esq);
        imprimePos(r->dir);
    }
}


Arvore * inserirNo(Arvore *a, int num)
{
      if(a==NULL) //Se não houver nó
      {
            a = (Arvore *) malloc(sizeof(Arvore)); //cria
            a->chave=num; //Insere o valor
            a->esq=NULL; //Cria filho esquerdo
            a->dir=NULL; //Cria filho direito
      }
      else if(a->chave > num) //Se o numero for menor do que a raiz, percorre a esquerda.
      {
            a->esq = inserirNo(a->esq,num);
      }
      else
      {
            a->dir = inserirNo(a->dir,num);
      }
      return a;
}




int main(){
    int c,n,numero;
    Arvore *arvore = NULL;
    
    scanf("%d",&c);
    for(int i=0;i<c;i++){ //quantidade de testes
        scanf("%d",&n);
        //printf("cheguei aqui1");
        for(int j=0;j<n;j++){ //tamanho da arvore
            scanf("%d",&numero);
          //  printf("cheguei aqui");
            arvore = inserirNo(arvore,numero);
        }
        
    }
    
    for(int k=0;k<c;k++){
       
        printf("Case %d:\n",k);
        
        printf("pre. :");
        imprimePre(arvore);
        printf("\n");
        
        printf("in.. :");
        imprimeInf(arvore);
        printf("\n");

        printf("post. :");
        imprimePos(arvore);
        printf("\n");

    }
 
    return 0;
}
