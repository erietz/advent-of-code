#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUT "input.txt"



int main() {
    FILE *file = fopen(INPUT, "r");

    char line[20];

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);

}
