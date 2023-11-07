#include <stdio.h>
#include <string.h>

#define NUM_PLAYERS 11

struct Player {
    char playerName[31];
    char playerPosition;
    int playerStrength;
};

float calculateTeamForce(struct Player players[]) {
    int G = 0, L1 = 0, L2 = 0, Z1 = 0, Z2 = 0, V1 = 0, V2 = 0, M1 = 0, M2 = 0, A1 = 0, A2 = 0;

    for (int i = 0; i < NUM_PLAYERS; i++) {
        switch (players[i].playerPosition) {
            case 'G':
                G = players[i].playerStrength;
                break;
            case 'L':
                if (L1 == 0)
                    L1 = players[i].playerStrength;
                else
                    L2 = players[i].playerStrength;
                break;
            case 'Z':
                if (Z1 == 0)
                    Z1 = players[i].playerStrength;
                else
                    Z2 = players[i].playerStrength;
                break;
            case 'V':
                if (V1 == 0)
                    V1 = players[i].playerStrength;
                else
                    V2 = players[i].playerStrength;
                break;
            case 'M':
                if (M1 == 0)
                    M1 = players[i].playerStrength;
                else
                    M2 = players[i].playerStrength;
                break;
            case 'A':
                if (A1 == 0)
                    A1 = players[i].playerStrength;
                else
                    A2 = players[i].playerStrength;
                break;
        }
    }

    return (8 * G + 10 * (L1 + L2) + 5 * (Z1 + Z2) + 8 * (V1 + V2) + 11 * (M1 + M2) + 12 * (A1 + A2)) / 100.0;
}

int main() {
    struct Player teamOne[NUM_PLAYERS], teamTwo[NUM_PLAYERS];
    char teamNameOne[31], teamNameTwo[31];

    // Lendo os dados do primeiro time
    fgets(teamNameOne, 31, stdin);
    teamNameOne[strcspn(teamNameOne, "\n")] = 0; // Remover o caractere de nova linha, se presente
    for (int i = 0; i < NUM_PLAYERS; i++) {
        scanf("%[^;];%c;%d\n", teamOne[i].playerName, &teamOne[i].playerPosition, &teamOne[i].playerStrength);
    }

    // Lendo os dados do segundo time
    fgets(teamNameTwo, 31, stdin);
    teamNameTwo[strcspn(teamNameTwo, "\n")] = 0; // Remover o caractere de nova linha, se presente
    for (int i = 0; i < NUM_PLAYERS; i++) {
        scanf("%[^;];%c;%d\n", teamTwo[i].playerName, &teamTwo[i].playerPosition, &teamTwo[i].playerStrength);
    }

    // Calculando as forças de cada time
    float forceOne = calculateTeamForce(teamOne);
    float forceTwo = calculateTeamForce(teamTwo);

    // Exibindo os resultados
    printf("%s: %.2f de forca\n", teamNameOne, forceOne);
    printf("%s: %.2f de forca\n", teamNameTwo, forceTwo);

    // Comparando as forças e exibindo o time mais forte
    if (forceOne > forceTwo) {
        printf("%s eh mais forte\n", teamNameOne);
    } else if (forceTwo > forceOne) {
        printf("%s eh mais forte\n", teamNameTwo);
    } else {
        printf("Os times sao igualmente fortes\n");
    }

    return 0;
}
