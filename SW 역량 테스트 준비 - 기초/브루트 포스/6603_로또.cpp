// Solution using permutation

#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

void solve(vector<int> set, int size, int limit)
{
    vector<int> bs(limit, 1);
    bs.resize(size, 2);

    do
    {
        for (int i = 0; i < size; i++)
            if (bs[i] == 1)
                cout << set[i] << " ";
        cout << endl;
    } while (next_permutation(begin(bs), end(bs)));
}

int main()
{
    fastIO;

    int n;

    while (cin >> n)
    {
        if (n == 0)
            break;

        vector<int> set(n);

        for (int i = 0; i < n; i++)
            cin >> set[i];

        solve(set, n, 6);

        cout << endl;
    }
}

/* -------------------------------------------------- */

// Solution using recursion

//#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

const int LIMIT = 6;
int n;
vector<int> v;
vector<int> lotto;

void go(int idx, int cnt)
{
    if (cnt == LIMIT)
    {
        for (auto n : lotto)
            cout << n << " ";
        cout << endl;
        return;
    }

    for (int i = idx; i < n; i++)
    {
        // 입력: 8 1 2 3 5 8 13 21 34
        // 가지치기 없이 247번 호출
        // 가지치기를 하면 83번 호출
        // pdf에 나와있는 코드로 하면 같은 입력으로 493번 호출
        if (i + 1 <= v.size() - LIMIT + cnt + 1)
        {
            lotto.push_back(v[i]);
            go(i + 1, cnt + 1);
            lotto.pop_back();
        }
    }
}

int main()
{
    fastIO;

    while (cin >> n)
    {
        if (n == 0)
            break;

        v = vector<int>(n);

        for (int i = 0; i < n; i++)
            cin >> v[i];

        go(0, 0);
        cout << endl;
    }
}