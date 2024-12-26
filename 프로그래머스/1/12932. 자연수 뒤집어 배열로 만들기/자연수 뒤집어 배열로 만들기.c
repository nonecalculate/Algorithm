#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(long long n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    int i = 0;
    long long k = n;
    while (k != 0) {
        k /= 10;
        i++;
    }
    int* answer = (int*)malloc(sizeof(int) * i);
    k = n;
    for (int j = 0; j < i; j++) {
        answer[j] = k % 10;
        k /= 10;
    }
    return answer;
}