#include <stdio.h>

int main(void) {
    int c;
    int count = 0;
    int words[20];
    for (int i = 0; i < 20; i++) {
        words[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            break;
        }
        if (c != ' ') {
            words[count]++;
        }

        if (c == ' ') {
            count++;
        }
    }
    for (int i = 0; i <= count; i++) {
        for (int j = words[i]; j > 0; j--) {
            putchar('*');
        }
        putchar('\n');
    }
}
