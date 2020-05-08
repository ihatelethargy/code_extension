#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

int main()
{
    fastIO;
    int a, b, c;
    cin >> a >> b >> c;

    int ans1 = (a + b) % c;
    int ans2 = (a * b) % c;

    cout << ans1 << endl
         << ans1 << endl
         << ans2 << endl
         << ans2 << endl;
}