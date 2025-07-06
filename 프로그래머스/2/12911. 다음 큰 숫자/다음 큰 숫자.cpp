#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int temp = n;
	int answer = 0;
	string k;
	int cnt = 0;
	while (temp > 0)
	{
		if (temp % 2 == 1)cnt++;
		temp /= 2;
	}
	int comp = 0;
	while (comp != cnt)
	{
		comp = 0;
		n++;
		temp = n;
		while (temp > 0)
		{
			if (temp % 2 == 1)comp++;
			temp /= 2;
		}
		if (comp == cnt)answer = n;
	}
    return answer;
}