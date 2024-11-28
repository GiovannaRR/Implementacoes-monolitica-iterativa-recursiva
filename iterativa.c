#include <stdio.h>

int calcula_tamanho(char *str) { // calcula o tamano da string
    int tamanho = 0;
    while (str[tamanho] != '\0') {
        tamanho++;
    }
    return tamanho;
}

int verifica_iterativo(char *entrada) {
    int tamanho = calcula_tamanho(entrada);
    int posicao_cerquilha = -1;

    for (int i = 0; i < tamanho; i++) { 
        if (entrada[i] == '#') {
            posicao_cerquilha = i;
            break;
        }
    }

    if (posicao_cerquilha == -1 || posicao_cerquilha == 0 || posicao_cerquilha == tamanho - 1) {
        return 0;
    }

    int inicio = 0;
    int fim = tamanho - 1;
    while (inicio < posicao_cerquilha) {
        if (entrada[inicio] != entrada[fim]) {
            return 0;
        }
        inicio++;
        fim--;
    }
    return 1;
}

void testa_iterativo() {
    char entrada[100];
    printf("Digite a string: ");
    scanf("%s", entrada);

    if (verifica_iterativo(entrada)) {
        printf("Pertence a linguagem!\n");
    } else {
        printf("Nao pertence a linguagem!\n");
    }
}

int main() {
    testa_iterativo();
    return 0;
}
