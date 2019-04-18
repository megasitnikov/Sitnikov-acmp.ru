#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int x1, x2, y1, y2;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	x2 -= x1;
	y2 -= y1;
	if (x2 % 2 == 0 && y2 % 2 !=0 || x2 % 2 != 0 && y2 % 2 == 0) cout << "0";
	else if (x2 == y2 || x2 == -y2) cout << "1";
	else cout << "2";
}
