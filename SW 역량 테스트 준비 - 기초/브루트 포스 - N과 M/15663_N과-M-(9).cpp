#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

int n, m;
map<int, int> mp;
vector<int> tmp;
int _size;
int __size;

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    _size = static_cast<int>(mp.size());
}

void go(int cnt)
{
    if (__size == m)
    {
        for (auto el : tmp)
            cout << el << " ";
        cout << endl;
        return;
    }

    for (auto it = begin(mp); it != end(mp); it++)
    {
        auto &[_n, _c] = *it;
        int _cnt = 1;

        while (_c > 0 && cnt + _cnt <= m)
        {
            _c--;
            tmp.push_back(_n);
            __size++;
            go(cnt + _cnt);
            _cnt++;
            _c++;
            tmp.pop_back();
            __size--;
        }
    }
}

int main()
{
    fastIO;
    input();
    go(0);
}