#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}
}
int main() {
	int T;	// line 수 1~100
	cin >> T;
	int t; // 입력 숫자 수 1~100
	long long *sum = new long long[T];
	for (int i = 0;i < T;i++) {
		cin >> t;
		int *arr = new int[t];
		for (int j = 0;j < t;j++) {
			cin >> arr[j];
		}
		sum[i] = 0;
		for (int k = 0;k < t;k++) {
			for (int l = 0;l < k;l++) {

				sum[i] += gcd(arr[k], arr[l]);
			}
		}
		delete []arr;
	}
	for (int i = 0;i < T;i++) {
		cout << sum[i] << endl;
	}
	delete[]sum;
}
