#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    vector<int> arr;
    int num = 0;
    int count = 0;
    while (ss >> num){
        arr.push_back(num);
        count++;
    }
    sort(arr.begin(), arr.end());
    answer = to_string(arr[0]) + " " + to_string(arr[count-1]);
    return answer;
}