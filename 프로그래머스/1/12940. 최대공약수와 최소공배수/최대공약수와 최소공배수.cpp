#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int max = n;
    int min = m;
    int temp = 0;
    if(min > max){
        temp = max;
        max = min;
        min = temp;
    }
    temp = 1;
    while(temp != 0){
        temp = max % min ;
        max = min;
        min = temp;
    }
    min = (m * n) / max;
    answer.push_back(max);
    answer.push_back(min);
    return answer;
}