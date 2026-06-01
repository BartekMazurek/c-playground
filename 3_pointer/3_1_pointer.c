#include <stdio.h>

int main() {
    int number1 = 100;
    int number2 = 200;

    int *ptr = &number1;

    *ptr = 101;
    ptr = &number2;
    *ptr = 201;

    printf("n1: %d\n", number1);
    printf("n2: %d\n", number2);

    return 0;
}
