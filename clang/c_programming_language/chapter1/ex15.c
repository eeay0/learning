#include <stdio.h>

double ctof(double);
double ftoc(double);

int main(void) {
    double c = 100.0;
    double f = 212.0;

    printf("%.2f°C = %.2f°F\n", c, ctof(c));
    printf("%.2f°F = %.2f°C\n", f, ftoc(f));

    return 0;
}

double ctof(double c) {
    return ((9.0 * c) / 5.0) + 32;
}

double ftoc(double f) {
    return (5.0 * (f - 32)) / 9.0;
}
