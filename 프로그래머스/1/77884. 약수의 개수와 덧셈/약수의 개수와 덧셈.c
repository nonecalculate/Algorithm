#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int left, int right) {
    int answer = 0;
    int s =0;
    for(int i = left; i <= right; i++){
        for(int j = 1; j <= i; j++){
            if(i % j == 0)s++; 
        }
        if(s % 2 == 0)answer += i;
        else if(s % 2 == 1)answer -= i;
        s = 0;
    }
    return answer;
}