#include <stdio.h>
#include <stdlib.h>

void dec_Bin(int numx) {
    int bin[32];
    int cont = 0;
    
    while (numx > 0) {
        bin[cont] = numx % 2;
        numx = numx / 2;
        cont++;
    }

    printf("Número em binário: ");
    for (int i = cont - 1; i >= 0; i--) {
        printf("%d", bin[i]);
    }
    printf("\n");
}

void dec_Octal(int numx) {
    int octal[32];
    int cont = 0;

    while (numx > 0) {
        octal[cont] = numx % 8;
        numx = numx / 8;
        cont++;
    }

    printf("Número em octal: ");
    for (int i = cont - 1; i >= 0; i--) {
        printf("%d", octal[i]);
    }
    printf("\n");
}

int main() {
    int numf;
    int opc;

    printf("Digite um número decimal: ");
    scanf("%d", &numf);

    printf("Escolha o tipo de conversão que deseja utilizar:\n");
    printf("0 - Converter para Binário\n");
    printf("1 - Converter para Octal\n");
    printf("Opção: ");
    scanf("%d", &opc);

    if(opc == 0){
        printf("Convertendo %d para binário:\n", numf);
        dec_Bin(numf);
    } else if(opc == 1){
        printf("Convertendo %d para octal:\n", numf);
        dec_Octal(numf);
    } else {
        printf("Opção incorreta.\n");
    }

    return 0;
}
