#include <iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>

#define MAXSIZE 1000+1

using namespace std;

int N, M;
int a, b;

vector<int> V[MAXSIZE];
bool visited[MAXSIZE];


void func(int node) {

	visited[node] = true;

	for (int i = 0; i < V[node].size(); ++i)
	{
		int next = V[node][i];

		if (visited[next] == false)
		{

			func(next);

		}

	}


}





void input() {

	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}

}




int main() {

	input();

	int cnt = 0;

	for (int i = 1; i <= N; ++i)
	{
		if (visited[i] == false)
		{
			func(i);
			cnt++;

		}
	}

	cout << cnt;


}



