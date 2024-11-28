#include <stdio.h>

int calcula_tamanho(char *str) {
    int tamanho = 0;
    while (str[tamanho] != '\0') {
        tamanho++;
    }
    return tamanho;
}

int verifica_recursivo(char *entrada, int inicio, int fim) {
    if (inicio >= fim) {
        return 1; 
    }
    if (entrada[inicio] != entrada[fim]) {
        return 0;
    }
    return verifica_recursivo(entrada, inicio + 1, fim - 1);
}

void testa_recursivo() {
    char entrada[100];
    printf("Digite a string: ");
    scanf("%s", entrada);

    int tamanho = calcula_tamanho(entrada); 
    int posicao_cerquilha = -1;

    for (int i = 0; i < tamanho; i++) {
        if (entrada[i] == '#') {
            posicao_cerquilha = i;
            break;
        }
    }

    if (posicao_cerquilha == -1 || posicao_cerquilha == 0 || posicao_cerquilha == tamanho - 1) {
        printf("Entrada invalida!\n");
        return;
    }

    if (verifica_recursivo(entrada, 0, posicao_cerquilha - 1)) {
        printf("Pertence a linguagem.\n");
    } else {
        printf("Nao pertence a linguagem!\n");
    }
}

int main() {
    testa_recursivo();
    return 0;
}
