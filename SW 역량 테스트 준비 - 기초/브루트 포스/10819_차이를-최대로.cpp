#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

int main()
{
    fastIO;
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(begin(v), end(v));

    int ans = INT_MIN;

    do
    {
        for (int i = 0; i < n; i++)
        {
            int sum = [&]() -> int {
                int ret = 0;

                for (int i = 0; i < n - 1; i++)
                    ret += abs(v[i] - v[i + 1]);

                return ret;
            }();

            ans = max(ans, sum);
        }
    } while (next_permutation(begin(v), end(v)));

    cout << ans << endl;
}