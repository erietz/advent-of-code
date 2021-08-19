#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct filestat {
    int columns;
    int rows;
} filestat;

struct filestat getFileStats() {
    char *filename = "input.txt";
    FILE *file = fopen(filename, "r");

    if (!file) {
        printf("could not open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[120];     // estimate of max number of columns in input file
    int numColumns = 0; // actual max number of columns in input file
    int numRows = 0;    // actual number of rows in input file
    while (fgets(line, sizeof(line), file)) {
        int cols = strlen(line) - 1;    // includes the new line character
        if (cols > numColumns) {
            numColumns = cols;
        }
        numRows += 1;
    }

    fclose(file);

    filestat data = {.columns = numColumns, .rows = numRows};
    return data;
}

void buildMap(int numRows, int numColumns, char data[numRows][numColumns]) {
    char *filename = "input.txt";
    FILE *file = fopen(filename, "r");

    char line[120];     // estimate of max number of columns in input file
    int currRow = 0;
    while (fgets(line, sizeof(line), file)) {
        for (int i=0; i<strlen(line); i++) {
            data[currRow][i] = line[i];
        }
        currRow += 1;
    }

}


int main() {

    filestat stats = getFileStats();
    /* printf("%d\n", stats.columns); */
    /* printf("%d\n", stats.rows); */

    char data[stats.rows][stats.columns];

    buildMap(stats.rows, stats.columns, data);

    char tree[] = "#";
    int currColumn = 0;
    int numTrees = 0;
    for (int i=0; i<stats.rows; i++) {
        char location = data[i][currColumn];
        if (location == tree[0]) {
            numTrees += 1;
        }
        currColumn += 3;
        currColumn %= stats.columns;
    }

    printf("Number of trees %d\n", numTrees);

    return 0;
}
