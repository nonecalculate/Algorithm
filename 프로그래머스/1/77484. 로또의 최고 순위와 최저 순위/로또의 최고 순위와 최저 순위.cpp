#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    unordered_set<int> set1(lottos.begin(), lottos.end());
    
    int attach = 0;
    for (int num : win_nums)
    {
         if (set1.count(num))attach++;
    }
    
    int chacne = 0;
    for (int i : lottos)
    {
         if (i == 0) chacne++;
    }
    
    if ((attach + chacne) == 0)answer.push_back(6);
    else answer.push_back(7 - (attach + chacne));
    if (attach == 0)attach++;
    answer.push_back(7 - attach);
    return answer;
}