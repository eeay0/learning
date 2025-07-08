#include <stdio.h>

#define IN 1
#define OUT 0

int main(void) {
    int c;
    int state = OUT;

    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            state = IN;
        }
        if (state == IN) {
            putchar(c);
            if (c == ' ' || c == '\n') {
                state = OUT;
                putchar('\n');
            }
        }
    }
}
