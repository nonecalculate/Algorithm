#include <string>
#include <vector>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<vector<int>> map1;
    vector<vector<int>> map2;
    for (int i = 0; i < n; i++) 
    {
        vector<int> temp1;
        vector<int> temp2;
        for (int j = 0; j < n; j++)
        {
            if (arr1[i] % 2)temp1.push_back(1);
            else temp1.push_back(0);
            if (arr2[i] % 2)temp2.push_back(1);
            else temp2.push_back(0);

            arr1[i] /= 2;
            arr2[i] /= 2;
        }
        map1.push_back(temp1);
        map2.push_back(temp2);
    }
    vector<string> answer;

    for (int i = 0; i < n; i++)
    {
        string tempSt;
        for (int j = n - 1; j >= 0; j--)
        {
            if (map1[i][j] || map2[i][j])tempSt.append("#");
            else tempSt.append(" ");
        }
        answer.push_back(tempSt);
    }
    
    return answer;
}