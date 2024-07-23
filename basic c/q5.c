#include <stdio.h>

int main() {
    float basic, hra, da, other, gross;

    printf("Enter the basic salary of the employee: ");
    scanf("%f", &basic);

    hra = 0.3 * basic;
    da = 0.6 * basic;
    other = 0.4 * basic;

    gross = basic + hra + da + other;

    printf("The gross salary of the employee is: %f\n", gross);

    return 0;
}
