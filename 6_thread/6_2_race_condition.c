#include <stdio.h>
#include <windows.h>

#define THREADS 2

int sum;

DWORD WINAPI ThreadWorker(LPVOID lpParam) {
    for (int i = 0; i < 1000; i++) {
        sum = sum + 1;
    }

    return 0;
}

int main() {
    HANDLE hThread[THREADS];
    DWORD dwThread[THREADS];

    hThread[0] = CreateThread(
        NULL,
        0,
        ThreadWorker,
        NULL,
        0,
        &dwThread[0]
    );

    hThread[1] = CreateThread(
        NULL,
        0,
        ThreadWorker,
        NULL,
        0,
        &dwThread[1]
    );

    WaitForMultipleObjects(THREADS, hThread, TRUE, INFINITE);

    CloseHandle(hThread[0]);
    CloseHandle(hThread[1]);

    printf("sum = %d\n", sum);

    return 0;
}
