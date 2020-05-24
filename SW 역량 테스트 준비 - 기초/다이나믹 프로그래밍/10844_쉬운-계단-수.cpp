#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;
const int MAX = 101;
const long long MOD = 1'000'000'000LL;

ll cache[MAX][10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= 9; i++)
        cache[1][i] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j - 1 >= 0)
                cache[i][j] += cache[i - 1][j - 1];

            if (j + 1 <= 9)
                cache[i][j] += cache[i - 1][j + 1];

            cache[i][j] %= MOD;
        }
    }

    ll ans(0);
    for (int i = 0; i <= 9; i++)
        ans += cache[n][i];
    ans %= MOD;
    cout << ans << endl;
}