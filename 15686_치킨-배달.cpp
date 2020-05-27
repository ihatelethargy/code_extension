#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, m, h_size, c_size, ans = INT_MAX;
vector<pair<int, int>> h, c;
bool vis[13];

int dist(pair<int, int> x, pair<int, int> y)
{
    return abs(x.first - y.first) + abs(x.second - y.second);
}

int calc()
{
    int ret(0);

    for (int i = 0; i < h_size; i++)
    {
        int tmp = INT_MAX;

        for (int j = 0; j < c_size; j++)
        {
            if (vis[j])
                tmp = min(tmp, dist(h[i], c[j]));
        }

        ret += tmp;
    }

    return ret;
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int v;
            cin >> v;

            if (v == 1)
                h.push_back({i, j});

            if (v == 2)
                c.push_back({i, j});
        }
    }
    h_size = static_cast<int>(h.size());
    c_size = static_cast<int>(c.size());
}

void dfs(int x, int cnt)
{
    if (cnt == m)
        ans = min(ans, calc());

    for (int i = x; i < c_size; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            dfs(i, cnt + 1);
            vis[i] = false;
        }
    }
}

void solve()
{
    dfs(0, 0);
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
}
