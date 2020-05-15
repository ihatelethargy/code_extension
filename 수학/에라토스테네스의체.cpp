/*
에라토스테네스의 체
*/

#include <cstdio>
const int MAX = 1000000;
bool prime[MAX + 1];

// true 가 일반수
// 0(지워진거) 가 소수
int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	prime[1] = true;
	for (int i = 2;i*i <= MAX;i++) {	// 소수 범위
		if (!prime[i]) {				// false 인것 중에 <그 값 빼고> 배수는 다 true 로! 
			for (int j = (i*i) % MAX;j <= MAX;j += i) {
				prime[j] = true;
			}
		}
	}
	for (int i = m;i <= n;i++) {
		if (!prime[i]) printf("%d\n", i);
	}
	return 0;
}