#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

int main()
{
    fastIO;
    int e, s, m;
    cin >> e >> s >> m;

    e--;
    s--;
    m--;

    for (int n = 0;; n++)
    {
        if (n % 15 == e && n % 28 == s && n % 19 == m)
        {
            cout << n + 1 << endl;
            break;
        }
    }
}