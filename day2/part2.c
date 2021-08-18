#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validPassword(char *string) {

    char stringCopy[500];
    strcpy(stringCopy, string);

    char *idx1 = strtok(stringCopy, "-");
    char *idx2  = strtok(NULL, " ");
    char *character  = strtok(NULL, ":");
    char *password  = strtok(NULL, " ");

    char *ptr;

    int index1 = (int)strtol(idx1, &ptr, 10) - 1;
    int index2 = (int)strtol(idx2, &ptr, 10) - 1;
    char letter = *character;

    int length = strlen(password);

    char val1 = password[index1];
    char val2 = password[index2];

    if (index1 > length - 1 || index2 > length - 1 ) {
        return 0;
    } else
    if (val1 == letter && val2 != letter) {
        return 1;
    } else
    if (val1 != letter && val2 == letter) {
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
