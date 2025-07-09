#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> temp;
	int l = 0;
	int r = 0;
	bool find = false;
	for (string h : words)
	{
		for (int i = 0; i < temp.size(); i++)
		{
			if (h == temp[i]) 
			{
				int cnt = 0;
				if ((temp.size() + 1) % n) cnt++;
				r = (temp.size() + 1) / n + cnt;
				l = (temp.size() + 1) % n;
				if (!l) l = n;
				find = 1;
			}
		}
		if (temp.size() < 1);
		else
		{
			if (temp[temp.size() - 1][temp[temp.size() - 1].size() - 1] != h[0])
			{
				int cnt = 0;
				if ((temp.size() + 1) % n) cnt++;
				r = (temp.size() + 1) / n + cnt;
				l = (temp.size() + 1) % n;
				if (!l) l = n;
				find = 1;
			}
		}
		if (find) break;
		temp.push_back(h);
	}
	answer.push_back(l);
	answer.push_back(r);
    return answer;
}