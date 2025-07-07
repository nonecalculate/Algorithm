#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
	vector<int> counting;
	sort(tangerine.begin(), tangerine.end());
	int temp = tangerine[tangerine.size() - 1];
	int cnt= 0;
	for (int i = tangerine.size() - 1; i >= 0; i--)
	{
		if (tangerine[i] == temp)cnt++;
		else 
		{
			counting.push_back(cnt);
			temp = tangerine[i];
			cnt = 1;
		}
	}
    counting.push_back(cnt);
	sort(counting.begin(), counting.end());
    cnt = 0;
	for (int i = counting.size() - 1; i >= 0; i--)
	{
		k -= counting[i];
		cnt++;
		if (k <= 0) {
			break;
		};
	}
    answer = cnt;
    return answer;
}