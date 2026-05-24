#include <stdio.h>
#include <stdlib.h>

#define FIRST 2
#define SECOND 4

int main() {
    char **letters;

    letters = (char **) malloc(sizeof(char *) * FIRST);

    for (int i = 0; i < FIRST; i++) {
        letters[i] = (char *) malloc(sizeof(char) * SECOND);
    }

    letters[0][0] = 'A';
    letters[0][1] = 'B';
    letters[0][2] = 'C';
    letters[0][3] = 'D';
    letters[1][0] = 'E';
    letters[1][1] = 'F';
    letters[1][2] = 'G';
    letters[1][3] = 'H';

    for (int i = 0; i < FIRST; i++) {
        for (int j = 0; j < SECOND; j++) {
            printf("%c", letters[i][j]);
        }
    }

    for (int i = 0; i < FIRST; i++) {
        free(letters[i]);
    }

    free(letters);

    return 0;
}
