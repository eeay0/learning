#include <stdio.h>

int main(void) {
    int current_char, last_char = EOF;
    while ((current_char = getchar()) != EOF) {
        if (current_char == ' ') {
            if (last_char != ' ') {
                putchar(current_char);
            }
        } else {
            putchar(current_char);
        }
        last_char = current_char;
    }
}
