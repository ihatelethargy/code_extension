#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int v, e;
vector<vector<int>> adj;
vector<char> color;

bool dfs(int node, char c)
{
    color[node] = c;

    for (auto next : adj[node])
    {
        if (color[next] == 'U' && !dfs(next, (c == 'R' ? 'B' : 'R')))
            return false;
        else if (color[node] == color[next])
            return false;
    }

    return true;
}

void check()
{
    for (int i = 1; i <= v; i++)
    {
        if (color[i] == 'U' && !dfs(i, 'R'))
        {
            cout << "NO" << endl;
            ;
            return;
        }
    }

    cout << "YES" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;

    while (k--)
    {
        cin >> v >> e;
        adj = vector<vector<int>>(v + 1);
        color = vector<char>(v + 1, 'U');

        while (e--)
        {
            int from, to;
            cin >> from >> to;
            adj[from].push_back(to);
            adj[to].push_back(from);
        }

        check();
    }
}