#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

int n;
vector<vector<int>> cost;
vector<int> p;

void input()
{
    cin >> n;
    cost = vector<vector<int>>(n, vector<int>(n, 0));
    p.resize(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
            p[i] = i;
        }
    }
}

void solve()
{
    int ans = INT_MAX;

    do
    {
        int sum = 0;
        bool ok = true;

        if (p[0] != 0)
            break;

        for (int i = 0; i < n; i++)
        {
            int _cost = cost[p[i]][p[(i + 1) % n]];

            if (_cost == 0)
            {
                ok = false;
                break;
            }

            sum += _cost;

            if (sum > ans)
                break;
        }

        if (ok)
            ans = min(ans, sum);
    } while (next_permutation(begin(p), end(p)));

    cout << ans << endl;
}

int main()
{
    fastIO;
    input();
    solve();
}