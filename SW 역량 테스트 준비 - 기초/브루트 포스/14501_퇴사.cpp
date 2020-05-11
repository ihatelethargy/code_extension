#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

int dp[17];

int main()
{
    fastIO;
    int n;
    cin >> n;

    pair<int, int> schedule[n + 1];

    for (int i = 1; i <= n; i++)
        cin >> schedule[i].first >> schedule[i].second;

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        auto &[t, p] = schedule[i];

        if (i + t <= n + 1)
        {
            dp[i + t] = max(dp[i + t], dp[i] + p);
            ans = max(ans, dp[i + t]);
        }

        // 일을 안하고 넘어가는 경우가 최적일 경우를 고려해야 한다.
        dp[i + 1] = max(dp[i + 1], dp[i]);
        ans = max(ans, dp[i + 1]);
    }

    cout << ans << endl;
}