// Programa desenvolvido por Prof. Paulo Formigoni
// Converte numeros inteiros at� 32767 em sistema bin�rio

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

// Fun��o para verificar se a entrada � um n�mero v�lido
int validarEntrada(char* entrada) {
    int i = 0;
    while (entrada[i]) {
        if (!isdigit(entrada[i])) {
            return 0; // N�o � um n�mero v�lido
        }
        i++;
    }
    return 1; // � um n�mero v�lido
}

// Fun��o para converter o n�mero inteiro em bin�rio
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

    printf("Digite um n�mero inteiro entre 0 e 32767: ");
    scanf("%s", entrada);

    // Verifica se a entrada � um n�mero v�lido
    if (!validarEntrada(entrada)) {
        printf("Entrada inv�lida. Digite um n�mero inteiro v�lido.\n");
        return 1;
    }

    // Converte a entrada para um n�mero inteiro
    numero = atoi(entrada);

    // Escolhe o n�mero de bits
    if (numero >= -128 && numero <= 127) {
        numBits = 8;
    } else if (numero >= -32768 && numero <= 32767) {
        numBits = 16;
    } else {
        printf("O n�mero est� fora do intervalo suportado (-128 a 127 ou -32768 a 32767).\n");
        return 1;
    }

    printf("Representa��o bin�ria do n�mero %d:\n", numero);
    decimalParaBinario(numero, numBits);

    return 0;
}



