#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_FILE "input.txt"

typedef struct passport {
    int byr;
    int iyr;
    int eyr;
    int hgt;
    int ecl;
    int pid;
    int cid;
    int hcl;
} passport;

void addKey(char *key, passport *pp) {
    if ( strcmp(key, "byr") == 0 ) {
        pp->byr = 1;
    } else if ( strcmp(key, "iyr") == 0 ) {
        pp->iyr = 1;
    } else if ( strcmp(key, "eyr")  == 0) {
        pp->eyr = 1;
    } else if ( strcmp(key, "hgt")  == 0) {
        pp->hgt = 1;
    } else if ( strcmp(key, "ecl")  == 0) {
        pp->ecl = 1;
    } else if ( strcmp(key, "pid")  == 0) {
        pp->pid = 1;
    } else if ( strcmp(key, "cid")  == 0) {
        pp->cid = 1;
    } else if ( strcmp(key, "hcl")  == 0) {
        pp->hcl = 1;
    }
}

void parseString(char *str, passport *pp) {

    size_t stringLength = strlen(str);
    char string[stringLength + 1];  // str may contain a \n character at end
    strcpy(string, str);

    char *key = strtok(string, ":");
    char *value = strtok(NULL, " ");

    while (key != NULL && value != NULL) {
        addKey(key, pp);

        key = strtok(NULL, ":");
        value = strtok(NULL, " ");
    }
}

void initializePassport(passport *pp) {
        pp->byr = 0;
        pp->iyr = 0;
        pp->eyr = 0;
        pp->hgt = 0;
        pp->ecl = 0;
        pp->pid = 0;
        pp->cid = 0;
        pp->hcl = 0;
}

int validatePassport(passport *pp) {
    int sum;
    sum = pp->byr + pp->iyr + pp->eyr + pp->hgt + pp->ecl + pp->pid + pp->hcl;
    if ( sum == 7 ) {
        return 1;
    } else {
        return 0;
    }
}

int subMain() {
    FILE *file = fopen(INPUT_FILE, "r");

    if (!file) {
        puts("cannot open file");
        exit(1);
    }

    char line[100];

    int valid;
    int validPassports = 0;
    passport pp;
    initializePassport(&pp);
    while ( fgets(line, sizeof(line), file) ) {
        if (line[0] == '\n') {
            valid = validatePassport(&pp);
            validPassports += valid;

            initializePassport(&pp);
        } else {
            parseString(line, &pp);
        }
    }
    valid = validatePassport(&pp);
    validPassports += valid;

    fclose(file);

    return validPassports;
}

int main() {

    int result = subMain();
    printf("Number of valid passports = %i\n", result);

    return 0;
}
