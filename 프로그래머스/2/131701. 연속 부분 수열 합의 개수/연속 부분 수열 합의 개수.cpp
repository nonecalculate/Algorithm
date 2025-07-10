#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    vector<int> temp = elements;
	vector<int> arr;
	for (int s : elements)
		temp.push_back(s);
	int t = 0;
	for (int k = 0; k < elements.size(); k++)
	{
		for (int i = 0; i < elements.size(); i++)
		{
			int c = 0;
			for (int j = 0; j < i; j++)
			{
				c += temp[k + j];
			}
			if (c == 0) continue;
			else arr.push_back(c);
		}
		t += temp[k];
	}
	sort(arr.begin(), arr.end());
	arr.push_back(t);
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
    answer = arr.size();
    return answer;
}