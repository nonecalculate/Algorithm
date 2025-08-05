#include<iostream>
#include<vector>
using namespace std;

vector<int> arr;
int N, S, countsums = 0;

void dfs(int depth, int sum)
{
    if (depth == N)
    {
        if (sum == S)countsums++;
        return;
    }

    dfs(depth + 1, arr[depth] + sum);

    dfs(depth + 1, sum);
}

int main()
{
    cin >> N >> S;
    arr.resize(N);
    for (int i = 0; i < N; i++)cin >> arr[i];

    dfs(0, 0);

    if (S == 0)countsums--;

    cout << countsums;

    return 0;
}