#include <iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;


#define MAXSIZE 7+1

bool visited[MAXSIZE];
vector<int> V;
int n, m;


void func(int cnt)
{
	if (m == cnt)
	{
		for (int i = 0; i < V.size(); i++)
		{
			cout << V[i] << " ";

		}
		cout << "\n";
		return;

	}

	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{

			V.push_back(i);
			func(cnt + 1);
			V.pop_back();

		}
	}


}


int main() {

	cin >> n >> m;
	func(0);

}
