#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(const char* s) {
    bool answer = true;
    int check = strlen(s);
    if(check == 4 || check == 6);
    else answer = false;
    for(int i = 0; i < strlen(s); i++){
        if((int)s[i] >= 65) answer = false;
    }
    return answer;
}