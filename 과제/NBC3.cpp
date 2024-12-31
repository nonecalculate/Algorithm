#include <iostream>
#include <algorithm>

using namespace std;

template <typename T> //템플릿 사용을 위한 typename T
class SimpleVector {
private:
	T* data; //동적 배열을 위한 포인터 멤버
	int currentSize = 0;
	int currentCapacity = 0;
public:
	void resize(int newCapacity)  //값 재할당
	{
		if (newCapacity < currentCapacity) return;	// 새 값이 현재값보다 작으면 return
		T* tempData = new T[newCapacity];			// 재할당 받은 값 크기만큼의 배열 생성
		for (int i = 0; i < currentCapacity; i++)	// 본래 크기만큼 가지고 있는 값을 임시배열 tempData에 초기화
		{
			tempData[i] = data[i];
		}
		delete[] data;								// 원래 data값 delete
		data = tempData;							// data에 tempData 덮어쓰기
		currentCapacity = newCapacity;				// 현재 값에 새 값 덮어쓰기
	}
	SimpleVector() : data(nullptr)					// data를 일단 nullptr로 초기화
	{
		resize(10);
	}
	SimpleVector(int capacity) : data(nullptr)		// data를 일단 nullptr로 초기화
	{
		resize(capacity);
	}
	SimpleVector(const SimpleVector& other) : data(new T[other.currentCapacity]),
		currentSize(other.currentSize),
		currentCapacity(other.currentCapacity)			// 복사 생성자 초기화 리스트
	{
		for (int i = 0; i < other.currentSize; i++)		
		{
			this->data[i] = other.data[i];
		}
	}
	~SimpleVector()									// 소멸자 data 삭제
	{
		delete[] data;
	}
	void push_back(const T& value)					// 입력값 넣기
	{
		if (currentSize == currentCapacity)			// 만약 값이 다 차있으면 실행
		{
			resize(currentCapacity + 5);			// currentCapacity는 resize안에서 초기화 되니 바로 + 5;
		}
		data[currentSize++] = value;				// 값이 안차있으면 if문을 빠져나가 작동하고 다 차있으면 사이즈 +5 인상태로 작동
		return;
	}
	void pop_back()									
	{
		if (currentSize > 0) currentSize--;			// currentSize만 줄여 접근이 불가능하게 만들고 push_back 하면 자연스럽게 pop된 값이 변경됨
	}
	int size() 
	{
		return currentSize;
	}
	int capacity() 
	{
		return currentCapacity;
	}
	void sortData() 
	{
		sort(data, data + currentSize);				// sort함수를 사용하여 바로 값 sort
		return;
	}
	void show()										//확인용 show 함수
	{
		cout << "{";
		for (int i = 0; i < currentSize; i++) {
			cout << data[i];
			if (i < currentSize - 1) {
				cout << " ,";
			}
		}
		cout << "}" << endl;
		return;
	}
};

int main() {
	SimpleVector<int> a;
	a.push_back(1);
	a.push_back(9);
	a.push_back(3);
	a.push_back(7);
	a.push_back(5);
	a.show();
	a.sortData();
	a.show();
	return 0;
}
