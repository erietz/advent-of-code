#include <stdio.h>

int main() {
    char *fileName = "./passwords.txt";
    FILE *infile = fopen(fileName, "r");

    if (!infile) {
        printf("could not open %s\n", fileName);
        return -1;
    }

    char line[500];
    while (fgets(line, sizeof(line), infile)) {
        printf("%s", line);
    }

    fclose(infile);
    return 0;
}
