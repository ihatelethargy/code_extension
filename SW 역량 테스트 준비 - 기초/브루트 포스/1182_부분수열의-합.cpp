#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

int n, s;
vector<int> v;
int ans;

void input()
{
    cin >> n >> s;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
}

void go(int idx, int sum)
{
    if (idx == n)
    {
        if (sum == s)
            ans++;
        return;
    }

    go(idx + 1, sum + v[idx]);
    go(idx + 1, sum);
}

int main()
{
    fastIO;
    input();
    go(0, 0);
    cout << (s == 0 ? ans - 1 : ans) << endl;
}