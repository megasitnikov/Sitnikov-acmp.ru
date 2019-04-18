#include"pch.h"
#include <iostream>
#include <clocale>
using namespace std;

int get_prev_sum(int  sum, int F, int P);

int main()
{
	setlocale(0, "");
	const int F_MAX = 1000000000;
	const int F_MIN = 2;
	const int P_MIN = 1;

	int F = 0, P = 0;
	do {
		cout << "Стоимость ПОЛНОЙ бутылки F больше " << F_MIN << " у.е. и меньше " << F_MAX << " у.е. : ";
		cin >> F;
	} 
	while (F < F_MIN || F_MAX < F);

	do {
		cout << "Стоимость ПУСТОЙ бутылки P больше " << P_MIN << " у.е. и меньше " << F << " у.е. : ";
		cin >> P;
	} 
	while (P < P_MIN || F <= P);

	int min_start_sum = F;

	for (int i = 0; i < 4; i++)
	{
		min_start_sum = get_prev_sum(min_start_sum, F, P);
	}

	cout << "Минимальная начальная сумма: " << min_start_sum;
	return 0;
}

int get_prev_sum(int  sum, int F, int P)
{
	return  ((sum - F) / P + 1) * (F - P) + sum;
}
