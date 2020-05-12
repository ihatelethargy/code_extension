#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

int n, m;
vector<int> v;
vector<bool> vis;

void input()
{
    cin >> n >> m;
    vis = vector<bool>(n + 1);
}

void dfs(int cnt)
{
    if (cnt == m)
    {
        for (auto el : v)
            cout << el << " ";
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            v.push_back(i);
            dfs(cnt + 1);
            vis[i] = false;
            v.pop_back();
        }
    }
}

int main()
{
    fastIO;
    input();
    dfs(0);
}