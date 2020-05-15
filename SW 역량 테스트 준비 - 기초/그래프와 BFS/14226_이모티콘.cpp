// 이모티콘

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int MAX = 1001;

int n;
int status[MAX][MAX];
queue<pair<int, int>> q;

void input_init()
{
    cin >> n;
    memset(status, -1, sizeof(status));
    status[1][0] = 0;
}

void solve()
{
    int ans(-1);
    q.push({1, 0});

    while (!q.empty())
    {
        auto [e, c] = q.front();
        q.pop();

        if (e == n)
        {
            ans = status[e][c];
            break;
        }

        if (status[e][e] == -1)
        {
            q.push({e, e});
            status[e][e] = status[e][c] + 1;
        }

        if (e + c <= MAX && status[e + c][c] == -1)
        {
            q.push({e + c, c});
            status[e + c][c] = status[e][c] + 1;
        }

        if (e - 1 >= 0 && status[e - 1][c] == -1)
        {
            q.push({e - 1, c});
            status[e - 1][c] = status[e][c] + 1;
        }
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input_init();
    solve();
}