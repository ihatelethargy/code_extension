// Solution using recursion

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

/* -------------------------------------------------- */

// Solution using bitwise operation

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

void solve()
{
    for (int i = 0; i < (1 << n); i++)
    {
        int sum = 0;

        for (int k = 0; k < n; k++)
        {
            if (i & (1 << k))
                sum += v[k];
        }

        if (sum == s)
            ans++;
    }
}

int main()
{
    fastIO;
    input();
    solve();
    cout << (s == 0 ? ans - 1 : ans) << endl;
}