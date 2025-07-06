#include <iostream>
#include<string>
#include<stack>

using namespace std;

int solution(string s)
{
	stack<char> st;
	int answer = -1;
	for (char c : s)
	{
		if (!st.empty() && st.top() == c)
		{
			st.pop();
		}
		else st.push(c);
	}

	if (st.empty()) answer = 1;
	else answer = 0;
    return answer;
}