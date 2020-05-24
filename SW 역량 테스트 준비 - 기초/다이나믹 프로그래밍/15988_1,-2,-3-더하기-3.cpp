#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;
const int MAX = 1000001;
const ll MOD = 1000000009LL;

ll cache[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;

    for (int i = 4; i < MAX; i++)
        cache[i] = (cache[i - 1] + cache[i - 2] + cache[i - 3]) % MOD;

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        cout << cache[n] << endl;
    }
}