#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    	int length = n;
	while (length > 1 ) 
	{
		if (length % 2)ans++;
		length /= 2;
	}
	ans++;
	cout << ans;

    return ans;
}