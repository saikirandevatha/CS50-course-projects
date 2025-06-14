#include <stdio.h>

int main() {
    int num1, num2;

    printf("Enter an integer: ");
    if (scanf("%d", &num1) != 1) {
        printf("That's not an integer!\n");
    }

    printf("Enter another integer: ");
    if (scanf("%d", &num2) != 1) {
        printf("That's not an integer!\n");
    }

    printf("You entered %d and %d.\n", num1, num2);

    return 0;
}
