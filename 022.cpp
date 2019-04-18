#include "pch.h"
#include<iostream>
using namespace std;
int main()
{
	int n, k = 0;
	cin >> n;
	while (n)
	{
		k += n % 2;
		n /= 2;
	}
	cout << k;
}
