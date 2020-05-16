#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int r, c;
vector<string> matrix;
vector<vector<int>> _time;
bool vis[51][51];
pair<int, int> start;
pair<int, int> target;

void input()
{
    cin >> r >> c;
    matrix.resize(r);
    for (int i = 0; i < r; i++)
        cin >> matrix[i];
}

bool inside(int row, int col)
{
    return 0 <= row && row < r && 0 <= col && col < c;
}

void calc_time()
{
    memset(vis, false, sizeof(vis));
    _time = vector<vector<int>>(r, vector<int>(c, -2));
    queue<pair<int, int>> q;

    for (int row = 0; row < r; row++)
    {
        for (int col = 0; col < c; col++)
        {
            if (matrix[row][col] == 'S')
                start = {row, col};

            if (matrix[row][col] == 'D')
            {
                _time[row][col] = -1;
                target = {row, col};
            }

            if (matrix[row][col] == 'X')
                _time[row][col] = -1;

            if (matrix[row][col] == '*')
            {
                vis[row][col] = true;
                q.push({row, col});
            }
        }
    }

    int q_size = static_cast<int>(q.size());
    int popped = 0;
    int cnt = 0;

    while (!q.empty())
    {
        auto [row, col] = q.front();
        _time[row][col] = cnt;
        q.pop();
        popped++;

        for (auto &[_row, _col] : directions)
        {
            int nr = row + _row;
            int nc = col + _col;

            if (inside(nr, nc) && !vis[nr][nc] && _time[nr][nc] != -1)
            {
                vis[nr][nc] = true;
                q.push({nr, nc});
            }
        }

        if (popped == q_size)
        {
            cnt++;
            popped = 0;
            q_size = static_cast<int>(q.size());
        }
    }
}

void solve()
{
    int ans{-1};
    calc_time();
    memset(vis, false, sizeof(vis));
    queue<tuple<int, int, int>> q;
    vis[start.first][start.second] = true;
    q.push({start.first, start.second, 0});

    while (!q.empty())
    {
        auto [row, col, cost] = q.front();
        q.pop();

        for (auto &[_row, _col] : directions)
        {
            int nr = row + _row;
            int nc = col + _col;

            if (nr == target.first && nc == target.second)
            {
                ans = cost + 1;
                break;
            }

            if (inside(nr, nc) && !vis[nr][nc] && _time[nr][nc] != -1 && (_time[nr][nc] == -2 || _time[nr][nc] > cost + 1))
            {
                vis[nr][nc] = true;
                q.push({nr, nc, cost + 1});
            }
        }

        if (ans != -1)
            break;
    }

    cout << (ans == -1 ? "KAKTUS" : to_string(ans)) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
}