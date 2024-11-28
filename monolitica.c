#include <stdio.h>

int calcula_tamanho(char *str) {
    int tamanho = 0;
    while (str[tamanho] != '\0') {
        tamanho++;
    }
    return tamanho;
}

void verifica_monolitico(char *entrada) {
    int tamanho = calcula_tamanho(entrada);
    int posicao_cerquilha = -1;

    for (int i = 0; i < tamanho; i++) { //encontrando a posicao do #
        if (entrada[i] == '#') {
            posicao_cerquilha = i;
            break;
        }
    }
    // confere se o # existe e divide a string
    if (posicao_cerquilha == -1 || posicao_cerquilha == 0 || posicao_cerquilha == tamanho - 1) { 
        printf("Entrada invalida!\n");
        return;
    }

    for (int i = 0; i < posicao_cerquilha; i++) { //comparando w com wr
        if (entrada[i] != entrada[tamanho - 1 - i]) {
            printf("Nao pertence a linguagem!\n");
            return;
        }
    }

    printf("Pertence a linguagem.\n");
}

int main() {
    char entrada[] = "abc#cba";
    verifica_monolitico(entrada);
    return 0;
}
