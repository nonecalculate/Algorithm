#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    int k = 0;
    int t = 0;
    vector<int> arr;
    while (k == 0) 
    {
        arr.push_back(n % 10);
        n = n / 10;
        t++;
        if (n == 0) k++;
    }
    for (int i = 0 ; i < arr.size() - 1; i++)
    {
        int temp = 0;
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] < arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < t - 1; i++) 
    {
        k = k * 10;
    }
    for (int i = 0; i < arr.size(); i++) 
    {
        answer += k * arr[i];
        k /= 10;
    }
    return answer;
}