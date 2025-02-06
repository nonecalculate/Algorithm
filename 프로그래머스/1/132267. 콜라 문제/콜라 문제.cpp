#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int temp1 = 0;
	int temp2 = 0;
	bool check = true;
	while (check) 
	{
		temp1 = n / a;
		temp2 = n % a;
		if (temp1) 
		{
			answer += (temp1 * b);
			n = temp1 * b;
		}
		n += temp2;

		if (!(n / a)) check = false;
	}
    return answer;
}