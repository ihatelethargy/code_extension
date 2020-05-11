// http://blog.naver.com/PostView.nhn?blogId=chogahui05&logNo=221292809519
// http://www.cplusplus.com/reference/algorithm/next_permutation/

#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

int n;
vector<int> permutation;

void input()
{
    cin >> n;
    permutation.resize(n);
    for (int i = 0; i < n; i++)
        cin >> permutation[i];
}

void solve()
{
    if (next_permutation(begin(permutation), end(permutation)))
    {
        for (auto v : permutation)
            cout << v << " ";
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

int main()
{
    fastIO;
    input();
    solve();
}
