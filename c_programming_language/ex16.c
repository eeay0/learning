#include <limits.h>
#include <stdio.h>
#define MAXLINE 10 /* maximum input line length */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main() {
    int len; /* current line length */
    int real_len;
    int max;               /* maximum length seen so far */
    char line[MAXLINE];    /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0) {
        real_len = len;

        if (len == MAXLINE - 1 && line[MAXLINE - 2] != '\n') {
            while (getchar() != '\n' && real_len < INT_MAX) {
                real_len++;
            }
        }

        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) {
        printf("length of the input: %d\n", real_len);
        printf("%s", longest);
    }
    return 0;
}

/* getline: read a line into s, return length */
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

/* copy: copy 'from' into 'to'; assume 'to' is big enough */
void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
