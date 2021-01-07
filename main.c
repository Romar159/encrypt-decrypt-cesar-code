#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv[]) {

    FILE* file = NULL;


    file = fopen("output.txt", "w");
    unsigned char encrypted[] = "VOIXAMBIGUEDUNCOEURQUIAUZEPHIRPREFERELESJATTESDEKIWI";

    fprintf(file, "ORIGINAL MESSAGE: %s\n\n", encrypted);

    int longueur = 1; // max 25 (0 : no encryption)
    for(longueur=1;longueur<26;longueur++) {
            printf("\n\nLOOP %d\n", longueur);
        if (longueur > 25)
            longueur = 25;

        printf("\n\nPASS: %s\n", encrypted);
        unsigned int length = (sizeof(encrypted)/sizeof(char)) - 1;
        printf("LENGTH: %d\n", length);

        unsigned char decrypted[length];

        for (int i=0;i<length;i++) {
            printf("LIGNE/i value: %d -> %d\n", i, encrypted[i]);
            printf("FINAL : %c, FINAL INTEGER: %d\n", (encrypted[i] + longueur), (encrypted[i] + longueur));
            decrypted[i] = encrypted[i] + longueur;
            if (decrypted[i] > 90)
                decrypted[i] = (encrypted[i] + longueur) - 26;
        }
        printf("Encrypted : ");
        fprintf(file, "[SIZE:%d] Encrypted : ", longueur);
        for (int i=0;i<length;i++) {
            printf("%c", decrypted[i]);

            fprintf(file, "%c", decrypted[i]);
        }
            fprintf(file, "\n");
    }
    fclose(file);
    return 0;
}
