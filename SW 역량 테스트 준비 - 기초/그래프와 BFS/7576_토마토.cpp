#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int m, n;
vector<vector<int>> matrix;
queue<pair<int, int>> q;

void input()
{
    cin >> m >> n;
    matrix = vector<vector<int>>(n, vector<int>(m, 0));
    for (int row = 0; row < n; row++)
        for (int col = 0; col < m; col++)
            cin >> matrix[row][col];
}

int solve()
{
    int ans = 0;

    for (int row = 0; row < n; row++)
        for (int col = 0; col < m; col++)
            if (matrix[row][col] == 1)
                q.push({row, col});

    int q_size = static_cast<int>(q.size());
    int popped = 0;

    auto inside = [&](int r, int c) {
        return 0 <= r && r < n && 0 <= c && c < m;
    };

    auto insert = [&](int r, int c) {
        for (auto &[_r, _c] : directions)
        {
            int nr = r + _r;
            int nc = c + _c;

            if (inside(nr, nc) && matrix[nr][nc] == 0)
            {
                q.push({nr, nc});
                matrix[nr][nc] = 1;
            }
        }
    };

    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        popped++;

        insert(r, c);

        if (popped == q_size)
        {
            ans++;
            popped = 0;
            q_size = static_cast<int>(q.size());
        }
    }

    for (auto r : matrix)
        for (auto c : r)
            if (c == 0)
                return -1;

    return ans - 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    cout << solve() << endl;
}