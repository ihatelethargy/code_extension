#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n;
vector<string> matrix;
queue<pair<int, int>> q;

void input()
{
    cin >> n;
    matrix = vector<string>(n);
    for (int i = 0; i < n; i++)
        cin >> matrix[i];
}

int bfs(int row, int col)
{
    int ret = 1;
    q.push({row, col});

    auto inside = [&](int r, int c) {
        return 0 <= r && r < n && 0 <= c && c < n;
    };

    auto insert = [&](int r, int c) {
        for (auto &[_r, _c] : directions)
        {
            int nr = r + _r;
            int nc = c + _c;
            if (inside(nr, nc) && matrix[nr][nc] == '1')
            {
                q.push({nr, nc});
                matrix[nr][nc] = '0';
                ret++;
            }
        }
    };

    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        insert(r, c);
    }

    return ret;
}

void solve()
{
    int total = 0;
    vector<int> cnt;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (matrix[row][col] == '1')
            {
                matrix[row][col] = '0';
                cnt.push_back(bfs(row, col));
                total++;
            }
        }
    }

    sort(begin(cnt), end(cnt));

    cout << total << endl;
    for (auto v : cnt)
        cout << v << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
}