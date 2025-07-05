#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt1 = 0;
	int cnt2 = 0;
	while (s != "1") {
		vector<char> arr;
		for (char c : s) 
		{
			if (c == '0')cnt1++;
			else arr.push_back(c);
		}
		int num = arr.size();
		s = "";
		while (num > 0) {
			s = to_string(num % 2) + s;
			num /= 2;
		}
		cnt2++;
	}
    answer.push_back(cnt2);
    answer.push_back(cnt1);
    return answer;
}