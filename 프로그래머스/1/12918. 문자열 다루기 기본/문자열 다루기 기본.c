#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(const char* s) {
    bool answer = true;
    answer = (strlen(s) == 4 || strlen(s) == 6);
    for(int i = 0; i < strlen(s); i++){
        if((int)s[i] >= 65) answer = false;
    }
    return answer;
}