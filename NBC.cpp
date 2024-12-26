#include<iostream>

using namespace std;

int sum(int a[],int size)   //���ϱ� �Լ�
{ 
	
	int all = 0;

	for (int i = 0; i < size; i++) {
		all += a[i];
	}

	return all;
}
double avg(int b,int size)   //��� �Լ�
{
	return (double)b / size; //�Ҽ��� ���ϸ� ǥ���ϱ� ���� (double) ����
}

int bubble(int a[], int size) //�������� �Լ�
{
	int select = 0;
	int temp = 0;
	while (select != 3) {     //����

		cout << endl << "1 ���� ��������, 2 ���� ��������, 3���� ������ :";

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
		else if (select == 3) { cout << "����� �ѹ� �� �����帮�� �����ڽ��ϴ�."; }
		else { cout << "Ʋ�� �Է��Դϴ�. ���� �迭�� �����Դϴ�."; }

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
		cout << "ũ�⸦ ���ϼ��� : ";
		cin >> size;
		if (size <= 0) cout << "���� ������ �� �����ϴ�.";
		else {
			int* score = new int[size] {0};

			for (int i = 0; i < size; i++) {
				cout << i + 1 << "��° ���ڸ� �Է����ּ���";
				cin >> score[i];
				cout << endl;
			}

			cout << avg(sum(score, size), size);

			bubble(score, size);

			delete score; //�����Ҵ� ����
		}
		cout <<endl << "���� �ٲٷ��� 1��, �������� 2���� �Է����ּ���:";
		cin >> k;

	}
	return 0;
}