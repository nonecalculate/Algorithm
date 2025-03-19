#include <string>
#include <vector>
#include <string>

using namespace std;

string solution(vector<int> food) {
	vector<int> cal;
	string answer = "";
	for (int r : food)
	{
		cal.push_back(r/2);
	}
	
	for (int i = 1; i < cal.size(); i++)
	{
		for (int j = 0; j < cal[i]; j++)
		{
			answer += to_string(i);
		}
		if (i == cal.size() - 1) answer += "0";
	}
	for (int i = cal.size() - 1; i >= 1; i--)
	{
		for (int j = 0; j < cal[i]; j++)
		{
			answer += to_string(i);
		}
	}
    return answer;
}