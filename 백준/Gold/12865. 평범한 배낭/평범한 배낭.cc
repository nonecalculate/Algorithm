#include <iostream>

#define WEIGHT 0
#define VALUE 1

int dp[101][100001];
int weight[101];
int value[101];
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> weight[i]>>value[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= K; w++) {
            if (weight[i] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i]] + value[i]);
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << dp[N][K];
    return 0;
}