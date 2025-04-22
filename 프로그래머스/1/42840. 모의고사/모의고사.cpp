#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<int> answers) {
        vector<vector<int>> patterns = {
         {1, 2, 3, 4, 5},
         {2, 1, 2, 3, 2, 4, 2, 5},
         {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };
    vector<int> scores(3, 0);
    int n = answers.size();
    for (int i = 0; i < n; ++i) {
        if (answers[i] == patterns[0][i % patterns[0].size()]) {
            scores[0]++;
        }
        if (answers[i] == patterns[1][i % patterns[1].size()]) {
            scores[1]++;
        }
        if (answers[i] == patterns[2][i % patterns[2].size()]) {
            scores[2]++;
        }
    }
    int max_score = *max_element(scores.begin(), scores.end());

    vector<int> answer;
    for (int i = 0; i < 3; ++i) {
        if (scores[i] == max_score) {
            answer.push_back(i + 1);
        }
    }
    return answer;
}