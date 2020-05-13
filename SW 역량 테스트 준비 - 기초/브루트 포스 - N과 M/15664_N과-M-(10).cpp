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

void go(map<int, int>::iterator &it, int cnt)
{
    if (__size == m)
    {
        for (auto el : tmp)
            cout << el << " ";
        cout << endl;
        return;
    }

    for (auto _it = it; _it != end(mp); _it++)
    {
        auto &[_n, _c] = *_it;
        int _cnt = 1;

        while (_c > 0 && cnt + _cnt <= m)
        {
            _c--;
            tmp.push_back(_n);
            __size++;
            go(_it, cnt + _cnt);
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
    auto it = begin(mp);
    go(it, 0);
}