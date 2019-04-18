#include "pch.h"
#include <iostream>
using namespace std;

int sum(int x1, int y1, int x2, int y2) {
	long long int a, b, c;
	a = abs(x1 - x2);
	b = abs(y1 - y2);
	if (a == 0) return b + 1 -2; //-2 это координаты начала и конца
	else {
		if (b == 0) return a + 1 -2; //-2 это координаты начала и конца
		else {
			while (b > 0) {
				c = a % b;
				a = b;
				b = c;
			}
			return a + 1 - 2;
		}
	}
}

int main() {
	long long int x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	int k = 0;
	if (x1 == x2, x2 == x3, x3 == y1, y1 == y2, y2 == y3) { // если все координаты лежат в одной точке
		cout << 1; // выводим в ответ единственную точку
		goto here; // пропускаем след условие, т.к. там  еще один вывод
	}
	k += sum(x1, y1, x2, y2); //1 сторона
	k += sum(x2, y2, x3, y3); //2 сторона
	k += sum(x3, y3, x1, y1); //3 сторона
	cout << k + 3; //+3, т.к. ф-ия не считает вершины 
here:
	return 0;
}
