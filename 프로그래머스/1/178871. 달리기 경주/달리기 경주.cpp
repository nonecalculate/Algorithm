#include <string>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
 	unordered_map<string, int> rank;
	for (int i = 0; i < players.size(); i++)
	{
		rank[players[i]] = i;
	}

	string temp;
	for (string called : callings)
	{
		int currentrank = rank[called];
		if (currentrank > 0)
		{
			string frontplayer = players[currentrank - 1];

			swap(players[currentrank], players[currentrank - 1]);

			rank[called]--;
			rank[frontplayer]++;
		}
	}
	answer = players;
    return answer;
}