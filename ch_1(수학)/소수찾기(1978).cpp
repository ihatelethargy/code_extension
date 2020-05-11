#include <iostream>
#include <algorithm>
using namespace std;


bool prime(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2;i*i <= n;i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	int counter=0;
	int size;
	cin >> size;
	long long *arr = new long long[size];
	for (int i = 0;i < size;i++) cin >> arr[i];
	
	for (int i = 0;i < size;i++) {
		if (prime(arr[i]) == 1) {
			counter++;
		}
	}
	cout << counter;
	delete[]arr;
}



/*
----------primeNumber(1)----------
1. 2���� ũ�ų� ����
2. n - 1���� �۰ų� ���� �ڿ����� ������ �������� X

bool prime(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2;i <= n - 1;i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
*/


/*
----------primeNumber(2)----------
1. 2���� ũ�ų� ����.
2. N/2 ���� �۰ų� ���� �ڿ����� ������ �������� �ȵȴ�.
bool prime(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2;i <= n / 2;i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
*/

/*
----------primeNumber(3)----------
1. 2���� ũ�ų� ����.
2. ��Ʈ N ���� �۰ų� ���� �ڿ����� ������ �������� �ȵȴ�. => i*i <= n
bool prime(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2;i*i <= n;i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}
*/