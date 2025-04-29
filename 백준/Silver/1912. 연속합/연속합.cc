#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n ;
	vector<int> list;
	int m[100000];
	for (int i = 0; i < n; i++)
	{
		int k = 0;
		cin >> k;
		list.push_back(k);	
	}
	m[0] = list[0];
	int answer = m[0];
	for (int i =0 ; i < n; i++)
	{
		answer = max(answer, m[i] = max(m[i - 1] + list[i], list[i]));
	}
	cout << answer;

	return 0;
}