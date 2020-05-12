// Solution using bit mask

#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

void exec_cmd(bitset<21> &bs, string cmd)
{
    int x;

    if (cmd == "add")
    {
        cin >> x;
        bs.set(x);
    }

    if (cmd == "remove")
    {
        cin >> x;
        bs.set(x, 0);
    }

    if (cmd == "check")
    {
        cin >> x;
        cout << (bs.test(x) ? 1 : 0) << endl;
    }

    if (cmd == "toggle")
    {
        cin >> x;
        bs.test(x) ? bs.set(x, 0) : bs.set(x);
    }

    if (cmd == "all")
        bs.set();

    if (cmd == "empty")
        bs.reset();
}

int main()
{
    fastIO;
    int m;
    cin >> m;

    bitset<21> bs;

    while (m--)
    {
        string cmd;
        cin >> cmd;
        exec_cmd(bs, cmd);
    }
}

/* -------------------------------------------------- */

// Solution using set data structure
#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

int main()
{
    fastIO;
    int m;
    cin >> m;

    set<int> s;

    while (m--)
    {
        string cmd;
        int x;
        cin >> cmd;

        if (cmd == "add")
        {
            cin >> x;
            s.insert(x);
        }

        if (cmd == "remove")
        {
            cin >> x;
            bool xExists = s.find(x) != s.end();
            if (xExists)
            {
                s.erase(s.find(x));
            }
        }

        if (cmd == "check")
        {
            cin >> x;
            cout << (s.find(x) != s.end() ? 1 : 0) << endl;
        }

        if (cmd == "toggle")
        {
            cin >> x;
            bool xExists = s.find(x) != s.end();
            if (xExists)
            {
                s.erase(s.find(x));
            }
            else
            {
                s.insert(x);
            }
        }

        if (cmd == "all")
        {
            for (int i = 1; i <= 20; i++)
            {
                s.insert(i);
            }
        }

        if (cmd == "empty")
        {
            s.clear();
        }
    }
}