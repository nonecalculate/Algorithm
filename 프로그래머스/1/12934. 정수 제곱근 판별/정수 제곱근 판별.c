#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(long long n) {
    long long answer = 0;
    for(long long i = 1;  i <= n; i++){
        if(((n / i) == i) && ((n % i) == 0)) {
            answer = (i+1)*(i+1);
            break;
        }
        else answer = -1;
    }
    return answer;
}