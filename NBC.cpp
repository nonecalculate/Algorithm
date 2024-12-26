#include<iostream>

using namespace std;

int sum(int a[],int size)   //더하기 함수
{ 
	
	int all = 0;

	for (int i = 0; i < size; i++) {
		all += a[i];
	}

	return all;
}
double avg(int b,int size)   //평균 함수
{
	return (double)b / size; //소수점 이하를 표현하기 위한 (double) 삽입
}

int bubble(int a[], int size) //버블정렬 함수
{
	int select = 0;
	int temp = 0;
	while (select != 3) {     //재사용

		cout << endl << "1 번은 오름차순, 2 번은 내림차순, 3번은 끝내기 :";

		cin >> select;

		if (select == 1) {
			for (int i = size - 1; i > 0; i--) {
				for (int j = 0; j < i; j++) {
					if (a[j] > a[j + 1]) {
						temp = a[j];
						a[j] = a[j + 1];
						a[j + 1] = temp;
					}
				}
			}
		}
		else if (select == 2) {
			for (int i = size - 1; i > 0; i--) {
				for (int j = 0; j < i; j++) {
					if (a[j] < a[j + 1]) {
						temp = a[j];
						a[j] = a[j + 1];
						a[j + 1] = temp;
					}
				}
			}
		}
		else if (select == 3) { cout << "결과를 한번 더 보여드리고 끝내겠습니다."; }
		else { cout << "틀린 입력입니다. 현재 배열의 상태입니다."; }

		for (int i = 0; i < size; i++) {
			cout << endl << a[i];
		}
	}
	return 0;
}

int main() {
	int k = 0;
	while (k != 2) 
	{
		int size = 0;
		cout << "크기를 정하세요 : ";
		cin >> size;
		if (size <= 0) cout << "값이 성립할 수 없습니다.";
		else {
			int* score = new int[size] {0};

			for (int i = 0; i < size; i++) {
				cout << i + 1 << "번째 숫자를 입력해주세요";
				cin >> score[i];
				cout << endl;
			}

			cout << avg(sum(score, size), size);

			bubble(score, size);

			delete score; //동적할당 제거
		}
		cout <<endl << "값을 바꾸려면 1번, 끝내려면 2번을 입력해주세요:";
		cin >> k;

	}
	return 0;
}