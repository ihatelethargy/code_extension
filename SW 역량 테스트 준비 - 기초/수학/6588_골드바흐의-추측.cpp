#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

vector<bool> isPrime;

void eratosthenes(int n)
{
    isPrime = vector<bool>(n + 1, true);

    isPrime[0] = isPrime[1] = false;

    int sqrtn = int(sqrt(n));

    for (int i = 2; i <= sqrtn; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

int main()
{
    fastIO;
    eratosthenes(1000000);
    int n;

    while (cin >> n)
    {
        if (n == 0)
            break;

        int a = -1;
        int b = -1;
        bool found = false;

        for (int i = 3; i <= n - 3; ++i)
        {
            if (isPrime[i] && isPrime[n - i])
            {
                a = i;
                b = n - i;
                found = true;
                break;
            }
        }

        if (found)
            cout << n << " = " << a << " + " << b << endl;
        else
            cout << "Goldbach's conjecture is wrong." << endl;
    }
}