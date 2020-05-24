#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int p[n + 1];
    vector<int> cache(n + 1, INT_MAX - 10000);
    cache[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cache[i] = min(cache[i], cache[i - j] + p[j]);
        }
    }

    cout << cache[n] << endl;
}