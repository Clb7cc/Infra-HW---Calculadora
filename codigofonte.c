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

    printf("Binario: ");
    for (int i = cont - 1; i >= 0; i--) {
        printf("%d", bin[i]);
    }
    printf("\n");
}

int main() {
    int numf;

    printf("Digite um numero decimal: ");
    scanf("%d", &numf);

    printf("Convertendo o numero %d:\n", numf);

    dec_Bin(numf);

    return 0;
}
