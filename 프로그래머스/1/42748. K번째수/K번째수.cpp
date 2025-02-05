#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer = {};
    for (int i = 0; i < commands.size() ; i++) 
	{
		vector<int> temparray = {};
		int temp1 = commands[i][0];
		int temp2 = commands[i][1];
		for (int j = temp1-1; j < temp2; j++) 
		{
			temparray.push_back(array[j]);
		}
		sort(temparray.begin(), temparray.end());
		answer.push_back(temparray[commands[i][2] - 1]);
	}
    return answer;
}