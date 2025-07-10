#include <stdio.h>

int main(void) {
    double fahr, cels;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    cels = lower;
    printf("Celsius\t\tFahrenheit\n");
    while (cels <= upper) {
        fahr = ((9.0 * cels) / 5.0) + 32.0;
        printf("%7.0f\t\t%10.1f\n", cels, fahr);
        cels += step;
    }
}
