#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#define MAXSIZE 1+8

using namespace std;

int n, m;
int x, y, z;

int cmp1, cmp2 = 0;


vector<int> V, vec, cmp;
bool visited[MAXSIZE];


void func(int cnt)
{

	if (m == cnt)
	{
		if (cmp.empty())
		{
			for (int i = 0; i < m; ++i)
			{
				cout << vec[i] << " ";
				cmp.push_back(vec[i]);
			}
			cout << "\n";
			return;
		}
		else
		{
			int count = 0;
			for (int i = 0; i < m; ++i)
			{
				if (cmp[i] != vec[i])
				{
					count = count + 1;

				}

			}

			if (count != 0)
			{
				cmp.clear();
				for (int i = 0; i < m; ++i)
				{

					cout << vec[i] << " ";
					cmp.push_back(vec[i]);
				}
				cout << "\n";
				return;
			}

		}
	}

	int before = -1;

	for (int i = 0; i < n; ++i)
	{


		if (visited[i] == false && (i == 0 || before != V[i]))
		{
			before = V[i];

			vec.push_back(V[i]);
			func(cnt + 1);

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




	func(0);

}
