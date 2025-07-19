#include <stdio.h>
#include <stdlib.h>
#define COLLIM 20

void getline(char s[], int lim);

int main(void) {
    char str[100];
    int last_sp;
    int i = 0;
    int col_c = 0;
    int first_to_print = 0;

    getline(str, 100);
    while (str[i] != '\0') {
        last_sp = -1;
        while (col_c <= COLLIM && str[i] != '\0') {
            if (str[i] == ' ') {
                last_sp = i;
            }
            i++;
            col_c++;
        }
        col_c = 0;

        if (last_sp != -1) {
            while (first_to_print < last_sp) {
                putchar(str[first_to_print++]);
            }
            putchar('\n');
            i = last_sp + 1;
            first_to_print = i;

        } else if (first_to_print < i) {
            while (first_to_print < i) {
                putchar(str[first_to_print++]);
            }
        }
    }

    return EXIT_SUCCESS;
}

void getline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != '\n'; ++i)
        s[i] = (char) c;
    // if (c == '\n') {
    //     s[i] = (char) c;
    //     ++i;
    // }
    s[i] = '\0';
}
