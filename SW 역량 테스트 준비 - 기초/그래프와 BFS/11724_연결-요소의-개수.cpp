#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
queue<int> q;

void input()
{
    cin >> n >> m;
    adj.resize(n + 1);
    visited = vector<bool>(n + 1, false);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj.at(u).push_back(v);
        adj.at(v).push_back(u);
    }
}

void dfs(int node)
{
    visited[node] = true;

    for (auto next : adj.at(node))
    {
        if (!visited[next])
            dfs(next);
    }
}

void bfs(int node)
{
    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto next : adj.at(front))
        {
            if (!visited[next])
            {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main()
{
    fastIO;
    input();

    int ans = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            // dfs(i);
            bfs(i);
            ans++;
        }
    }

    cout << ans << endl;
}