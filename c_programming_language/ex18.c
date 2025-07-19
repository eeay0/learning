#include <stdio.h>
#define MAX 1000
#define MIN 10

int getline(char s[], int lim);
int trim_trailing(char line[], int len);

int main(void) {
    char line[1000];
    int len;

    while ((len = getline(line, MAX)) > 0) {
        len = trim_trailing(line, len);
        if (len > 0) {
            printf("===========");
            printf("%s\n", line);
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

int trim_trailing(char line[], int len) {
    int i = len - 1;
    while (i >= 0 && (line[i] == ' ' || line[i] == '\n' || line[i] == '\t')) {
        i--;
    }
    if (i < 0) {
        return 0;
    }
    line[++i] = '\n';
    line[++i] = '\0';
    return i;
}
