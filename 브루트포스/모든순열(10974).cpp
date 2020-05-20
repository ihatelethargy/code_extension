#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int k;
	scanf("%d", &k);
	vector<int>arr;

	for (int i = 0;i < k;i++) {
		arr.push_back(i + 1);
	}

	do {
		for (int i = 0;i < k;i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	} while (next_permutation(arr.begin(), arr.end()));
}