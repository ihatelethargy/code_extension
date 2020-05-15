#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n, m;
vector<string> matrix;
bool vis[1001][1001][2];
queue<tuple<int, int, bool, int>> q; // {row, col, breaked, cost}

void input()
{
    cin >> n >> m;
    matrix.resize(n);
    for (int i = 0; i < n; i++)
        cin >> matrix[i];
}

void solve()
{
    int ans(-1);
    vis[0][0][0] = true;
    q.push({0, 0, 0, 1});

    auto inside = [&](int r, int c) {
        return 0 <= r && r < n && 0 <= c && c < m;
    };

    while (!q.empty())
    {
        auto &[r, c, breaked, cost] = q.front();
        q.pop();

        if (r == n - 1 && c == m - 1)
        {
            ans = cost;
            break;
        }

        for (auto &[_r, _c] : directions)
        {
            int nr = r + _r;
            int nc = c + _c;

            if (inside(nr, nc))
            {
                if (matrix[nr][nc] == '0' && !vis[nr][nc][breaked])
                {
                    vis[nr][nc][breaked] = true;
                    q.push({nr, nc, breaked, cost + 1});
                }

                if (!breaked && matrix[nr][nc] == '1' && !vis[nr][nc][1])
                {
                    vis[nr][nc][1] = true;
                    q.push({nr, nc, true, cost + 1});
                }
            }
        }
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