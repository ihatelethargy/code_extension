#include <iostream>
using namespace std;

int main() {
	int e, s, m;
	
	cin >> e >> s >> m;
	int E = 0;
	int S = 0;
	int M = 0;
	
	for (int i = 0;;i++) {
		if (E == e && S == s && M == m) {
			cout << i;
			break;
		}
		E++;
		S++;
		M++;
		if (E == 16) {
			E = 1;
		}
		if (S == 29) {
			S = 1;
		}
		if (M == 20) {
			M = 1;
		}
	}
}