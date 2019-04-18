#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int n, k = 0;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)	{
		cin >> arr[i];
	}
	for (int i = 0; i < n - 1; i++) {
		if ((arr[i] > arr[i + 1]) || (arr[i + 1] - arr[i] > 1)) {
			k++;
		}
	}
	cout << k;
	return 0;
}
