#include <stdio.h>
#include <stdlib.h>

typedef struct stack_el {
    int value;
    struct stack_el *next;
} stack_el;

void push(stack_el **p, int value) {
    stack_el *new_el = malloc(sizeof(stack_el));

    new_el->value = value;
    new_el->next = *p;

    *p = new_el;
}

void pop(stack_el **p) {
    stack_el *old = *p;
    *p = old->next;

    free(old);
}

int main() {
    stack_el *p = NULL;

    push(&p, 1);
    push(&p, 2);
    push(&p, 3);

    pop(&p);
    pop(&p);
    pop(&p);

    return 0;
}
