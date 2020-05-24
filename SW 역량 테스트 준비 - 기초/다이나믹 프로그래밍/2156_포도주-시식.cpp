#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int amount[n + 1];

    for (int i = 1; i <= n; i++)
        cin >> amount[i];

    int dp[n + 1];
    dp[0] = 0;
    dp[1] = amount[1];
    dp[2] = amount[1] + amount[2];

    for (int i = 3; i <= n; i++)
        dp[i] = max({dp[i - 1], dp[i - 2] + amount[i], dp[i - 3] + amount[i - 1] + amount[i]});

    cout << dp[n] << endl;
}