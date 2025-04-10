#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(),score.end(), greater<int>());
    int DeleteScores = score.size() % m;
    for (int i = 0; i< DeleteScores; i++)
    {
    	score.pop_back();
    }
    int stack = 0;
    int FirstScore = 0;
    for (int i : score)
    {
    	if (stack == 0)FirstScore = i;
    	if (FirstScore >= i)FirstScore = i;
	    stack++;
	    if (stack == m)
	    {
		    answer += FirstScore * m;
		    stack = 0;
	    }
    }
    return answer;
}