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

    vector<int> dp1(n, 1);
    vector<int> dp2(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (seq[i] > seq[j])
                dp1[i] = max(dp1[i], dp1[j] + 1);
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (seq[i] > seq[j])
                dp2[i] = max(dp2[i], dp2[j] + 1);
        }
    }

    int ans(0);

    for (int i = 0; i < n; i++)
        ans = max(ans, dp1[i] + dp2[i] - 1);

    cout << ans << endl;
}