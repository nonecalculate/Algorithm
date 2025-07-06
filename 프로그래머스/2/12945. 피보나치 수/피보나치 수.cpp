#include <string>
#include <vector>

using namespace std;


int solution(int n) {
    int answer = 0;
    int MOD = 1234567;
    int a = 0, b = 1;

    for (int i = 2; i <= n; ++i) {
        int next = (a + b) % MOD;
        a = b;
        b = next;
    }
    return answer = b;
}