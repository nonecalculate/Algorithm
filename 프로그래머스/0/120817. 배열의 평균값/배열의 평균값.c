#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
double solution(int numbers[], size_t numbers_len) {
    double answer = 0;
    for(int i =0; i < numbers_len; i++){
        answer += numbers[i];
    }
    answer /= numbers_len;
    double a = answer - (int)answer;
    if (a == 0.5 || a == 0);
    else answer -= a;
    return answer;
}