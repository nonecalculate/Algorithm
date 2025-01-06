#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int price, int money, int count) {
    long long answer = 0;
    long long needmoney = 0;
    for(int i = 1 ; i <=count ; i++){
        needmoney += price * i;
    }
    answer = needmoney - money;
    if(needmoney <= money) answer = 0;
    return answer;
}