#include <stdio.h>

int main(void) {
    double fahr, cels;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("Fahrenheit\tCelsius\n");
    while (fahr <= upper) {
        cels = (5.0 * (fahr - 32.0)) / 9.0;
        printf("%10.0f\t%7.1f\n", fahr, cels);
        fahr += step;
    }
}
