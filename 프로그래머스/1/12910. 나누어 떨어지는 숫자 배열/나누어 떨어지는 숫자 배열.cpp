#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    int check = 0;
    for(int i = 0 ; i < arr.size(); i++){
        if(arr[i] % divisor == 0){
            answer.push_back(arr[i]);
            check++;
        }
    }
    if(check == 0 )answer.push_back(-1);
    sort(answer.begin(),answer.end());
    return answer;
}