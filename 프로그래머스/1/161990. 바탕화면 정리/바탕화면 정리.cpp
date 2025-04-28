#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int ws = wallpaper.size();
	vector<vector<int>> map(ws,vector<int>());
	int k = 0;
	for (string h : wallpaper)
	{
		map[k].push_back(h.find("#"));
		map[k].push_back(h.rfind("#"));
		k++;
	}
	int min_u = wallpaper.size();
	int min_l = wallpaper[0].size();
	int max_d = 0;
	int max_r = 0;
	for (size_t i = 0; i < ws; i++)
	{
		for (size_t r = 0; r < map[i].size(); r++)
		{
			if (map[i][r] != -1)
			{
				if (i <= min_u) 
				{
					min_u = i;
				}
				if (i >= max_d)
				{
					max_d = i;
				}
				if (map[i][r] <= min_l)
				{
					min_l = map[i][r];
				}
				if (map[i][r] >= max_r)
				{
					max_r = map[i][r];
				}
			}
		}
	}
	max_d++;
	max_r++;
    answer.push_back(min_u);
    answer.push_back(min_l);
    answer.push_back(max_d);
    answer.push_back(max_r);
    return answer;
}