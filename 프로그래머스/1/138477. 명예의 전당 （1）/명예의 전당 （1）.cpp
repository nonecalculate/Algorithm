#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> legend;
    for (int r : score) 
	{
		legend.push_back(r);
		sort(legend.begin(), legend.end(), greater<int>());
		if (legend.size() > k)legend.pop_back();
		answer.push_back(legend.back());
	}
    return answer;
}