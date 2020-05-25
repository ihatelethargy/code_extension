#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> seq(n);

    for (int i = 0; i < n; i++)
        cin >> seq[i];

    int ans(seq[0]);
    vector<int> dp(seq);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (seq[i] > seq[j])
            {
                dp[i] = max(dp[i], dp[j] + seq[i]);
                ans = max(ans, dp[i]);
            }
        }
    }

    cout << ans << endl;
}