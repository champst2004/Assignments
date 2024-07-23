#include <stdio.h>

int main() {
    char capital, small;
    printf("Enter a capital letter: ");
    scanf("%c", &capital);

    if (capital >= 'A' && capital <= 'Z') {
        small = capital + ('a' - 'A');
        printf("The small letter is: %c\n", small);
    } else {
        printf("Enter a capital case letter.\n");
    }
    printf("All Alphabets:\n");
    for (char c = 'A'; c <= 'Z'; c++) {
        printf("%c = %c\n", c, c + ('a' - 'A'));
    }

    return 0;
}
