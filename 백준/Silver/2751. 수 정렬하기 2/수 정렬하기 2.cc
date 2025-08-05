#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> arr;
int N = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++)cin >> arr[i];

    sort(arr.begin(),arr.end());

    for (int i = 0; i < N; i++)cout << arr[i] << "\n";
    return 0;
}