#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;
const int MAX = 1'001;
const int MOD = 10'007;

ll cache[MAX][10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i <= 9; i++)
        cache[1][i] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                cache[i][j] += cache[i - 1][k];
                cache[i][j] %= MOD;
            }
        }
    }

    ll ans(0);
    for (int i = 0; i <= 9; i++)
        ans += cache[n][i];
    ans %= MOD;
    cout << ans << endl;
}

/* -------------------------------------------------- */

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int arr[10] = {
        1,
    };

    for (int i = 0; i <= n; i++)
        for (int j = 1; j <= 9; j++)
            arr[j] = (arr[j] + arr[j - 1]) % 10'007;

    cout << arr[9] << endl;
}