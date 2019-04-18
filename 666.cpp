#include "pch.h"
#include <iostream>
using namespace std;

int main() {
	const int maxn = 26;
	long long int a[maxn], k, n;
	int i;
	cin >> n;
	a[0] = 1;
	for (i = 0; i < maxn-1; i++) {
		a[i + 1] = 1 + 2 * a[i];
	}
	for (k = 26; k > 1; k--) {
		if (n == 1) {
			cout << (char('a' + k - 1));
			goto here;
		}
		else {
			if (n > a[k - 1] + 1) n = n - 1 - a[k - 1];
			else n--;
		}
	}
	here:
	return 0;
}
