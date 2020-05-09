#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;
vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> vis;

void input()
{
    cin >> n >> m;
    grid = vector<vector<int>>(n, vector<int>(m, 0));
    vis = vector<vector<bool>>(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];
}

int dfs(int row, int col, int cnt)
{
    if (cnt == 4)
        return grid[row][col];

    auto inside = [&](int r, int c) { return 0 <= r && r < n && 0 <= c && c < m; };
    int sum = 0;

    for (auto &dir : directions)
    {
        int new_row = row + dir.first;
        int new_col = col + dir.second;

        if (inside(new_row, new_col) && !vis[new_row][new_col])
        {
            vis[new_row][new_col] = true;
            sum = max(sum, grid[row][col] + dfs(new_row, new_col, cnt + 1));
            vis[new_row][new_col] = false;
        }
    }

    return sum;
}

int edge_case(int row, int col)
{
    int sum = 0;

    if (row > 0 && row < n - 1 && col < m - 1)
        sum = max(sum, grid[row][col] + grid[row - 1][col] + grid[row + 1][col] + grid[row][col + 1]);

    if (row > 0 && row < n - 1 && col > 0)
        sum = max(sum, grid[row][col] + grid[row - 1][col] + grid[row + 1][col] + grid[row][col - 1]);

    if (col > 0 && col < m - 1 && row < n - 1)
        sum = max(sum, grid[row][col] + grid[row][col - 1] + grid[row][col + 1] + grid[row + 1][col]);

    if (col > 0 && col < m - 1 && row > 0)
        sum = max(sum, grid[row][col] + grid[row][col - 1] + grid[row][col + 1] + grid[row - 1][col]);

    return sum;
}

void solve()
{
    int ans = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            vis[i][j] = true;
            ans = max({ans, dfs(i, j, 1), edge_case(i, j)});
            vis[i][j] = false;
        }
    }

    cout << ans << endl;
}

int main()
{
    fastIO;
    input();
    solve();
}
