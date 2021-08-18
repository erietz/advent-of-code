#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validPassword(char *string) {

    char stringCopy[500];
    strcpy(stringCopy, string);

    char *min = strtok(stringCopy, "-");
    char *max  = strtok(NULL, " ");
    char *character  = strtok(NULL, ":");
    char *password  = strtok(NULL, " ");
    /* printf("%s %s %s %s\n", min, max, character, password); */

    char *ptr;

    long minInt = strtol(min, &ptr, 10);
    long maxInt = strtol(max, &ptr, 10);
    char letter = *character;

    int occurances = 0;
    for (int i=0; i<strlen(password); i++) {
        if (password[i] == letter) {
            occurances += 1;
        }
    }

    if (occurances >= minInt && occurances <= maxInt) {
        return 1;
    } else {
        return 0;
    }
}

int main() {

    char *fileName = "./passwords.txt";
    FILE *infile = fopen(fileName, "r");

    if (!infile) {
        printf("could not open %s\n", fileName);
        return -1;
    }

    int numCorrectPasswords = 0;
    char line[500];
    while (fgets(line, sizeof(line), infile)) {

        int valid = validPassword(line);

        numCorrectPasswords += valid;

        /* printf("%d\n", valid); */
        /* printf("%s", line); */
    }

    printf("Number correct passwords: %d\n", numCorrectPasswords);

    fclose(infile);
    return 0;
}
