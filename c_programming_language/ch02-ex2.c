#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int getline_(char s[], int lim);

int main() {
    char line[100];
    int length = getline_(line, 100);

    printf("%d", length);
    return EXIT_SUCCESS;
}

int getline_(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1; i++) {
        if ((c = getchar()) == EOF)
            break;
        if (c == '\n')
            break;
    }
    if (c == '\n') {
        s[i] = (char) c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
