#include <stdio.h>

int main(void) {
    int c, count;
    count = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            ++count;
        }
        printf("%c\t", c);
        printf("%d\n", count);
    }
}
