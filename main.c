#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv[]) {

    FILE* file = NULL;
    file = fopen("output.txt", "w");
    unsigned char encrypted[] = "VOIXAMBIGUEDUNCOEURQUIAUZEPHIRPREFERELESJATTESDEKIWI";
    fprintf(file, "ORIGINAL MESSAGE: %s\n\n", encrypted);
    int longueur = 1;
    for(longueur=1;longueur<26;longueur++) {
        if (longueur > 25) longueur = 25;

        unsigned int length = (sizeof(encrypted)/sizeof(char)) - 1;
        unsigned char decrypted[length];

        for (int i=0;i<length;i++) {
            decrypted[i] = encrypted[i] + longueur;
            if (decrypted[i] > 90)
                decrypted[i] = (encrypted[i] + longueur) - 26;
        }

        fprintf(file, "[SIZE:%d] Encrypted : ", longueur);
        for (int i=0;i<length;i++) fprintf(file, "%c", decrypted[i]);
        fprintf(file, "\n");
    }
    fclose(file);
    return 0;
}
