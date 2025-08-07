#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
int N, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	unordered_map<string, int> freq;

	for (int i = 0; i < N; i++)
	{
		string word;
		cin >> word;
		if (word.length() >= M)
			freq[word]++;
	}

	vector<string> answer;
	for (const auto& p : freq)
		answer.push_back(p.first);

	sort(answer.begin(), answer.end(), [&](const string& a, const string& b)
	{
		if (freq[a] != freq[b]) return freq[a] > freq[b];
		if (a.length() != b.length())return a.length() > b.length();
		return a < b;
	});

	for (const auto& h : answer)
		cout << h << "\n";

	return 0;
}
