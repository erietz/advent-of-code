#!/bin/awk

BEGIN { }

{foo[bar++] = $1}

END {
    done = 0;
    for (i=0; i<bar; i++) {
        for (j=0; j<bar; j++) {
            if ( foo[i] + foo[j] == 2020 ) {
                printf "%i + %i = 2020 \n", foo[i], foo[j];
                printf "%i * %i = %i \n", foo[i], foo[j], foo[i] * foo[j];
                done = 1;
                break;
            }
        }
        if (done == 1) {
            break;
        }
    }
}
