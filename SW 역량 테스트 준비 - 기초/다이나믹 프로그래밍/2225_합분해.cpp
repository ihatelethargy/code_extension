#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;
const ll MOD = 1'000'000'000LL;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                dp[i][j] += dp[i - 1][j - k];
                dp[i][j] %= MOD;
            }
        }
    }

    cout << dp[k][n] << endl;
}