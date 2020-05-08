#include <bits/stdc++.h>

using namespace std;
#define endl "\n"

bool isPrime[1001];

void eratosthenes(int n)
{
    memset(isPrime, true, sizeof(isPrime));

    isPrime[0] = isPrime[1] = false;

    int sqrtn = int(sqrt(n));

    for (int i = 2; i <= sqrtn; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    eratosthenes(1000);

    int n;
    cin >> n;

    int ans = 0;

    while (n--)
    {
        int num;
        cin >> num;
        if (isPrime[num])
            ans++;
    }

    cout << ans << endl;
}