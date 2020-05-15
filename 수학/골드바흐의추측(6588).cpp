#include <cstdio>

const int MAX = 1000000;
bool prime[MAX + 1];


int main() {
	prime[1] = true;
	for (int i = 2;i*i <= MAX;i++) {
		if (!prime[i]) {
			for (int j = i * i;j <= MAX;j += i) {
				prime[j] = true;
			}
		}
	}

	while (1) {
		int m;
		scanf("%d", &m);
		if (m == 0) break;
		for (int i = 2;i <= MAX;i++) {
			if (prime[i] == false) {
				int j = m - i;
				if (!prime[j]) {
					printf("%d = %d + %d\n", m, i, j);
					break;
				}
			}
		}
	}

	return 0;
}