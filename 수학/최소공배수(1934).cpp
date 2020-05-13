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
	int t;
	cin >> t;
	int *lcm = new int[t];
	int a, b;
	for (int i = 0;i < t;i++) {
		cin >> a >> b;
		lcm[i] = a * b / gcd(a, b);
	}

	for (int i = 0;i < t;i++) {
		cout << lcm[i] << endl;
	}

	delete[]lcm;
}