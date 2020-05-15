// 숨바꼭질, bfs

#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

const int MAX = 100000;

int solve(int n, int k)
{
    if (n == k)
        return 0;

    if (n > k)
        return n - k;

    queue<int> q;
    vector<bool> vis(MAX + 1, false);
    int ret = 1;

    auto in_range = [&](int idx) {
        return 0 <= idx && idx <= MAX;
    };

    auto insert = [&](int idx) {
        int dir[3] = {idx - 1, idx + 1, idx * 2};

        for (auto d : dir)
        {
            if (in_range(d) && !vis[d])
            {
                q.push(d);
                vis[d] = true;
            }
        }
    };

    insert(n);

    if (vis[k])
        return ret;

    int q_size = static_cast<int>(q.size());
    int popped = 0;

    while (!q.empty())
    {
        int idx = q.front();
        q.pop();
        popped++;

        insert(idx);

        if (vis[k])
        {
            if (popped != 0)
                ret++;
            break;
        }

        if (popped == q_size)
        {
            ret++;
            popped = 0;
            q_size = static_cast<int>(q.size());
        }
    }

    return ret;
}

int main()
{
    fastIO;
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
}