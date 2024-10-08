//Feito por Caio Lima Bezerra
//Link do Github: https://github.com/Clb7cc/Infra-HW---Calculadora
//
//Relatório dos Commits :
//Adição da função para transformar número decimal para binário (na void e na main também) - 23/08/2023 ás 14:31.
//Adição da função para transformar número decimal para octal (na void e na main também) - 23/08/2023 ás 19:15.
//Adição da função para transformar número decimal para hexadecimal (na void e na main também) - 28/08/2023 ás 16:40.
//Adição da função para transformar número decimal para BCD (na void e na main também) - 28/08/2023 ás 17:22.
//Adição da função para transformar a complemento a 2 (na void e na main também) - 28/08/2023 ás 19:01.
//Adição da função para converter real em decimal para float e double (na void e na main também) - 28/08/2023 ás 22:08.
//Revisão das funções e adição da descrição dos commits - 29/08/2023 ás 11:23.
//
//Data de Começo : 23/08/2024
//Data de Finalização : 29/08/2024

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void dec_BCD(int numx) {
    printf("Número em BCD: ");
    int temp = numx;
    int digitos[32];
    int cont = 0;

    while (temp > 0) {
        digitos[cont] = temp % 10;
        temp = temp / 10;
        cont++;
    }

    for (int i = cont - 1; i >= 0; i--) {
        int digito = digitos[i];
        for (int j = 3; j >= 0; j--) {
            printf("%d", (digito >> j) & 1);
        }
        printf(" ");
    }
    printf("\n");
}

void dec_Comp2(int numx) {
    unsigned short bin = (unsigned short)numx; 
    char bin_arr[16]; 
    int b = 0;

    printf("Número: %d\n", numx);

    printf("Número em binário (16 bits): ");
    for (int i = 15; i >= 0; i--) {
        printf("%d", (bin >> i) & 1);
        bin_arr[b] = ((bin >> i) & 1) + '0'; 
        b++;
    }
    printf("\n");

    printf("Complemento a 1: ");
    for (int i = 0; i < 16; i++) {
        bin_arr[i] = (bin_arr[i] == '0') ? '1' : '0'; 
        printf("%c", bin_arr[i]);
    }
    printf("\n");

    printf("Complemento a 2: ");
    int soma = 1; 
    for (int i = 15; i >= 0; i--) {
        if (bin_arr[i] == '1' && soma == 1) {
            bin_arr[i] = '0'; 
        } else if (bin_arr[i] == '0' && soma == 1) {
            bin_arr[i] = '1';
            soma = 0;
        }
    }

    for (int i = 0; i < 16; i++) {
        printf("%c", bin_arr[i]);
    }
    printf("\n");
}

void float_Representation(float numx) {
    unsigned int* ptr = (unsigned int*)&numx;
    unsigned int bits = *ptr;

    printf("Representação de %.2f como float:\n", numx);
    printf("Sinal: %d\n", (bits >> 31) & 1);
    printf("Expoente: ");
    for (int i = 30; i >= 23; i--) {
        printf("%d", (bits >> i) & 1);
    }
    printf("\nFrações: ");
    for (int i = 22; i >= 0; i--) {
        printf("%d", (bits >> i) & 1);
    }
    printf("\n");
}

void double_Rpr(double numx) {
    unsigned long long* ptr = (unsigned long long*)&numx;
    unsigned long long bits = *ptr;

    printf("Representação de %.2lf como double:\n", numx);
    printf("Sinal: %d\n", (int)((bits >> 63) & 1));
    printf("Expoente: ");
    for (int i = 62; i >= 52; i--) {
        printf("%d", (int)((bits >> i) & 1));
    }
    printf("\nFrações: ");
    for (int i = 51; i >= 0; i--) {
        printf("%d", (int)((bits >> i) & 1));
    }
    printf("\n");
}

int main() {

    int numf;
    int opc;
    float num_float;
    double num_double;

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
        printf("Digite um número real (float): ");
        scanf("%f", &num_float);
    } else if (opc == 6) {
        printf("Digite um número real (double): ");
        scanf("%lf", &num_double);
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
            printf("Convertendo %d para BCD:\n", numf);
            dec_BCD(numf);
            break;
        case 4:
            printf("Convertendo %d para complemento a 2 (16 bits):\n", numf);
            dec_Comp2(numf);
            break;
        case 5:
            float_Representation(num_float);
            break;
        case 6:
            double_Rpr(num_double);
            break;
        default:
            printf("Opção incorreta.\n");
            break;
    }

    return 0;
}
