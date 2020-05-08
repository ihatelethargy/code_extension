#include <iostream>
#include <algorithm>

using namespace std;
#define endl "\n"

int gcd(int p, int q)
{
    if (q == 0)
        return p;
    else
        return gcd(q, p % q);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    int _gcd = gcd(max(a, b), min(a, b));

    cout << _gcd << endl;
    cout << a * b / _gcd << endl;

    return 0;
}
