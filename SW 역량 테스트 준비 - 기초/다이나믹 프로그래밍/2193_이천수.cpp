#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;
const int MAX = 91;

ll cache[MAX][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cache[1][0] = 0;
    cache[1][1] = 1;

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        cache[i][0] = cache[i - 1][0] + cache[i - 1][1];
        cache[i][1] = cache[i - 1][0];
    }

    ll ans = cache[n][0] + cache[n][1];

    cout << ans << endl;
}

/* -------------------------------------------------- */

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<ll> cache(n + 1, 0);
    cache[1] = 1;

    for (int i = 2; i <= n; i++)
        cache[i] = cache[i - 1] + cache[i - 2];

    cout << cache[n] << endl;
}