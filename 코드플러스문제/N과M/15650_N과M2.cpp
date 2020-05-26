#include <iostream>
#include<string>
#include<algorithm>
#include<vector>

#define MAXSIZE 1+8

using namespace std;


vector<int> V;
int n, m;
bool visited[MAXSIZE];


void func(int idx, int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < V.size(); i++)
		{
			cout << V[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = idx; i < n; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			V.push_back(i + 1);
			func(i, cnt + 1);
			V.pop_back();
			visited[i] = false;

		}
	}


}

int main() {

	cin >> n >> m;
	func(0, 0);


}
