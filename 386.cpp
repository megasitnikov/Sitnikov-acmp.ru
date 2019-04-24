#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;

int main() {
	int n, x=0, y=0;
	cin >> n;
	cout << "YES\n";
	cout << x << " "<< y << endl;
	for (int i = 2; i <= n; i++) {
		x = rand() % 10000;
		y = rand() % 10000;
		cout << x << " " << y << endl;
	}
	return 0;
}
