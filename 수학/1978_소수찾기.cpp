#include <iostream>

using namespace std;

bool prime(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main() {
	int cnt = 0;
	int n;
	int num[100];

	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];

	for (int i = 0; i < n; i++) {
		if (prime(num[i]) == 1)
			cnt++;
	}

	cout << cnt << endl;

}