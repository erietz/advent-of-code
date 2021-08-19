#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Number correct passwords: 564 */

int validPassword(char *string) {

    // Copy the string because strtok modifies strings in place
    int copyLength = strlen(string);
    char stringCopy[copyLength];
    strcpy(stringCopy, string);

    //--------------------------------------------
    // Example password: 3-5 f: fgfff
    //--------------------------------------------

    // strtok will replace its second argument will null terminator
    char *min = strtok(stringCopy, "-");    // 3
    char *max  = strtok(NULL, " ");         // 5
    char *character  = strtok(NULL, ":");   // f
    char *password  = strtok(NULL, " ");    // fgfff

    long minInt = strtol(min, NULL, 10);
    long maxInt = strtol(max, NULL, 10);
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
    // fgets will read string until \n character is encountered or the limit
    // defined by the second argument of the function is reached. We can assume
    // in this case that the length of any line won't be longer than 500 chars.
    char line[500];
    while (fgets(line, sizeof(line), infile)) {
        int valid = validPassword(line);
        numCorrectPasswords += valid;
    }

    printf("Number correct passwords: %d\n", numCorrectPasswords);

    fclose(infile);
    return 0;
}
