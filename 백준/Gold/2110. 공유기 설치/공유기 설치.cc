#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N = 0;
	int C = 0;
    cin >> N >> C;
	vector<int> house(N);
	for (int i = 0; i < N; i++) {
		cin >> house[i];
	}
	sort(house.begin(), house.end());
    long long left = 1;
    long long right = house.back() - house.front();
    long long ans = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        int count = 1;
        int last_installed = house[0];

        for (int i = 1; i < N; i++) {
            if (house[i] - last_installed >= mid) {
                count++;
                last_installed = house[i];
            }
        }

        if (count >= C) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}