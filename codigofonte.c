#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <stdio.h>

void dec_Bin(int numx) {
    int bin[32];
    int cont = 0;

    if (numx == 0) {
        printf("Numero em binario de 0 = 0\n");
        return;
    }
    
    printf("%d para binario: \n", numx);
    while (numx > 0) {
        printf("%d / 2 resto eh %d\n", numx, numx % 2);
        bin[cont] = numx % 2;
        numx = numx / 2;
        cont++;
    }

    printf("Resultado em binario: ");
    for (int i = cont - 1; i >= 0; i--) {
        printf("%d", bin[i]);
    }
    printf("\n\n");
}

void dec_Octal(int numx) {
    int octal[32];
    int cont = 0;

    if (numx == 0) {
        printf("Número em octal 0 = 0\n");
        return;
    }

    printf("%d para octal: \n", numx);
    while (numx > 0) {
        printf("%d / 8 resto eh %d\n", numx, numx % 8);
        octal[cont] = numx % 8;
        numx = numx / 8;
        cont++;
    }

    printf("Resultado em octal: ");
    for (int i = cont - 1; i >= 0; i--) {
        printf("%d", octal[i]);
    }
    printf("\n\n");
}

void dec_Hex(int numx) {
    char hex[32];
    int cont = 0;

    if (numx == 0) {
        printf("Numero em hexadecimal = 0\n");
        return;
    }

    printf("%d para hexadecimal: \n", numx);
    while (numx > 0) {
        int resto = numx % 16;
        if (resto < 10) {
            hex[cont] = resto + '0';
        } else {
            hex[cont] = resto - 10 + 'A';
        }
        printf("%d / 16 resto eh %d; em hexadecimal: %c\n", numx, resto, hex[cont]);
        numx = numx / 16;
        cont++;
    }

    printf("Resultado em Hexadecimal = ");
    for (int i = cont - 1; i >= 0; i--) {
        printf("%c", hex[i]);
    }
    printf("\n");
}


int main() {
    int numf;
    int opc;

    printf("Escolha o tipo de conversão que deseja utilizar:\n");
    printf("0 - Converter para Binário\n");
    printf("1 - Converter para Octal\n");
    printf("2 - Converter para Hexadecimal\n");
    printf("3 - Converter para BCD\n");
    printf("4 - Converter para Complemento a 2 (16 bits)\n");
    printf("5 - Converter real para float\n");
    printf("6 - Converter real para double\n");
    printf("Opção: ");
    scanf("%d", &opc);

    if (opc >= 0 && opc <= 4) {
        printf("Digite um número decimal: ");
        scanf("%d", &numf);
    } else if (opc == 5) {
    } else if (opc == 6) {
    } else {
        printf("Opção incorreta.\n");
        return 1;
    }

    switch (opc) {
        case 0:
            printf("Convertendo %d para binário:\n", numf);
            dec_Bin(numf);
            break;
        case 1:
            printf("Convertendo %d para octal:\n", numf);
            dec_Octal(numf);
            break;
        case 2:
            printf("Convertendo %d para hexadecimal:\n", numf);
            dec_Hex(numf);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        default:
            printf("Opção incorreta.\n");
            break;
    }

    return 0;
}
