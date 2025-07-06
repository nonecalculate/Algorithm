#include <string>
#include <vector>

using namespace std;



int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= n; i++) 
	{
		int k = 0;
		int j = i;
		while (k <= n)
		{
			k += j;
			j++;
			if (k == n) 
			{
				answer++;
			}
		}
		k = 0;
	}
    return answer;
}