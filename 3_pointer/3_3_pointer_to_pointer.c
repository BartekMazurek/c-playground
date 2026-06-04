#include<stdio.h>

void increase(int **p) {
    *p = *p + 1;
    printf("%d\n", **p);
}

int main() {
    int numbers[3] = {1, 2, 3};

    int *p;

    p = numbers + 1;

    increase(&p);

    printf("%d", *p);

    return 0;
}
