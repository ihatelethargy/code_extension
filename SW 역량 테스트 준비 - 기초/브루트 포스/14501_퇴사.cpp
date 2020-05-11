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

/* -------------------------------------------------- */

// Solution using recursion (brute force)

#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

int n;
vector<pair<int, int>> schedule;
int ans;

void input()
{
    cin >> n;
    schedule.resize(n + 1);
    for (int i = 0; i < n; i++)
        cin >> schedule[i].first >> schedule[i].second;
}

void search(int idx, int sum)
{
    if (idx == n)
    {
        ans = max(ans, sum);
        return;
    }

    if (idx + 1 <= n)
        search(idx + 1, sum);

    if (auto &[t, p] = schedule[idx]; idx + t <= n)
        search(idx + t, sum + p);
}

int main()
{
    fastIO;
    input();
    search(0, 0);
    cout << ans << endl;
}