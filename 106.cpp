#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int n, x, one=0, null=0;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> x;
		arr[i] = x;
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) null++;
		else one++;
	}
	if (one >= null) cout << null;
	else cout << one;
	return 0;
 }
