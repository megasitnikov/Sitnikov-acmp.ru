#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

int L, R, n;

bool seg(int l, int r)
{
	L = max(L, l);
	R = min(R, r);
	return L <= R;
}

int main(){
	cin >> n >> L >> R;
	for (int i = 2; i <= n; i++)
	{
		int l, r;
		cin >> l >> r;
		if (!seg(l, r))
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}
