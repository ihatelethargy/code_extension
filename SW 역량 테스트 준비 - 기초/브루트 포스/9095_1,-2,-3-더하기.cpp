#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

int main()
{
    fastIO;
    int t;
    cin >> t;
    
    int dp[12];
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    for (int i = 4; i <= 10; ++i)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    
    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
}