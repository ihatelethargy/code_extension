/*
�����佺�׳׽��� ü
*/

#include <cstdio>
const int MAX = 1000000;
bool prime[MAX + 1];

// true �� �Ϲݼ�
// 0(��������) �� �Ҽ�
int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	prime[1] = true;
	for (int i = 2;i*i <= MAX;i++) {	// �Ҽ� ����
		if (!prime[i]) {				// false �ΰ� �߿� <�� �� ����> ����� �� true ��! 
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