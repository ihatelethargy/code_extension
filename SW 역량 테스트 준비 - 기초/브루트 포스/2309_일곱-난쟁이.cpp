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

    int sum(accumulate(v.begin(), v.end(), 0));

    int x(-1), y(-1);

    for (int i = 0; i < 9; ++i)
    {
        for (int j = i + 1; j < 9; ++j)
        {
            if (v[i] + v[j] == sum - 100)
            {
                x = i;
                y = j;
                break;
            }
        }
    }

    vector<int> ans;

    for (int i = 0; i < 9; ++i)
    {
        if (i != x && i != y)
            ans.push_back(v[i]);
    }

    sort(begin(ans), end(ans));

    for (auto h : ans)
        cout << h << endl;
}