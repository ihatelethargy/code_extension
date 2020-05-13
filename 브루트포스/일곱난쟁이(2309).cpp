#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define trash 987654321
#define MAX 9

int main() {
	vector<int> arr;
	bool check = false;
	int sum = 0;
	int num;

	for (int i = 0;i < 9;i++) {
		cin >> num;
		arr.push_back(num);
		sum += arr[i];
	}

	for (int i = 0;i < MAX;i++) {
		for (int j = i + 1;j < MAX;j++) {
			if (arr[i] + arr[j] == sum - 100) {
				arr[i] = trash;
				arr[j] = trash;
				check = true;
				break;
			}
		}
		if (check) break;
	}

	sort(arr.begin(), arr.end());
	for (int i = 0;i < 7;i++) {
		cout << arr[i] << endl;
	}
}

/*
vector
vector<int>arr;
arr.push_back(num);
sort(arr.begin(),arr.end());
*/