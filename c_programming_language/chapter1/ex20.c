#include <stdio.h>

int get_input(char str[], int limit);
char *detab(char str_in[], char str_out[], int length, int limit);

int main(void) {
    char input[1000];
    char output[1000];
    int length;

    printf("Enter input (Ctrl+D to end):\n");
    length = get_input(input, sizeof(input));

    detab(input, output, length, sizeof(output));

    printf("Detabbed output:\n%s\n", output);
    return 0;
}

int get_input(char str[], int limit) {
    int c;
    int i = 0;
    while ((c = getchar()) != EOF) {
        if (i == limit - 1) {
            str[limit - 1] = '\0';
            printf("Memory limit exceeded");
            return i;
        }
        str[i] = (char) c;
        i++;
    }
    str[i] = '\0';
    return i;
}

char *detab(char str_in[], char str_out[], int length, int limit) {
    int out = 0;
    for (int in = 0; in <= length; in++) {
        if (in == limit - 1) {
            str_out[limit - 1] = '\0';
            printf("Memory limit exceeded");
            break;
        }
        if (str_in[in] == '\t') {
            str_out[out++] = ' ';
            str_out[out++] = ' ';
            str_out[out++] = ' ';
            str_out[out++] = ' ';
            continue;
        }
        str_out[out++] = str_in[in];
    }
    return str_out;
}
