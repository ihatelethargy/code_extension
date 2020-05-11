#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

int l, c;
vector<char> v;

void input()
{
    cin >> l >> c;
    v.resize(c);
    for (int i = 0; i < c; i++)
        cin >> v[i];
}

void dfs(string s, int idx, int nv, int nc)
{
    int length = static_cast<int>(s.size());

    if (length == l)
    {
        if (nv >= 1 && nc >= 2)
            cout << s << endl;
        return;
    }

    auto is_vowel = [&](char c) -> bool {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };

    for (int i = idx; i < c; i++)
    {
        is_vowel(v[i]) ? nv++ : nc++;
        dfs(s + v[i], i + 1, nv, nc);
        is_vowel(v[i]) ? nv-- : nc--;
    }
}

void solve()
{
    sort(begin(v), end(v));
    dfs("", 0, 0, 0);
}

int main()
{
    fastIO;
    input();
    solve();
}

// 입력이 큰 경우 아래와 같은 방법이 효율적임

// #include <bits/stdc++.h>

// #define endl "\n"
// #define fastIO                   \
//     ios::sync_with_stdio(false); \
//     cin.tie(NULL)

// using namespace std;

// int l, c;
// vector<char> v;
// vector<bool> vis;
// vector<char> tmp;
// int num_of_vowels;
// int num_of_consonant;

// void input()
// {
//     cin >> l >> c;
//     v.resize(c);
//     vis = vector<bool>(c, false);
//     for (int i = 0; i < c; i++)
//         cin >> v[i];
// }

// bool is_vowel(char c)
// {
//     return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
// }

// bool promising(int idx)
// {
//     if (num_of_vowels >= 1 && num_of_consonant >= 2)
//         return true;

//     int nv = num_of_vowels;
//     int nc = 0;

//     for (int i = idx; i < c; i++)
//     {
//         if (is_vowel(v[i]))
//             nv++;
//         else
//             nc++;

//         if (nv >= 1 && nc >= 2 - num_of_consonant)
//             return true;
//     }

//     return false;
//     ;
// }

// void dfs(int idx, int cnt)
// {
//     if (cnt == l)
//     {
//         if (num_of_vowels < 1 || num_of_consonant < 2)
//             return;

//         for (auto v : tmp)
//             cout << v;
//         cout << endl;
//         return;
//     }

//     for (int i = idx + 1; i < c; i++)
//     {
//         if (!vis[i] && promising(i))
//         {
//             if (is_vowel(v[i]))
//                 num_of_vowels++;
//             else
//                 num_of_consonant++;

//             vis[i] = true;
//             tmp.push_back(v[i]);

//             dfs(i, cnt + 1);

//             if (is_vowel(*tmp.rbegin()))
//                 num_of_vowels--;
//             else
//                 num_of_consonant--;

//             vis[i] = false;
//             tmp.pop_back();
//         }
//     }
// }

// void solve()
// {
//     sort(begin(v), end(v));

//     for (int i = 0; i <= c - l; i++)
//     {
//         if (is_vowel(v[i]))
//             num_of_vowels++;
//         else
//             num_of_consonant++;

//         tmp.push_back(v[i]);
//         dfs(i, 1);
//         tmp.pop_back();
//         num_of_vowels = 0;
//         num_of_consonant = 0;
//     }
// }

// int main()
// {
//     fastIO;
//     input();
//     solve();
// }