#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i < n; i++){
        int combine = arr1[i] | arr2[i];
        string h;
        
        for(int j= n-1; j>=0; j--){
            if(combine & (1 << j))
                h += "#";
            else
                h += " ";
        }
        answer.push_back(h);
    }
    return answer;
}