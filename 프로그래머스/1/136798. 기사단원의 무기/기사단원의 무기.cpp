#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    for(int i = 1; i < number+1 ; i++)
    {
        int k = 0;
        for (int j = 1; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                k++;
                if (j != i / j)k++;
            }
        }
        if (k > limit) answer += power;
        else answer += k;
    }
    return answer;
}