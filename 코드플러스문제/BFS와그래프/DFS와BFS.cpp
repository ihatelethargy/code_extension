#include<iostream>
#include<queue>
#include<vector>


using namespace std;

int x, y, z;

int a, b;
vector<int>V;
vector<int>vec;
queue<int>q;

bool bisited[1001];
bool visited[1001];

int arr[1001][1001];


void bfs(int z) {

	q.push(z);

	bisited[z] = true;

	while (!q.empty())
	{
		for (int i = 1; i <= x; ++i)
		{
			if (bisited[i] == false)
			{
				if (arr[q.front()][i] == 1)
				{
					q.push(i);
					bisited[i] = true;
				}
			}

		}
		V.push_back(q.front());
		q.pop();

	}


	for (int i = 0; i < V.size(); ++i)
	{
		cout << V[i] << " ";

	}

}




void dfs(int cnt)
{

	vec.push_back(cnt);
	visited[cnt] = true;

	for (int i = 1; i <= x; ++i)
	{
		if (visited[i] == false)
		{
			if (arr[cnt][i] == 1)
			{
				dfs(i);
			}
		}
	}


}


void input() {

	cin >> x >> y >> z;

	for (int i = 0; i < y; ++i)
	{
		cin >> a >> b;

		arr[a][b] = 1;
		arr[b][a] = 1;

	}


}

int main() {

	input();

	dfs(z);
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << " ";

	}
	cout << "\n";

	bfs(z);


}