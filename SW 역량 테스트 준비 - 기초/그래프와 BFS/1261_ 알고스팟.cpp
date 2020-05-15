#include <bits/stdc++.h>
#define endl "\n"
#define pipii pair<int, pair<int, int>>
using namespace std;
vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int m, n;
vector<string> matrix;
vector<vector<bool>> vis;
priority_queue<pipii, vector<pipii>, greater<pipii>> min_heap;

void input()
{
    cin >> m >> n;
    matrix.resize(n);
    vis = vector<vector<bool>>(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
        cin >> matrix[i];
}

void solve()
{
    int ans{-1};
    vis[0][0] = true;
    min_heap.push({0, {0, 0}});

    auto inside = [&](int r, int c) {
        return 0 <= r && r < n && 0 <= c && c < m;
    };

    auto insert = [&](int breaked, int r, int c) {
        for (auto &[_r, _c] : directions)
        {
            int nr = r + _r;
            int nc = c + _c;

            if (inside(nr, nc) && !vis[nr][nc])
            {
                vis[nr][nc] = true;
                min_heap.push({matrix[nr][nc] == '1' ? breaked + 1 : breaked, {nr, nc}});
            }
        }
    };

    while (!min_heap.empty())
    {
        auto [breaked, pos] = min_heap.top();
        auto [r, c] = pos;
        min_heap.pop();

        if (r == n - 1 && c == m - 1)
        {
            ans = breaked;
            break;
        }

        insert(breaked, r, c);
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
}