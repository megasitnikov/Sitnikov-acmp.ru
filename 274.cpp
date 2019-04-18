#include "pch.h"
#include <iostream>
using namespace std;

void output(bool arr[]) {
	cout << endl;
	for (int i = 0; i < 10; i++) cout << arr[i] << " ";
}

int main()
{
	int k;
	cin >> k;
	for (int i=0; i<k;i++)
	{
		bool a[10], b[10];
		for (int i=0; i<10;i++)
			a[i] = 0, b[i] = 0;
		int x, y;
		cin >> x >> y;
		while (x > 0)
			a[x % 10] = 1, x /= 10;
		while (y > 0)
			b[y % 10] = 1, y /= 10;
		bool fl = 1;
		//output(a);
		//output(b);
		for (int i = 0; i < 10; i++)
			fl = fl & (a[i] == b[i]);
		if (fl)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;;
	}
}
