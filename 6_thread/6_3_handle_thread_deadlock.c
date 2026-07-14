#include <stdio.h>
#include <windows.h>

#define THREADS 2

int sum;
CRITICAL_SECTION cs;

DWORD WINAPI ThreadWorker(LPVOID lpParam) {
    for (int i = 0; i < 1000; i++) {
        EnterCriticalSection(&cs);
        sum = sum + 1;
        LeaveCriticalSection(&cs);
    }

    return 0;
}

int main() {

    sum = 0;

    InitializeCriticalSection(&cs);

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

    DeleteCriticalSection(&cs);

    printf("sum = %d\n", sum);

    return 0;
}
