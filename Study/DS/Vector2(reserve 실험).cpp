#include<iostream>
#include<chrono>
#include<vector>

using namespace std;
int main() {
	const int N = 10'000'000;
//reserve 없이 할당
	{
		vector<int> v;
		auto start = chrono::high_resolution_clock::now();

		for (int i = 0; i < N; i++) 
			v.push_back(i);

		auto end = chrono::high_resolution_clock::now();
		cout << "No reserve: "
			<< chrono::duration<double>(end - start).count()
			<< "s\n";
	}
//reserve 있이 할당
	{
		vector<int> v;
		v.reserve(N);
		auto start = chrono::high_resolution_clock::now();

		for (int i = 0; i < N; i++)
			v.push_back(i);

		auto end = chrono::high_resolution_clock::now();
		cout << "With reserve: "
			<< chrono::duration<double>(end - start).count()
			<< "s\n";
	}
}

/*
  실행 결과

  No reserve: 0.450227s
  With reserve: 0.39681s

  역순으로 실행해도 비슷한 결과가 나오는 걸 보아하니 효과가있음.
*/
