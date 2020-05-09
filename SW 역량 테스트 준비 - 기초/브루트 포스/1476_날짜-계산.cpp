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

    int ans = 1;

    while (true)
    {
        bool _e = ans % 15 == e || (ans % 15 == 0 && e == 15);
        bool _s = ans % 28 == s || (ans % 28 == 0 && s == 28);
        bool _m = ans % 19 == m || (ans % 19 == 0 && m == 19);

        if (_e && _s && _m)
            break;

        ans++;
    }

    cout << ans << endl;
}