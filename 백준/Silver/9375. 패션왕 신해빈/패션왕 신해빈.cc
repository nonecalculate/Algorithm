#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
vector<string> wear;
vector<int> times;
vector<int> answer;
int N, S;


int main()
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S;
        int cnt = 0;
        for (int j = 0; j < S; j++)
        {
            string temp, temp2 = "";
            cin >> temp;
            cin >> temp2;
            bool detect = false;
            for (int k = 0; k < wear.size(); k++)
                if (temp2 == wear[k]) {
                    times[k]++;
                    detect = 1;
                }
            if (!detect) {
                wear.push_back(temp2);
                times.push_back(1);
            }
        }
        cnt = 1;
        for (int i = 0; i < times.size(); i++) {
            cnt *= (times[i] + 1);
        }
        cnt -= 1;
        answer.push_back(cnt);
        times.clear();
        wear.clear();
    }

    for (int s : answer)cout << s << " ";

    return 0;
}