#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define linelim 150

int getline_(char s[], int lim);
void remove_comments(char s[], int length, bool *in_comment);
int main(void) {
    char line[linelim];
    bool in_comment = false;
    int length = 0;

    while ((length = getline_(line, linelim)) > 0) {
        remove_comments(line, length, &in_comment);
        printf("%s", line);
    }

    return EXIT_SUCCESS;
}

int getline_(char s[], int lim) {
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

// need to implement what to do when a char occurs.
void remove_comments(char s[], int length, bool *in_comment) {
    bool in_string = false;
    int i = 0;
    while (i < length) {
        // string
        if (s[i] == '"' && !*in_comment) {
            in_string = !in_string;
            i++;
            continue;
        }

        // single line
        if (!in_string && !*in_comment && s[i] == '/' && s[i + 1] == '/') {
            s[i] = '\n';
            s[i + 1] = '\0';
            break;
        }

        // multi line
        if (!in_string && s[i] == '/' && s[i + 1] == '*') {
            *in_comment = true;
            s[i] = ' ';
            s[i + 1] = ' ';
            i += 2;
        }

        if (*in_comment) {
            if (s[i] == '*' && s[i + 1] == '/') {
                *in_comment = false;
                s[i] = ' ';
                s[i + 1] = ' ';
                i += 2;
                continue;
            }
            s[i] = ' ';
            i++;
            continue;
        }

        i++;
    }
}
