//Yuri Volpato 159518
#include <stdio.h>
#include <string.h>

int main() {
    char nome[100001];
    fgets(nome, sizeof(nome), stdin);

    // Verifica se a sequência "zelda" (insensível a maiúsculas/minúsculas) aparece em qualquer parte da string
    if (strcasestr(nome, "zelda") != NULL) {
        printf("Link Bolado\n");
    } else {
        printf("Link Tranquilo\n");
    }

    return 0;
}