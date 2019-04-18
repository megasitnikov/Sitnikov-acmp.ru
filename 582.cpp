#include "pch.h"
#include <iostream>
using namespace std;

struct Cube { //грани куба
	int front; //передняя
	int back; //задняя
	int top; //верхняя
	int bottom; //нижняя
	int left; //левая
	int right; //правая
	static Cube read() {
		int front, back, top, bottom, left, right;
		cin >> front >> back >> top >> bottom >> left >> right; //считываем эти грани
		return Cube{ front, back, top, bottom, left, right }; //вохвращаем новый куб с этими значениями
	}
	Cube rotateToTop() const {
		return Cube{ bottom, top, front, back, left, right };
	}
	Cube rotateRight() const {
		return Cube{ left, right, top, bottom, back, front };
	}
	Cube rotateCW() const {
		return Cube{ front, back, left, right, bottom, top };
	}
};

bool operator == (const Cube &a, const Cube &b) {
	return a.front == b.front && a.back == b.back && a.top == b.top && a.bottom == b.bottom && a.left == b.left && a.right == b.right;
}

int main() {
	Cube a = Cube::read();
	Cube b = Cube::read();
	for (int i = 0; i < 4; i++) {
		a = a.rotateToTop(); //направление вращения: куда сдвинется передняя грань
		for (int j = 0; j < 4; j++) {
			a = a.rotateRight();
			for (int k = 0; k < 4; k++) {
				a = a.rotateCW(); //по часовой стрелке
				if (a == b) {
					cout << "YES";
					return 0;
				}
			}
		}
	}
	cout << "NO";
	return 0;
}

/*#define F first
#define S second

pair <int, int> a[4], b[4];

int main() {
	for (int i = 0; i < 3; i++) {
		cin >> a[i].F >> a[i].S;
		if (a[i].F > a[i].S)
			swap(a[i].F, a[i].S);
	}
	for (int i = 0; i < 3; i++)	{
		cin >> b[i].F >> b[i].S;
		if (b[i].F > b[i].S)
			swap(b[i].F, b[i].S);
	}
	sort(b, b + 3);
	sort(a, a + 3);
	bool ok = 1;
	for (int i = 0; i < 3; i++)
		if (a[i] != b[i])
			ok = 0;
	if (ok) cout << "YES";
	else cout << "NO";
}*/
