#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    int cache[11];

    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;

    for (int i = 4; i <= 10; ++i)
        cache[i] = cache[i - 1] + cache[i - 2] + cache[i - 3];

    while (t--)
    {
        int n;
        cin >> n;
        cout << cache[n] << endl;
    }
}