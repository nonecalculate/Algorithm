#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;
	vector<int> mul;
	bool breaked = false;
	for (int i = 2; i < sum - 1; i++)
	{
		if (sum % i == 0)mul.push_back(i);
	}
	for (int i = 0; i < mul.size(); i++) 
	{
		for (int j = 0; j < mul.size(); j++)
		{
			if (mul[i] * mul[j] == sum)
			{
				if ((mul[i] + mul[j]) * 2 - 4 == brown)
				{
					answer.push_back(mul[j]);
					answer.push_back(mul[i]);
					breaked = 1;
					break;
				}
			}
		}
		if (breaked) break;
	}
    return answer;
}