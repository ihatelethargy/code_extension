#include <iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

#define MAXSIZE 1+8
int n, m;
int x, y, z;

vector<int> V, vec;
bool visited[MAXSIZE];


void func(int idx, int cnt)
{

	if (m == cnt)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << vec[i] << " ";

		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < n; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			vec.push_back(V[i]);
			func(i, cnt + 1);

			vec.pop_back();

			visited[i] = false;

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
