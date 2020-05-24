#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    vector<vector<ll>> dp;

    while (t--)
    {
        int n;
        cin >> n;

        ll arr[2][n + 1];

        for (int i = 0; i < 2; i++)
            for (int j = 1; j <= n; j++)
                cin >> arr[i][j];

        dp = vector<vector<ll>>(n + 1, vector<ll>(3, 0));

        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + arr[0][i];
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + arr[1][i];
        }

        ll ans = *max_element(begin(dp[n]), end(dp[n]));
        cout << ans << endl;
    }
}