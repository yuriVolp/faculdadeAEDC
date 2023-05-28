//Yuri Yoshida Volpato 159518 EP09 - Mapa do Meistre
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct matriz
{
    int jaPassei; // Indica se a célula da matriz já foi visitada durante a exploração
    char simboloMapa; // O símbolo presente na célula da matriz
}matriz;


int validarAlturaLargura(int m){
    if(m>0 && m<100){
        return 0; // Retorna 0 se a altura/largura for válida
    }
    return -1; // Retorna -1 se a altura/largura for inválida
}

int possuiBau(matriz **m, int altura, int largura){
    for(int i=0; i<altura; i++){
        for(int j=0; j<largura; j++){
            if(m[i][j].simboloMapa == '*'){
                return 0; // Retorna 0 se houver um bau na matriz
            }
        }
    }
    return -1; // Retorna -1 se não houver um bau na matriz
}

int validaBordas(char simbolo, int alturaMax, int larguraMax, int alturaAtual, int larguraAtual)
{
    // Verifica se a posição atual está nas bordas da matriz
    if (alturaAtual == 0 && simbolo == '^'){return -1;} // Retorna -1 se estiver na borda superior e o símbolo for '^'
    else if(alturaAtual == alturaMax && simbolo =='v'){return -1;} // Retorna -1 se estiver na borda inferior e o símbolo for 'v'
    else if(larguraAtual == 0 && simbolo == '<'){return -1;} // Retorna -1 se estiver na borda esquerda e o símbolo for '<'
    else if(larguraAtual == larguraMax && simbolo == '>'){return -1;}// Retorna -1 se estiver na borda direita e o símbolo for '>'
    else return 0; // Retorna 0 se a posição atual não estiver nas bordas
}





int percorreDireita(matriz **m, int alturaMax, int larguraMax, int alturaAtual, int larguraAtual){
    // Percorre para a direita a partir da posição atual 
    for(int i=larguraAtual+1;i<larguraMax;i++){
        if( m[alturaAtual][i].simboloMapa != '.'){
            return i; // Retorna a coluna encontrada
        }
    }
    return -1; // Retorna -1 se não encontrar nenhum simbolo para a direita
}


int percorreEsquerda(matriz **m, int alturaMax, int larguraMax, int alturaAtual, int larguraAtual){
   // Percorre para a esquerda a partir da posição atual
    for(int i=larguraAtual-1;i>=0;i--){
        if( m[alturaAtual][i].simboloMapa != '.'){
            return i; // Retorna a coluna encontrada
        }
    }
    return -1; // Retorna -1 se não encontrar nenhum simbolo para a esquerda
}

int percorreBaixo(matriz **m, int alturaMax, int larguraMax, int alturaAtual, int larguraAtual){
    // Percorre para baixo a partir da posição atual 
    for(int i=alturaAtual+1;i<alturaMax;i++){
        if( m[i][larguraAtual].simboloMapa != '.'){
            return i;// Retorna a linha encontrada
        }
    }
    return -1;// Retorna -1 se não encontrar nenhum simbolo para baixo
}

int percorreCima(matriz **m, int alturaMax, int larguraMax, int alturaAtual, int larguraAtual){
   // Percorre para cima a partir da posição atual 
    for(int i=alturaAtual-1;i>=0;i--){
        if( m[i][larguraAtual].simboloMapa != '.'){
            return i;// Retorna a linha encontrada
        }
    }
    return -1;// Retorna -1 se não encontrar nenhuma simbolo para cima
}



char percorrerMapa(matriz **m, int altura, int largura, int i, int j){
   // Verifica se o mapa possui um bau
    if(possuiBau(m,altura,largura) == -1){ return '!';}// Retorna '!' se não houver um bau na matriz
    char simbolo = m[i][j].simboloMapa;
    if(m[i][j].jaPassei == 1){return '!';}// Retorna '!' se a célula já foi visitada antes
    if(validaBordas(simbolo,altura,largura,i,j) == -1){return '!';}// Retorna '!' se o simbolo atual estiver nas bordas e for invalido
    m[i][j].jaPassei = 1;// Marca a célula atual como visitada
    int larguraEncontrada,alturaEncontrada;
    switch (simbolo)
    {
    case '*':
        return '*';// Retorna '*' se o bau for encontrado
        break;
    case '>':
        larguraEncontrada = percorreDireita(m,altura,largura,i,j);
        if(larguraEncontrada == -1){return '!';}
        return percorrerMapa(m,altura,largura,i,larguraEncontrada); // chama a recursao
    case '<':       
        larguraEncontrada = percorreEsquerda(m,altura,largura,i,j);
        if(larguraEncontrada == -1){return '!';}
        return percorrerMapa(m,altura,largura,i,larguraEncontrada);
    case 'v':
        alturaEncontrada = percorreBaixo(m,altura,largura,i,j);
        if(alturaEncontrada == -1){return '!';}
        return percorrerMapa(m,altura,largura,alturaEncontrada,j);
    case '^':
        alturaEncontrada = percorreCima(m,altura,largura,i,j);
        if(alturaEncontrada == -1){return '!';}
        return percorrerMapa(m,altura,largura,alturaEncontrada,j);
    default:
        return '!';
        break;
    }
}

void imprimirMapa(matriz **m, int altura, int largura){
     for(int i=0; i<altura; i++){
        for(int j=0; j<largura; j++){
            printf("%c ",m[i][j].simboloMapa);
        }
        printf("\n");
    }
}

int main(){
    int altura,largura;
    char resultado;
   
    scanf("%i",&largura);
    scanf("%i",&altura);
 
    //altura = 5;
    //largura = 7;
    if(validarAlturaLargura(altura) == -1){
        printf("\nerro de altura!");
        return -1;
    }
    if (validarAlturaLargura(largura) == -1){
        printf("\nerro de largura!");
        return -1;
    } 
    
    matriz **m = (matriz **)malloc(altura * sizeof(matriz *));
    for (int i = 0; i < altura; i++) {
        m[i] = (matriz *)malloc(largura * sizeof(matriz));
    }
    
    //looping com altura 
    for(int i=0; i<altura; i++){
        for(int j=0; j<largura; j++){
            m[i][j].jaPassei = 0;
           // m[i][j].simboloMapa = '.' ;
           // fgets(m[i][j].simboloMapa,1,stdin);
            scanf(" %c", &m[i][j].simboloMapa);
        }
    }


    //imprimirMapa(m,altura,largura);
    resultado = percorrerMapa(m,altura,largura,0,0);
    printf("%c", resultado);
    printf("\n");

    // Liberar a memória alocada para a matriz
    for (int i = 0; i < altura; i++) {
        free(m[i]);
    }


    free(m);
    return 0;
}