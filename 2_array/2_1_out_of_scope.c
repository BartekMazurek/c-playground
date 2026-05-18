#define LEN 3

int main() {

    int array1[LEN];
    int array2[LEN];
    int array3[LEN];

    for (int i = 0; i < LEN; i++) {
        array1[i] = 1;
        array2[i] = 2;
        array3[i] = 3;
    }

    array2[-1] = 2;
    array2[LEN] = 2;

    return 0;
}
