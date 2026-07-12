#include <stdio.h>
#include <windows.h>

#define THREADS 2

DWORD WINAPI Thread1Worker(LPVOID lpParam) {
    for (int i = 0; i < 1000; i++) {
        printf("%d\n", 2 * i);
        Sleep(1000);
    }

    return 0;
}

DWORD WINAPI Thread2Worker(LPVOID lpParam) {
    for (int i = 0; i < 1000; i++) {
        printf("%d\n", 2 * i + 1);
        Sleep(1000);
    }

    return 0;
}

int main() {
    HANDLE hThread[THREADS];
    DWORD dwThread[THREADS];

    hThread[0] = CreateThread(
        NULL,
        0,
        Thread1Worker,
        NULL,
        0,
        &dwThread[0]
    );

    hThread[1] = CreateThread(
        NULL,
        0,
        Thread2Worker,
        NULL,
        0,
        &dwThread[1]
    );

    WaitForMultipleObjects(THREADS, hThread, TRUE, INFINITE);

    CloseHandle(hThread[0]);
    CloseHandle(hThread[1]);

    return 0;
}
