#include <stdio.h>
#include <string.h>

#define NUM_PLAYERS 11

struct Player {
    char name[31];
    char position;
    int strength;
};

float calculateForce(struct Player players[]) {
    int G = 0, L1 = 0, L2 = 0, Z1 = 0, Z2 = 0, V1 = 0, V2 = 0, M1 = 0, M2 = 0, A1 = 0, A2 = 0;

    for (int i = 0; i < NUM_PLAYERS; i++) {
        switch (players[i].position) {
            case 'G':
                G = players[i].strength;
                break;
            case 'L':
                if (L1 == 0)
                    L1 = players[i].strength;
                else
                    L2 = players[i].strength;
                break;
            case 'Z':
                if (Z1 == 0)
                    Z1 = players[i].strength;
                else
                    Z2 = players[i].strength;
                break;
            case 'V':
                if (V1 == 0)
                    V1 = players[i].strength;
                else
                    V2 = players[i].strength;
                break;
            case 'M':
                if (M1 == 0)
                    M1 = players[i].strength;
                else
                    M2 = players[i].strength;
                break;
            case 'A':
                if (A1 == 0)
                    A1 = players[i].strength;
                else
                    A2 = players[i].strength;
                break;
        }
    }

    return (8 * G + 10 * (L1 + L2) + 5 * (Z1 + Z2) + 8 * (V1 + V2) + 11 * (M1 + M2) + 12 * (A1 + A2)) / 100.0;
}

int main() {
    struct Player team1[NUM_PLAYERS], team2[NUM_PLAYERS];
    char teamName1[31], teamName2[31];

    // Lendo os dados do primeiro time
    fgets(teamName1, 31, stdin);
    teamName1[strcspn(teamName1, "\n")] = 0; // Remover o caractere de nova linha, se presente
    for (int i = 0; i < NUM_PLAYERS; i++) {
        scanf("%[^;];%c;%d\n", team1[i].name, &team1[i].position, &team1[i].strength);
    }

    // Lendo os dados do segundo time
    fgets(teamName2, 31, stdin);
    teamName2[strcspn(teamName2, "\n")] = 0; // Remover o caractere de nova linha, se presente
    for (int i = 0; i < NUM_PLAYERS; i++) {
        scanf("%[^;];%c;%d\n", team2[i].name, &team2[i].position, &team2[i].strength);
    }

    // Calculando as forças de cada time
    float force1 = calculateForce(team1);
    float force2 = calculateForce(team2);

    // Exibindo os resultados
    printf("%s: %.2f de forca\n", teamName1, force1);
    printf("%s: %.2f de forca\n", teamName2, force2);

    // Comparando as forças e exibindo o time mais forte
    if (force1 > force2) {
        printf("%s eh mais forte\n", teamName1);
    } else if (force2 > force1) {
        printf("%s eh mais forte\n", teamName2);
    } else {
        printf("Os times sao igualmente fortes\n");
    }

    return 0;
}