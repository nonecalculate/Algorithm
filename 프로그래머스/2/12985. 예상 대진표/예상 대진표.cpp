#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
	int cnt = 1;
	bool meet = false;
	if (abs(a - b) == 1) {
		if (a % 2)a++;
		if (b % 2)b++;
		if (a / 2 == b / 2)meet = 1;
	}
	while (!meet)
	{
		cnt++;
		if (a % 2)a++;
		a = a / 2;
		if (b % 2)b++;
		b = b / 2;
		if (abs(a - b) == 1) {
			if (a % 2)a++;
			if (b % 2)b++;
			if (a / 2 == b / 2)meet = 1;
		}

	}
    answer = cnt;
    return answer;
}