#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int k;
	scanf("%d", &k);

	vector<int>arr;
	for (int i = 0;i < k;i++) {
		int temp;
		scanf("%d", &temp);
		arr.push_back(temp);
	}
	sort(arr.begin(),arr.end());
	int max = 0;
	int sum;
	do {				// k = 6
		sum = 0;
		for (int i = 0;i < k-1;i++) {				
			sum += abs(arr[i] - arr[i + 1]);
		}
		
		if (sum > max) {
			max = sum;
		}

	} while (next_permutation(arr.begin(),arr.end()));
	
	printf("%d", max);
}