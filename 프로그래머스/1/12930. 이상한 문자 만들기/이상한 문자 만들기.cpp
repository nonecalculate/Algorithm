#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

string solution(string s) {
	stringstream ss(s);
	string s1;
	string answer;
	int k = 0;
	while (ss >> s1) {
		for (int i = 0; i <= s1.length(); i++) {
			if (i % 2 == 0) {
				s1[i] = toupper(s1[i]);
			}
			else if (i % 2 == 1) {
				s1[i] = tolower(s1[i]);
			}
		}
		answer += s1;
	}
	if (answer.length() != s.length()) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 32) {
				answer.insert(i, " ");
			}
		}
	}
    return answer;
}