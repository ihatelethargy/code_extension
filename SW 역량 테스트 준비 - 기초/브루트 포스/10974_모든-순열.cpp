#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

int n;
vector<int> permutation;
vector<bool> vis;

void input()
{
    cin >> n;
    vis = vector<bool>(n + 1, false);
}

void dfs(int cnt)
{
    if (cnt == n)
    {
        for (auto v : permutation)
            cout << v << " ";
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            permutation.push_back(i);
            dfs(cnt + 1);
            vis[i] = false;
            permutation.pop_back();
        }
    }
}

int main()
{
    fastIO;
    input();
    dfs(0);
}

/* -------------------------------------------------- */

#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

int main()
{
    fastIO;
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        v[i] = i + 1;

    do
    {
        for (int i = 0; i < n; i++)
            cout << v[i] << ' ';
        cout << endl;
    } while (next_permutation(begin(v), end(v)));
}