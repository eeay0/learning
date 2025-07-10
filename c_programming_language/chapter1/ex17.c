#include <stdio.h>
#define MAX 1000
#define MIN 10

int getline(char s[], int lim);

int main(void) {
    char line[1000];
    int len;

    while ((len = getline(line, MAX)) > 0) {
        if (len > MIN) {
            printf("--------\n");
            printf("Line size is: %d\n", len);
            printf("%s", line);
            printf("--------\n");
        } else if (len > 1) {
            printf("shorter than MIN");
        }
    }
}

int getline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = (char) c;
    if (c == '\n') {
        s[i] = (char) c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
