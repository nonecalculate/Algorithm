#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x) {
    bool answer = true;
    int p = x;
    int k = 0;
    int temp = 0;
    while(k == 0){
        temp += x%10;
        x /= 10;
        if(x == 0) k++;
    }
    if(p % temp != 0) answer = false;
    
    return answer;
}