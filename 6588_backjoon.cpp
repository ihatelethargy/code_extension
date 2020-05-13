#include<iostream>
#include<cmath>

using namespace std;


int n;
bool sosu[1001];



void func(int n) {

	memset(sosu, true, sizeof(sosu));
	int x, y;
	int ff = int(sqrt(n));

	sosu[0] = false;
	sosu[1] = false;

	for (int i = 2; i <= ff; ++i)
	{
		if (sosu[i] == true)
		{
			for (int j = i * i; j <= n; j += i)
			{
				sosu[j] = false;
			}
		}
	}

	for (int i = 0; i <= n; ++i)
	{
		if (sosu[i] && sosu[n - i])
		{
			x = i;
			y = n - i;
			break;
		}
	}
	cout << n << " = " << x << " + " << y << "\n";

}

void input() {

	while (1) {

		cin >> n;
		if (n == 0)break;
		func(n);
	}
}


int main() {

	input();

}




