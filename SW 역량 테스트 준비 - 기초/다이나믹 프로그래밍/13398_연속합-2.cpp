#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n, 0);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    int ans(v[0]);
    vector<int> dpl(v);
    vector<int> dpr(v);

    for (int i = 1; i < n; i++)
    {
        dpl[i] = max(dpl[i], dpl[i - 1] + v[i]);
        ans = max(ans, dpl[i]);
    }

    for (int i = n - 2; i >= 0; i--)
        dpr[i] = max(dpr[i], dpr[i + 1] + v[i]);

    for (int i = 1; i < n - 1; i++)
        ans = max(ans, dpl[i - 1] + dpr[i + 1]);

    cout << ans << endl;
}