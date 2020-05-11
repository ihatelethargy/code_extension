#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	
	int line1 = (a + b) % c;
	int line2 = (a % c + b % c) % c;
	int line3 = (a * b) % c;
	int line4 = (a % c * b % c) % c;
	
	
	cout << line1 << endl
		<< line1 << endl
		<< line3 << endl
		<< line4 << endl;
}

/*

line1 == line2
line3 == line4

*/