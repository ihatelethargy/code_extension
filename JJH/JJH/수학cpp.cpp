#include <iostream>
#include <algorithm>
using namespace std;

/*
나머지
(A + B)%C == (A%B + B%C)%C
(A X B)%C == (A%B X B%C)%C
*/

/*
최대공약수
*/

int main() {
	int g = 1;
	int a = 18;
	int b = 24;
	for (int i = 2;i <= min(a, b);i++) {
		if (a % i == 0 && b%i == 0) {
			g = i;
		}
	}
	cout << g;
}


