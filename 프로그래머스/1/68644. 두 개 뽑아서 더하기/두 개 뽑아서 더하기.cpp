#include <string>
#include <set>
#include <vector>

using namespace std;

vector<int> Calc(vector<int> numbers) 
{
	set<int> sums;

	for (int i = 0; i < numbers.size(); i++) 
	{
		for (int j = i+1; j < numbers.size(); j++) 
		{
			sums.insert(numbers[i] + numbers[j]);
		}
	}

	vector<int> result(sums.begin(), sums.end());

	return result;
}

vector<int> solution(vector<int> numbers) {
    vector<int> answer = Calc(numbers);
    return answer;
}