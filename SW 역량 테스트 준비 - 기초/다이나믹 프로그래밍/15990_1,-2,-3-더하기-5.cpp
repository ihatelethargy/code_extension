#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;
const int MAX = 100'001;
const ll MOD = 1'000'000'009LL;

ll cache[MAX][4];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    cache[1][1] = 1;
    cache[2][2] = 1;
    cache[3][1] = 1;
    cache[3][2] = 1;
    cache[3][3] = 1;

    for (int i = 4; i < MAX; i++)
    {
        cache[i][1] = (cache[i - 1][2] + cache[i - 1][3]) % MOD;
        cache[i][2] = (cache[i - 2][1] + cache[i - 2][3]) % MOD;
        cache[i][3] = (cache[i - 3][1] + cache[i - 3][2]) % MOD;
    }

    while (t--)
    {
        int n;
        cin >> n;
        ll ans = (cache[n][1] + cache[n][2] + cache[n][3]) % MOD;
        cout << ans << endl;
    }
}