#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;

long double v[1000][2];
long double a[500000];
int z[500000][2];
int b[1000];

void Q(int L, int R) {
	int i, j;
	long double x;
	x = a[(L + R) >> 1];
	i = L, j = R;
	while (i <= j) {
		while (a[i] < x) i++;
		while (x < a[j]) j--;
		if (i <= j) {
			swap(a[j], a[i]);
			swap(z[j][1], z[i][1]);
			swap(z[j][0], z[i][0]);
			i++, j--;
		}
	}
	if (L < j) Q(L, j);
	if (i < R) Q(i, R);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i][0] >> v[i][1];
	int o = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			z[o][0] = i;
			z[o][1] = j;
			a[o] = (v[i][0] - v[j][0])*(v[i][0] - v[j][0]) + (v[i][1] - v[j][1])*(v[i][1] - v[j][1]);
			o++;
		}
	}
	int k = 0;
	int count = 1;
	Q(0, o - 1);
	long double Max = 0;
	for (int i = 0; i < n - 1; i++) {
		while ((b[z[k][0]] == b[z[k][1]]) && (b[z[k][0]] != 0))k++;

		if (b[z[k][0]] == 0 && b[z[k][1]] == 0) {
			b[z[k][1]] = count;
			count++;
		}
		if (b[z[k][0]] == 0) b[z[k][0]] = b[z[k][1]];
		else {
			if (b[z[k][1]] == 0) b[z[k][1]] = b[z[k][0]];
			else {
				for (int e = 0; e < 1000; e++){
					if (b[e] == b[z[k][0]]) b[e] = b[z[k][1]];
				}
			}
		}
		k++;
	}
	Max = sqrt(a[k - 1]) + 0.005;
	int m = (int)Max;
	int h = (int)((100 * Max));
	h = h - 100 * m;
	cout << m;
	cout << '.';
	if (h < 10) cout << '0';
	cout << h;
}
