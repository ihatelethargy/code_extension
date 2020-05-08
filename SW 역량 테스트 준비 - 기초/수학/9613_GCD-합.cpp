#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

long long gcd(int p, int q)
{
    if (q == 0)
        return p;
    else
        return gcd(q, p % q);
}

int main()
{
    fastIO;
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> nums(n);

        for (int i = 0; i < n; ++i)
            cin >> nums[i];

        long long gcd_sum = 0;

        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                gcd_sum += gcd(nums[i], nums[j]);

        cout << gcd_sum << endl;
    }
}