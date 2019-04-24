#include "pch.h"
#include <iostream> 

using namespace std;

int main() {
	int n, i, j, mass[30000], num1, num2;
	cin>>n>>num1>>num2;
	for (i = 0; i < n - 1; i++) cin>>mass[i];
	while (num1 != num2) {
		if (num1 > num2) swap(num1, num2);
		num2 = mass[num2 - 2];
	}
	cout<<num1;
}
