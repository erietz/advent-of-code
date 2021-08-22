#!/bin/awk

BEGIN { }

{foo[bar++] = $1}

END {

done = 0;
for (i=0; i<bar; i++) {
    for (j=0; j<bar; j++) {
        for (k=0; k<bar; k++) {
            if ( foo[i] + foo[j] + foo[k] == 2020 ) {
                printf "%i + %i + %i = 2020 \n", foo[i], foo[j], foo[k];
                printf "%i * %i * %i = %i \n", foo[i], foo[j], foo[k],
                       foo[i] * foo[j] * foo[k];
                done = 1;
                break;
            }
        }
        if (done == 1) {
            break;
        }
    }
    if (done == 1) {
        break;
    }
}

}
