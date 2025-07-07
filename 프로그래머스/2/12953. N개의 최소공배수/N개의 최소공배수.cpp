#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    sort(arr.begin(), arr.end());
	bool dec = 0;
	int attempt = 1;
	int cnt = 0;
	while (!dec)
	{
		answer = cnt * arr[0];
		for (int s : arr)
			if (!(answer % s))attempt++;
			else attempt--;
		if (attempt == arr.size()) dec = 1;
		attempt = 0;
		cnt++;
	}
    return answer;
}