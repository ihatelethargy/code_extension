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

// 실패 (시간 초과)

// #include <bits/stdc++.h>

// #define endl "\n"
// #define fastIO                   \
//     ios::sync_with_stdio(false); \
//     cin.tie(NULL)

// using namespace std;

// int n;
// vector<int> permutation;
// vector<int> tmp;
// vector<bool> vis;
// bool found;
// bool finished;

// void input()
// {
//     cin >> n;
//     permutation.resize(n);
//     vis = vector<bool>(n + 1, false);
//     for (int i = 0; i < n; i++)
//         cin >> permutation[i];
// }

// void dfs(int cnt)
// {
//     if (finished)
//         return;

//     if (cnt == n)
//     {
//         if (found)
//         {
//             for (auto el : tmp)
//                 cout << el << " ";
//             cout << endl;
//             finished = true;
//             return;
//         }

//         found = equal(permutation.begin(), permutation.end(), tmp.begin(), tmp.end());
//         return;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         if (!vis[i])
//         {
//             vis[i] = true;
//             tmp.push_back(i);
//             dfs(cnt + 1);
//             vis[i] = false;
//             tmp.pop_back();
//         }
//     }
// }

// int main()
// {
//     fastIO;
//     input();
//     dfs(0);

//     if (!finished)
//         cout << -1 << endl;
// }