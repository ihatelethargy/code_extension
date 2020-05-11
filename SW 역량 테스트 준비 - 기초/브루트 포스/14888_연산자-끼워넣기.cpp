#include <bits/stdc++.h>

#define endl "\n"
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

const int ADDITION = 0;
const int SUBTRACTION = 1;
const int MULTIPLICATION = 2;
const int DIVISION = 3;

int n;
vector<int> operands;
vector<int> operators;

void input()
{
    cin >> n;
    operands.resize(n);
    for (int i = 0; i < n; i++)
        cin >> operands[i];
    for (int i = 0; i <= 3; i++)
    {
        int x;
        cin >> x;
        while (x--)
            operators.push_back(i);
    }
}

void solve()
{
    int _max = INT_MIN;
    int _min = INT_MAX;

    do
    {
        int res = operands[0];

        for (int i = 0; i < n - 1; i++)
        {
            switch (operators[i])
            {
            case ADDITION:
                res += operands[i + 1];
                break;
            case SUBTRACTION:
                res -= operands[i + 1];
                break;
            case MULTIPLICATION:
                res *= operands[i + 1];
                break;
            case DIVISION:
                res /= operands[i + 1];
                break;
            default:
                break;
            }
        }

        _max = max(_max, res);
        _min = min(_min, res);
    } while (next_permutation(begin(operators), end(operators)));

    cout << _max << endl;
    cout << _min << endl;
}

int main()
{
    fastIO;
    input();
    solve();
}