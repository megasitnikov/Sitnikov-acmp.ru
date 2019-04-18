#include "pch.h"
#include <iostream>
using namespace std;

int A(int n, int k) {
	int a = 1;
	for (int i = n; i > n - k; i--)
		a *= i;
	return a;
}


int main() {
	int n, k, a, b[20], r = 0;
	cin >> n >> k;
	for (int i = 0; i < 20; i++) b[i] = 0;
	for (int i = 0; i < k; i++)
	{
		int l = 0;
		cin >> a;
		for (int j = 1; j < a; j++)
			if (b[j] == 0) l++;
		r += l * A(n - i - 1, k - i - 1);
		b[a] = 1;
	}
	cout << r + 1;
}
