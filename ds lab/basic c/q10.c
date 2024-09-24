#include <stdio.h>
#include <math.h>

int main() {
    double base, exp, power, number, root;

    printf("Enter the base: ");
    scanf("%lf", &base);
    printf("Enter the exp: ");
    scanf("%lf", &exp);
    
    power = pow(base, exp);
    printf("The result is %lf\n", power);

    printf("Enter the number to find the square root: ");
    scanf("%lf", &number);

    root = sqrt(number);
    printf("The square root is: %f\n", root);

    return 0;
}
