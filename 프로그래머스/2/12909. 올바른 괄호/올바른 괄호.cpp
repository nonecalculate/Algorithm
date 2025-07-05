#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
	int open, close;
	open = close = 0;
	int count = 0;
	for (char c : s) { 
		if (c == '(') 
		{
			count++;
			open++;
		};
		if (count >= 1 && c == ')')count--;
		if (c == ')')close++;
	}
	if (count)answer = false;
	if (open != close) answer = false;
    cout << "Hello Cpp" << endl;

    return answer;
}