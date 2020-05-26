#include <iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

#define MAXSIZE 1+8
int n, m;
vector<int> V;
bool visited[MAXSIZE];


void func(int idx, int cnt) {

	if (m == cnt)
	{
		for (int i = 0; i < V.size(); ++i)
		{
			cout << V[i] << " ";

		}
		cout << "\n";
		return;

	}

	for (int i = idx; i < n; ++i)
	{
		if (!visited[i])
		{
			V.push_back(i + 1);
			func(i, cnt + 1);
			V.pop_back();

		}
	}


}



int main() {

	cin >> n >> m;
	func(0, 0);


}