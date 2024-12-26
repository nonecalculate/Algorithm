#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int age) {
    int answer = 0;
    answer = 2023-age;
    printf("2022년 기준 %d살이므로 %d년생입니다.", age, answer);
    return answer;
}