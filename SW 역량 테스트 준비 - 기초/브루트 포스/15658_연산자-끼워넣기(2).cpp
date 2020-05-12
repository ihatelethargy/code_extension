#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

int n;
vector<int> operands;
vector<int> operators(4, 0);
int _min = INT_MAX;
int _max = INT_MIN;

void input()
{
    cin >> n;
    operands.resize(n);
    for (int i = 0; i < n; i++)
        cin >> operands[i];
    for (int i = 0; i <= 3; i++)
        cin >> operators[i];
}

void go(int cnt, int res, int a, int s, int m, int d)
{
    if (cnt == n - 1)
    {
        _max = max(_max, res);
        _min = min(_min, res);
        return;
    }

    if (a > 0)
        go(cnt + 1, res + operands[cnt + 1], a - 1, s, m, d);

    if (s > 0)
        go(cnt + 1, res - operands[cnt + 1], a, s - 1, m, d);

    if (m > 0)
        go(cnt + 1, res * operands[cnt + 1], a, s, m - 1, d);

    if (d > 0)
        go(cnt + 1, res / operands[cnt + 1], a, s, m, d - 1);
}

void solve()
{
    go(0, operands[0], operators[0], operators[1], operators[2], operators[3]);
    cout << _max << endl;
    cout << _min << endl;
}

int main()
{
    fastIO;
    input();
    solve();
}