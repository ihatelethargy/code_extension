#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

// 7   1 2 3 4 5 6 7 
void rottoMaker(int rottoSize) {
	vector<int>n;		// 전체 '숫자' 넣을 벡터
	
	for (int i = 0;i < rottoSize;i++) {		// '숫자' 입력
		int temp;
		scanf("%d", &temp);
		n.push_back(temp);
	}
	
	

	int k = 6; // 6개 뽑음

	vector<int>bi;
	for (int i = 0;i < k;i++) {		// 6개의 1 저장
		bi.push_back(0);
	}

	for (int i = 0;i < rottoSize - k;i++) {	// 전체숫자(rottoSize) - 6 의 0 저장 선택 못받는것
		bi.push_back(1);
	} 

	sort(bi.begin(), bi.end());

	do {
		for (int i = 0;i < rottoSize;i++) {
			if (bi[i] == 0) {
				printf("%d ", n[i]);
			}
		}
		printf("\n");

	} while (next_permutation(bi.begin(), bi.end()));
}


int main() {
	while (1) {
		int rottoSize;
		scanf("%d", &rottoSize);
		if (rottoSize == 0) break;
		else {
			rottoMaker(rottoSize);
			printf("\n");
		}
	}
}