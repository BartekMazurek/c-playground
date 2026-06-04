#include <stdio.h>

typedef struct {
    int id;
    double number;
} Object;

void multiplyNumber(Object *p) {
    p->number = p->number * p->number;
}

int main() {
    Object p;
    p.id = 1;
    p.number = 2.0;

    multiplyNumber(&p);

    printf("id: %d \n", p.id);
    printf("number: %f \n", p.number);

    return 0;
}
