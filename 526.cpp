#include "pch.h"
#include <iostream>
#include <cstdio> 
#include <string> 
#include <cassert> 
#include <iostream> 
using namespace std;

char digitToChar(int d) {
	if (0 <= d && d <= 9) {
		return (char)('0' + d);
	}
	else {
		assert(10 <= d && d <= 35);
		return (char)('A' + (d - 10));
	}
}
string toStringBase(int n, int base) { //переводит первое число в систему счисления
	string s = "";
	while (n > 0) {
		int d = n % base;
		n /= base;
		s = digitToChar(d) + s;
	}
	return s; //возвращает ответ в системе счисления
}
int main()
{
	int value;
	static char buffer[1000 * 1000 + 1];
	cin>>buffer>>value;
	string s(buffer);
	assert(s.size() < 1000 * 1000); //Проверяем условие меньше 1е7
	for (int base = 2; base <= 36; base++) { //основание
		if (toStringBase(value, base) == s) { //проверяем равно ли первое число второму во всех системах счисления 
			cout << base;
			return 0;
		}
	}
	cout << "0";
	return 0;
}
