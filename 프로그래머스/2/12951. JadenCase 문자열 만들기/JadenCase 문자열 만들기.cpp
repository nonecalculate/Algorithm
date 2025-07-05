#include <string>
#include <vector>
#include <sstream>
using namespace std;

string solution(string s) {
    string answer = "";
    stringstream f(s);
	string h = "";
    vector<string> a;
	vector<char> word;
	while (f >> h)
	{
		a.push_back(h);
	}
	int size = a.size();
	for (string r : a) 
	{
		int cnt = 0;
		for (char c : r)
		{
			if (!cnt)
				if (isalpha(c))
					if (c > 96) word.push_back(c - ' ');
					else word.push_back(c);
				else word.push_back(c);
			else {
				if (isalpha(c))
					if (c <= 96) word.push_back(c + ' ');
					else word.push_back(c);
				else word.push_back(c);
			}
			cnt++;
		}
		size--;
		if (size > 0) word.push_back(' ');
	}
	for (char c : word) {
		answer += c;
	}
    for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
			if (answer[i] != ' ')answer.insert(i, 1, ' ');
	}
    return answer;
}