#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int cache[n + 1];

    cache[1] = 1;
    cache[2] = 2;

    for (int i = 3; i <= n; ++i)
        cache[i] = (cache[i - 1] + cache[i - 2]) % 10007;

    cout << cache[n] << endl;
}