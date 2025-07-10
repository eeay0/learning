#include <stdio.h>
#define MAX 1000
#define MIN 10

/* trim end and start of the string, print trimmed string and reversed string. */

int getline(char s[], int lim);
void shift(char s[], int n);
void ltrim(char s[]);
void rtrim(char s[], int len);
void reverse(char s[], int len);

int main(void) {
    // char line[1000];
    // int len;
    //
    // while ((len = getline(line, MAX)) > 0) {
    //     if (len > 0) {
    //         printf("===========");
    //         printf("%s\n", line);
    //     }
    // }
    char str1[] = "Hello";
    reverse(str1, 5);
    printf("'%s'\n", str1); // 'Hello'

    return 0;
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

void ltrim(char s[]) {
    int i = 0;
    while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t') {
        i++;
    }
    if (i > 0) {
        int j = 0;
        while (s[i] != '\0') {
            s[j++] = s[i++];
        }
        s[j] = '\0';
    }
}

void rtrim(char s[], int len) {
    int i = len - 1;
    while (i >= 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')) {
        i--;
    }
    if (i < 0) {
    }
    s[++i] = '\n';
    s[++i] = '\0';
}

void reverse(char s[], int len) {
    int i, j;
    char temp;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
