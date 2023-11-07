#include <stdio.h>
int somaVetores(int valores[], int tamanho) {
    while (tamanho > 1) {
        for (int i = 0; i < tamanho - 1; i++) {
            valores[i] = valores[i] + valores[i + 1];
        } 
        tamanho--;  
        for (int i = 0; i < tamanho; i++) {
            printf("%d", valores[i]);
            if (i < tamanho - 1) {
                printf(" "); 
            }
        }
        printf("\n");
    }
}

int main() {
    int conjunto_de_valores[10];
    int numero_de_elementos = 10;


    for (int i = 0; i < numero_de_elementos; i++) {
        scanf("%d", &conjunto_de_valores[i]);
    }

   
    
    for (int i = 0; i < numero_de_elementos; i++) {
        printf("%d", conjunto_de_valores[i]);
        if (i < numero_de_elementos - 1) {
            printf(" "); 
        }
    }
    printf("\n");

    somaVetores(conjunto_de_valores, numero_de_elementos);

    return 0;
}