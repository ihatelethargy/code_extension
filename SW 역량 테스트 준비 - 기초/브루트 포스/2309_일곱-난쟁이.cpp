#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

int main()
{
    fastIO;
    vector<int> v(9);

    for (int i = 0; i < 9; ++i)
        cin >> v[i];

    int sum(accumulate(begin(v), end(v), 0));
    sort(begin(v), end(v));

    for (int i = 0; i < 9; ++i)
    {
        for (int j = i + 1; j < 9; ++j)
        {
            if (v[i] + v[j] == sum - 100)
            {
                for (int k = 0; k < 9; ++k)
                {
                    if (k != i && k != j)
                        cout << v[k] << endl;
                }

                return 0;
            }
        }
    }
}