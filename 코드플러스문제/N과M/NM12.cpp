#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#define MAXSIZE 1+8

using namespace std;

vector<int>V, vec;
bool visited[MAXSIZE];
int n, m;
int x;


void func(int idx, int cnt) {

	if (cnt == m)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << vec[i] << " ";

		}
		cout << "\n";
		return;

	}

	int before = -1;
	for (int i = idx; i < n; ++i)
	{
		if (!visited[i] && (i == 0 || before != V[i]))
		{
			before = V[i];
			vec.push_back(V[i]);
			func(i, cnt + 1);
			vec.pop_back();

		}

	}

}


int main() {


	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		V.push_back(x);

	}
	sort(V.begin(), V.end());


	func(0, 0);



}