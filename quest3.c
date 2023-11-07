#include <stdio.h>
#include <string.h>

int main() {
    int A[4][4], B[4][4], result[4][4];
    char operacao[5];
   
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    
    
    scanf("%s", operacao);
    
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (strcmp(operacao, "soma") == 0) {
                result[i][j] = A[i][j] + B[i][j];
            } else if (strcmp(operacao, "sub") == 0) {
                result[i][j] = A[i][j] - B[i][j];
            } else if (strcmp(operacao, "mult") == 0) {
                result[i][j] = 0;
                for (int k = 0; k < 4; k++) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%4d", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}