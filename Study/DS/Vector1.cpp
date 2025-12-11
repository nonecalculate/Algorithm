#include<iostream>
#include<vector>

using namespace std;
int main() {
	vector<int> v;
	v.reserve(0);
	for (int i = 0; i < 100; i++)
	{
		cout << "i= " << i
			<< " | size = " << v.size()
			<< " | capacity = " << v.capacity() << endl;
		v.push_back(i);
	}
}

//capacity 증가 실험
