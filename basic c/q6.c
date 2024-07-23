#include<stdio.h>
int main()
{
    int num, sum;
    printf("Enter a number: ");
    scanf("%d",&num);
    for(int i = 0; i < 5; i++){
        int rem = num % 10;
        num = num / 10;
        sum += rem;
    }
    printf("Sum of digits is %d.",sum);
    return 0;
}