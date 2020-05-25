// Kadane's algorithm
// Maximum subarray

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    int ans = INT_MIN, a = 0;

    for (auto x : v)
    {
        a += x;
        ans = max(ans, a);
        a = max(a, 0);
    }

    cout << ans << endl;
}