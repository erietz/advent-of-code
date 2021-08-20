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

/*
typedef struct passport {
    int byr;    // 1937
    int iyr;    // 2017
    int eyr;    // 2020
    char *hgt;  // 183cm
    char *ecl;  // gry
    int pid;    // 860033327
    int cid;    // 147
    int hcl;    // #fffffd
} passport;
*/

passport addKey(char *key, passport pp) {
    if ( strcmp(key, "byr") == 0 ) {
        pp.byr = 1;
    } else if ( strcmp(key, "iyr") == 0 ) {
        pp.iyr = 1;
    } else if ( strcmp(key, "eyr")  == 0) {
        pp.eyr = 1;
    } else if ( strcmp(key, "hgt")  == 0) {
        pp.hgt = 1;
    } else if ( strcmp(key, "ecl")  == 0) {
        pp.ecl = 1;
    } else if ( strcmp(key, "pid")  == 0) {
        pp.pid = 1;
    } else if ( strcmp(key, "cid")  == 0) {
        pp.cid = 1;
    } else if ( strcmp(key, "hcl")  == 0) {
        pp.hcl = 1;
    }
    return pp;
}

passport parseString(char *str, passport pp) {

    int stringLength = strlen(str);
    char string[stringLength];
    strcpy(string, str);

    char *key = strtok(string, ":");
    char *value = strtok(NULL, " ");

    /* puts(key); */
    /* puts(value); */

    /* pp = addKey(key, pp); */

    while (key != NULL && value != NULL) {
        pp = addKey(key, pp);
        /* puts(key); */
        /* puts(value); */

        key = strtok(NULL, ":");
        value = strtok(NULL, " ");
    }

    return pp;
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
            pp = parseString(line, pp);
            /* printf("%i\n", pp.pid); */
        }
    }
    valid = validatePassport(&pp);
    validPassports += valid;

    fclose(file);

    return validPassports;
}

int main() {


    /* char strTest[] = "pid:561068005 eyr:2025 iyr:2017 cid:139 ecl:blu hcl:#ceb3a1"; */
    /* passport pp = initializePassport(); */
    /* pp = parseString(strTest, pp); */
    /* printf("pid %i\n", pp.pid); */
    /* printf("eyr %i\n", pp.eyr); */
    /* printf("iyr %i\n", pp.iyr); */
    /* printf("cid %i\n", pp.cid); */
    /* printf("ecl %i\n", pp.ecl); */
    /* printf("hcl %i\n", pp.hcl); */
    /* printf("hgt %i\n", pp.hgt); */
    /* printf("byr %i\n", pp.byr); */
    /* printf("valid: %d\n", validatePassport(pp)); */

    int result = subMain();
    printf("%i\n", result);

    return 0;
}
