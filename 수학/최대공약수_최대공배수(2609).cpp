#include <iostream>
#include <algorithm>
using namespace std;
/*
----------GCD(normal)----------
int main() {
	int g = 1;
	int a, b;
	cin >> a >> b;
	for (int i = 2;i <= min(a, b);i++) {
		if (a % i == 0 && b % i == 0) {
			g = i;
		}
	}
	cout << g;
}
*/

/*
----------GCD(with recursive function)----------
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}
}
gcd(a, b)
*/
/*
----------GCD(without recursive function)----------
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
*/

/*
----------LCM----------
LCM(a,b) => (a * b) / GCD
*/

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}
}

int main() {
	int num1, num2;
	cin >> num1 >> num2;
	int g = gcd(num1, num2);
	cout << g << endl
		<< num1*num2 / g;
}