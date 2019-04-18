#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int n, m, ans;
	cin >> n >> m;
	ans = 2 * (m*n + n + m);
	if (m % 2 == 1 && n % 2 == 1 || n == 1 || m == 1) ans -= 2;
	else ans;
	cout << ans;
}
