#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

int n, m;
vector<int> tmp;

void go(int idx, int cnt)
{
    if (cnt == m)
    {
        for (auto v : tmp)
            cout << v << " ";
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        tmp.push_back(i);
        go(i, cnt + 1);
        tmp.pop_back();
    }
}

int main()
{
    fastIO;
    cin >> n >> m;
    go(0, 0);
}