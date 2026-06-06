#include "input.h"

#include <ctype.h>
#include <stdio.h>

int getLine(char *s, int lim) {
    int c, i;

    while (lim-- > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';

    return i;
}

int parseInt(char *s) {
    int val, i;

    for (i = 0; isspace(s[i]); i++) {
        ;
    }
    for (val = 0; isdigit(s[i]); i++) {
        val = val * 10 + (s[i] - '0');
    }

    return val;
}
