#include <stdio.h>

int main(void) {
    for (int i = 0; i < 2; i++) {
        printf("%d\n", getchar() != EOF);
    }
    return 0;
}
