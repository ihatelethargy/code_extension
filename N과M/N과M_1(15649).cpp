#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// go(0,n,m)
// n = 4 m = 2 
bool c[10]; int a[10];
void go(int index, int n, int m) {
	if (index == m) {
		// ���� ���
		for (int i = 0;i < m;i++) {
			printf("%d ", a[i]);
			
		}
		printf("\n");
		return;
	}
	for (int i = 1;i <= n;i++) {		// �� �� �ִ� �ڿ��� 1~n ����
		if (c[i]) continue;				// �ߺ� Ȯ��!
		c[i] = true;					// ��������ϱ� true
		a[index] = i;					// a[index]�� i ��
		go(index + 1, n, m);
		c[i] = false;					// ��� ��
	}
}

int main() {
	int n; int m;
	scanf("%d %d", &n, &m);
	go(0, n, m);
}