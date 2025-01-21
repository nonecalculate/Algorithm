#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int solution(int n) {
    int answer = 0;
    int len = 0;
    int num = n;
    while (num / 3 > 0) {
        num /= 3;
        len++;
    }

    for (int i = 0; i <= len; i++) {
        answer += (n % 3) * pow(3, len - i);
        n /= 3;
    }
    return answer;
}