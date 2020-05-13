#include <iostream>
#include <algorithm>
using namespace std;

bool prime(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2;i <= n / 2;i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	int counter = 0;
	int *arr = new int[100001];
	arr[counter] = 1;

	while (1) {
		if (arr[counter - 1] == 0) { break; }
		cin >> arr[counter];
		counter++;
	}

	for (int i = 0;i < counter - 1;i++) {
		for (int j = 2; j < arr[i];j++) {
			if (prime(j) == 1 && prime(arr[i] - j) == 1) {
				cout << arr[i] << " = " << j << " + " << arr[i] - j << endl;
				break;
			}
		}
	}
	delete[]arr;
}