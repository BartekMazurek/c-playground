#include <stdlib.h>
#include <unistd.h>

#define SIZE 10000

int main() {
    char *letter;

    while (1) {
        letter = (char *) malloc(SIZE * sizeof(char));

        *letter = '\0';

        usleep(5000);
    }

    // pgrep 4_1_so
    // /proc/<PID>/stats
    // VmSize, VmRSS

    return 0;
}
