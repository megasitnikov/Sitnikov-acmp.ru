
#include "pch.h"
#include <iostream>
using namespace std;

int main() {
	int s = 0, x;
	for (int i = 0; i < 31; i++) {
		cin >> x;
		s += x;
	}
	cout << (s / 27);
	return 0;
}
