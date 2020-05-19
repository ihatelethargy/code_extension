#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* STL »ç¿ë*/
int main() {
	int n;
	scanf("%d", &n);
	vector<int>arr(n);

	for (int i = 0;i < n;i++) {
		scanf("%d", &arr[i]);
	}
	bool c;
	for (int i = 0;i < n-1;i++) {
		if (arr[i] < arr[i + 1]) {
			c = 0;
			break;
		}
		else {
			c = 1;
		}
	}
	if (!c) {
		next_permutation(arr.begin(), arr.end());
		for (int i = 0;i < n;i++) {
			printf("%d ", arr[i]);
		}
	}
	else if(c) printf("%d",-1);

}