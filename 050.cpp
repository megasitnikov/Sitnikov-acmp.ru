#include "pch.h"
#include<iostream>
#include<string>
using namespace std;

string cs(string s) {
	if (s.size())s = (s + s[0]).erase(0, 1);
	return s;
}

int main() {
	string t, s, q;
	cin >> t >> s;
	q = s;
	int k = 0, i = 0, j;
	do {
		do {
			j = t.find(s, i);
			if (j == string::npos)i = 0;
			else { k++; i = j + 1; }
		} while (i);
		s = cs(s);
	} while (s != q);
	cout << k;
	return 0;
}
