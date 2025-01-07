#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    int length = strlen(s);
    char* answer;
    if (length % 2 == 0)
    {
        answer = (char*)malloc(3);
        snprintf(answer, 3, "%.*s", 2, s + (length / 2 - 1));
        printf("%c%c", answer[0],answer[1]);
    }
    else if (length % 2 == 1)
    {
        answer = (char*)malloc(2);
        snprintf(answer, 2, "%.*s", 1, s + (length / 2));

        printf("%c", answer[0]);
    }

    return answer;
}