#include <stdio.h>

#define LEN 3

int main() {
    int numbers[LEN];

    *numbers = 10;
    *(numbers + 1) = 20;
    *(numbers + 2) = 30;

    for (int i = 0; i < LEN; i++) {
        printf("%d\n", numbers[i]);
    }

    return 0;
}
