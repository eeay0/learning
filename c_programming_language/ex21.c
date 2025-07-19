#include <stdio.h>
#define TABSTOP 4

int main(void) {
    int c;
    int space_c = 0;

    while ((c = getchar()) != EOF) {
        while (c == ' ') {
            space_c++;
            c = getchar();
        }
        while (space_c >= TABSTOP) {
            putchar('T');
            space_c -= TABSTOP;
        }
        while (space_c > 0 && space_c < TABSTOP) {
            putchar(' ');
            space_c--;
        }
        putchar(c);
    }
}
