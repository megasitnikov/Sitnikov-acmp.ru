#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int n = 0, sum = 4, c = 3;
	cin >> n;
	for (int i = 2; i < n; i++)
		sum += c++;
	cout << sum;

}
