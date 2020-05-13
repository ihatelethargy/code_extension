#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main() {
	int t, i;
	int a, b;
	cin >> t;
	int lcm[1000];

	for (i = 0; i < t; i++) {
		cin >> a >> b;
		lcm[i] = (a * b) / gcd(a, b);
	}

	for (i = 0; i < t; i++) {
		cout << lcm[i] << endl;
	}






}