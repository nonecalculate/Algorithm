#include <string>
#include <vector>

using namespace std;

#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a <= b ? a : b)

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int w = 0;
    int h = 0;
    for(int i =0 ; i <(int)sizes.size(); i++)
    {
        if(w < MAX(sizes[i][0], sizes[i][1])) w = MAX(sizes[i][0], sizes[i][1]);
        if(h < MIN(sizes[i][0], sizes[i][1])) h = MIN(sizes[i][0], sizes[i][1]);
    }
    answer = w*h;
    return answer;
}