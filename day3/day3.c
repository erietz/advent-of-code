#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The product is 1206576000 */

#define INPUTFILE "input.txt"   // file name of data file
#define MAX_COLUMNS 500         // max characters per line estimate in INPUTFILE

typedef struct filestat { int columns; int rows; } filestat;

struct filestat getFileStats() {
    FILE *file = fopen(INPUTFILE, "r");

    if (!file) {
        printf("could not open %s\n", INPUTFILE);
        exit(EXIT_FAILURE);
    }

    char line[MAX_COLUMNS];     // estimate of max number of columns in input file
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

    filestat stats = {.columns = numColumns, .rows = numRows};
    return stats;
}

// NOTE: This strategy uses Variable Length Arrays which seem not to be
// supported by all C compilers.
// See here: https://stackoverflow.com/a/3912959
void buildMap(int rows, int cols, char data[rows][cols]) {
    FILE *file = fopen(INPUTFILE, "r");

    char line[MAX_COLUMNS];
    int currRow = 0;
    while (fgets(line, sizeof(line), file)) {
        for (int i=0; i<strlen(line); i++) {
            data[currRow][i] = line[i];
        }
        currRow += 1;
    }
}

int traverseMap(
        char tree,
        int rows,
        int cols,
        char data[rows][cols],
        int right,
        int down
        ) {

    int currColumn = 0;
    int numTrees = 0;
    for (int i=0; i<rows; i = i + down) {
        char location = data[i][currColumn];
        if (location == tree) {
            numTrees += 1;
        }
        currColumn += right;
        currColumn %= cols;
    }
    return numTrees;
}

int main() {

    filestat stats = getFileStats();

    char data[stats.rows][stats.columns];

    buildMap(stats.rows, stats.columns, data);

    char tree = '#';
    int finalResult =
        traverseMap(tree, stats.rows, stats.columns, data, 1, 1) *
        traverseMap(tree, stats.rows, stats.columns, data, 3, 1) *
        traverseMap(tree, stats.rows, stats.columns, data, 5, 1) *
        traverseMap(tree, stats.rows, stats.columns, data, 7, 1) *
        traverseMap(tree, stats.rows, stats.columns, data, 1, 2);

    printf("The product is %i\n", finalResult);

    return 0;
}
