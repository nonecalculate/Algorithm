#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if(arr.size() <= 1){ answer.push_back(-1); }
    else {
        int min = 10000000;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] < min) min = arr[i];
        }
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] != min) answer.push_back(arr[i]);
        }
    }
    return answer;
}