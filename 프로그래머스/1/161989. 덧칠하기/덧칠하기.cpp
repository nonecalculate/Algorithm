#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int progress = 0;
    for (int i : section)
    {
        if (i == section[0])
        {
            progress = section[0] + m - 1;
            answer++;
        }
        if (progress < i)
        {
            progress = i + m - 1;
            answer++;
        }
    }
    return answer;
}