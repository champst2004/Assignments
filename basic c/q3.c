#include<stdio.h>
int main()
{
    int phy, chem, maths;
    printf("Enter Physics marks: ");
    scanf("%d",&phy);
    printf("Enter Chemistry marks: ");
    scanf("%d",&chem);
    printf("Enter Maths marks: ");
    scanf("%d",&maths);

    if(phy >= 50 && chem >= 50 && maths >= 50){
        printf("Pass");
    }
    else{
        printf("Fail");
    }
    return 0;
}