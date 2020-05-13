#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

int n, m, v;
bitset<1001> adj[1001];
bitset<1001> vis;
queue<int> q;

void input()
{
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        adj[from][to] = 1;
        adj[to][from] = 1;
    }
}

void dfs(int node)
{
    cout << node << " ";
    vis[node] = 1;

    for (int i = 1; i <= n; i++)
        if (adj[node][i] && !vis[i])
            dfs(i);
}

void bfs(int node)
{
    cout << endl;
    q.push(node);
    vis[node] = 1;

    while (!q.empty())
    {
        int _node = q.front();
        q.pop();
        cout << _node << " ";

        for (int i = 1; i <= n; i++)
        {
            if (adj[_node][i] && !vis[i])
            {
                q.push(i);
                vis[i] = 1;
            }
        }
    }

    cout << endl;
}

int main()
{
    fastIO;
    input();
    dfs(v);
    vis.reset();
    bfs(v);
}