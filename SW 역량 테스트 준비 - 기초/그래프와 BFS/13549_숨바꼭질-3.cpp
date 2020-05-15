// queue 1개로도 풀 수 있는 문제
// bfs 수행시 순간이동과 앞, 뒤 이동이 충돌하지 않음
// min heap을 사용해도 되지만 이 경우에는 dequeue나 queue가 더 효율적일 듯

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int MAX = 100001;

int n, k;
bool vis[MAX];
deque<pair<int, int>> dq;

void input()
{
    cin >> n >> k;
}

void solve()
{
    vis[n] = true;
    int ans(-1);
    dq.push_back({n, 0});

    while (!dq.empty())
    {
        auto [pos, time] = dq.front();
        dq.pop_front();

        if (pos == k)
        {
            ans = time;
            break;
        }

        if (pos * 2 < MAX && !vis[pos * 2])
        {
            vis[pos * 2] = true;
            dq.push_front({pos * 2, time});
        }

        if (pos - 1 >= 0 && !vis[pos - 1])
        {
            vis[pos - 1] = true;
            dq.push_back({pos - 1, time + 1});
        }

        if (pos + 1 < MAX && !vis[pos + 1])
        {
            vis[pos + 1] = true;
            dq.push_back({pos + 1, time + 1});
        }
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
}