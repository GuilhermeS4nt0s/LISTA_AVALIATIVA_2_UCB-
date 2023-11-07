#include <stdio.h>

int sumArrays(int values[], int size) {
    while (size > 1) {
        for (int i = 0; i < size - 1; i++) {
            values[i] = values[i] + values[i + 1];
        } 
        size--;  
        for (int i = 0; i < size; i++) {
            printf("%d", values[i]);
            if (i < size - 1) {
                printf(" "); 
            }
        }
        printf("\n");
    }
}

int main() {
    int valueArray[10];
    int numElements = 10;

    for (int i = 0; i < numElements; i++) {
        scanf("%d", &valueArray[i]);
    }
    
    for (int i = 0; i < numElements; i++) {
        printf("%d", valueArray[i]);
        if (i < numElements - 1) {
            printf(" "); 
        }
    }
    printf("\n");

    sumArrays(valueArray, numElements);

    return 0;
}
