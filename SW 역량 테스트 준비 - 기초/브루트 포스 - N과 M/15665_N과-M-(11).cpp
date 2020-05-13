#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

int n, m;
set<int> s;
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
        s.insert(x);
    }
    _size = static_cast<int>(s.size());
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

    for (auto it = begin(s); it != end(s); it++)
    {
        int _cnt = 1;

        while (cnt + _cnt <= m)
        {
            tmp.push_back(*it);
            __size++;
            go(cnt + _cnt);
            _cnt++;
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