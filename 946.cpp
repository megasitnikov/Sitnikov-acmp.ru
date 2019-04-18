#include "pch.h"
#include <iostream>
#include<deque>
using namespace std;
int main() {
	int n, k, d;
	deque<int>s; // создаем дек типа инт
	cin >> n;
	while (n) {
		cin >> k;
		if (k < 3) {
			cin >> d;
			if (k == 1)s.push_front(d); //добавили в начало дека d
			else s.push_back(d); //добавили в конец дека элемент d
		}
		else {
			if (k == 3) {
				d = s.front(); 
				s.pop_front(); // удалили первый элемент
			}
			else {
				d = s.back();
				s.pop_back(); // удалили последний элемент
			}
			cout << d << ' ';
		}
		n--;
	}
	return 0;
}
