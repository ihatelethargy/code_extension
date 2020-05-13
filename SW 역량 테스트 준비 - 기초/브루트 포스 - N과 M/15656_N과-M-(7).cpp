#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

int n, m;
vector<int> v;
vector<int> tmp;

void input()
{
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(begin(v), end(v));
}

void go(int idx, int cnt)
{
    if (cnt == m)
    {
        for (auto el : tmp)
            cout << el << " ";
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {

        tmp.push_back(v[i]);
        go(i, cnt + 1);
        tmp.pop_back();
    }
}

int main()
{
    fastIO;
    input();
    go(0, 0);
}