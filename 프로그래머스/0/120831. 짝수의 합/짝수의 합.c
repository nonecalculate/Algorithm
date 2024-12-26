#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    for(int i = n; i >= 0; i--){
        if(i%2 == 0)answer += i;
    }
    return answer;
}