#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int w, h;
vector<vector<int>> matrix;
queue<pair<int, int>> q;

void input()
{
    matrix = vector<vector<int>>(h, vector<int>(w));
    for (int row = 0; row < h; row++)
        for (int col = 0; col < w; col++)
            cin >> matrix[row][col];
}

void bfs(int row, int col)
{
    matrix[row][col] = 0;
    q.push({row, col});

    auto inside = [&](int r, int c) {
        return 0 <= r && r < h && 0 <= c && c < w;
    };

    auto insert = [&](int r, int c) {
        for (auto &[_r, _c] : directions)
        {
            int nr = r + _r;
            int nc = c + _c;
            if (inside(nr, nc) && matrix[nr][nc] == 1)
            {
                q.push({nr, nc});
                matrix[nr][nc] = 0;
            }
        }
    };

    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        insert(r, c);
    }
}

void solve()
{
    int ans = 0;

    for (int row = 0; row < h; row++)
    {
        for (int col = 0; col < w; col++)
        {
            if (matrix[row][col] == 1)
            {
                bfs(row, col);
                ans++;
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> w >> h)
    {
        if (w == 0 && h == 0)
            break;

        input();
        solve();
    }
}