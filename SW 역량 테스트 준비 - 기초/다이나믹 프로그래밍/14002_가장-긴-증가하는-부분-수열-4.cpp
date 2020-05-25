// LIS

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int seq[n];

    for (int i = 0; i < n; i++)
        cin >> seq[i];

    int len(1), idx(0);
    vector<int> dp(n, 1);
    vector<int> v(n, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (seq[i] > seq[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                v[i] = j;

                if (len < dp[i])
                {
                    len = dp[i];
                    idx = i;
                }
            }
        }
    }

    vector<int> ans;

    while (true)
    {
        if (v[idx] == -1)
        {
            ans.push_back(seq[idx]);
            break;
        }

        ans.push_back(seq[idx]);
        idx = v[idx];
    }

    reverse(begin(ans), end(ans));

    cout << len << endl;
    for (auto v : ans)
        cout << v << " ";
    cout << endl;
}