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
    cache[1] = 0;

    for (int i = 2; i <= n; ++i)
    {
        cache[i] = cache[i - 1] + 1;

        if (i % 2 == 0 && cache[i] > cache[i / 2] + 1)
            cache[i] = cache[i / 2] + 1;

        if (i % 3 == 0 && cache[i] > cache[i / 3] + 1)
            cache[i] = cache[i / 3] + 1;
    }

    cout << cache[n] << endl;
}