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
1. 2보다 크거나 같다
2. n - 1보다 작거나 같은 자연수로 나누어 떨어지면 X

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
1. 2보다 크거나 같다.
2. N/2 보다 작거나 같은 자연수로 나누어 떨어지면 안된다.
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
1. 2보다 크거나 같다.
2. 루트 N 보다 작거나 같은 자연수로 나누어 떨어지면 안된다. => i*i <= n
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