#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num) {
    int answer = 0;
    while (num != 1){
        if (num == 0)break;
        else if(num % 2 == 0) num /=2;
        else if(num % 2 == 1) num = num * 3 + 1;
        answer++;
        if (answer > 500) {
            answer = -1;
            break;
        }
    }
    return answer;
}