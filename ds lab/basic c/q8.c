#include <stdio.h>

int main() {
    int x, y;

    printf("Truth Table for && :\n");
    for (x = 0; x <= 1; x++) {
        for (y = 0; y <= 1; y++) {
            printf("%d %d    %d\n", x, y, x && y);
        }
    }
    printf("\nTruth Table for || :\n");
    for (x = 0; x <= 1; x++) {
        for (y = 0; y <= 1; y++) {
            printf("%d %d    %d\n", x, y, x || y);
        }
    }

    return 0;
}
