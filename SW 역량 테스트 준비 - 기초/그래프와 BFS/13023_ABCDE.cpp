#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

// 인접행렬로 표현하면 시간 초과
int n, m;
vector<vector<int>> adj;
bitset<2000> vis;
bool ok;

void input()
{
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

void dfs(int node, int cnt)
{
    if (cnt == 4)
    {
        ok = true;
        return;
    }

    int size = static_cast<int>(adj[node].size());

    for (int i = 0; i < size; i++)
    {
        if (ok)
            return;

        int next = adj[node][i];

        if (!vis[next])
        {
            vis[next] = 1;
            dfs(next, cnt + 1);
            vis[next] = 0;
        }
    }
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        if (ok)
            return;

        vis[i] = 1;
        dfs(i, 0);
        vis[i] = 0;
    }
}

int main()
{
    fastIO;
    input();
    solve();
    cout << (ok ? 1 : 0) << endl;
}