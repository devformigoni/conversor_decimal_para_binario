// Programa desenvolvido por Prof. Paulo Formigoni
// Converte numeros inteiros até 32767 em sistema binário

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

// Função para verificar se a entrada é um número válido
int validarEntrada(char* entrada) {
    int i = 0;
    while (entrada[i]) {
        if (!isdigit(entrada[i])) {
            return 0; // Não é um número válido
        }
        i++;
    }
    return 1; // É um número válido
}

// Função para converter o número inteiro em binário
void decimalParaBinario(int numero, int numBits) {
    int i, j;
    for (i = numBits - 1; i >= 0; i--) {
        j = numero >> i;
        if (j & 1)
            printf("1");
        else
            printf("0");
    }
    printf(" (%d bits)\n", numBits);
}

int main() {
	setlocale(LC_ALL, "");
    char entrada[50];
    int numero;
    int numBits;

    printf("Digite um número inteiro entre 0 e 32767: ");
    scanf("%s", entrada);

    // Verifica se a entrada é um número válido
    if (!validarEntrada(entrada)) {
        printf("Entrada inválida. Digite um número inteiro válido.\n");
        return 1;
    }

    // Converte a entrada para um número inteiro
    numero = atoi(entrada);

    // Escolhe o número de bits
    if (numero >= -128 && numero <= 127) {
        numBits = 8;
    } else if (numero >= -32768 && numero <= 32767) {
        numBits = 16;
    } else {
        printf("O número está fora do intervalo suportado (-128 a 127 ou -32768 a 32767).\n");
        return 1;
    }

    printf("Representação binária do número %d:\n", numero);
    decimalParaBinario(numero, numBits);

    return 0;
}



