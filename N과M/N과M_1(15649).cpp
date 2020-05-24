#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// go(0,n,m)
// n = 4 m = 2 
bool c[10]; int a[10];
void go(int index, int n, int m) {
	if (index == m) {
		// 수열 출력
		for (int i = 0;i < m;i++) {
			printf("%d ", a[i]);
			
		}
		printf("\n");
		return;
	}
	for (int i = 1;i <= n;i++) {		// 들어갈 수 있는 자연수 1~n 까지
		if (c[i]) continue;				// 중복 확인!
		c[i] = true;					// 사용했으니까 true
		a[index] = i;					// a[index]에 i 값
		go(index + 1, n, m);
		c[i] = false;					// 사용 끝
	}
}

int main() {
	int n; int m;
	scanf("%d %d", &n, &m);
	go(0, n, m);
}