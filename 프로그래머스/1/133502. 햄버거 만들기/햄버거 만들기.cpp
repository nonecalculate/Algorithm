#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    string ingredient_str = "";
    for (int item : ingredient) {
        ingredient_str += to_string(item);
    }

    string pattern = "1231";
    string processed_str = "";

    for (char c : ingredient_str) {
        processed_str += c;
        if (processed_str.length() >= pattern.length() &&
            processed_str.substr(processed_str.length() - pattern.length()) == pattern) {
            answer++;
            processed_str.resize(processed_str.length() - pattern.length()); // 마지막 4 문자 제거
        }
    }
    return answer;
}