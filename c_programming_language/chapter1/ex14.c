#include <stdio.h>

int main(void) {
    int c;
    int chars[11] = {0};
    /* 0...9 and whitespaces*/

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            break;
        }

        if (c == ' ' || c == '\t') {
            chars[10]++;
        }

        if (c >= '0' && c <= '9') {
            chars[c - '0']++;
        }
    }

    for (int j = 0; j < 10; j++) {
        printf("%5d =", j);
        for (int i = 0; i < chars[j]; i++) {
            putchar('*');
        }
        putchar('\n');
    }
    printf("white =");
    for (int i = 0; i < chars[10]; i++) {
        putchar('*');
    }
}
