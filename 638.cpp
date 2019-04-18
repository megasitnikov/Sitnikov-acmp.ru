#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int daysInMonth, len;
	cin >> daysInMonth >> len; //количество дней месяца / продолжительность олимпиды
	int daysInWeek, nWeekHolidays, firstDayOfWeek; 
	cin >> daysInWeek >> nWeekHolidays >> firstDayOfWeek; // кол-во дней в неделе /один день который нельзя использовать /день на который приходится первый день месяца
	vector <bool> weekHolidays(1 + daysInWeek, false); //создаем вектор свободен ли в этот день недели
	for (int i = 0; i < nWeekHolidays; i++) {
		int day;
		cin >> day; // считываем номер дня
		weekHolidays[day] = true; //прописываем что этот день выходной
	}
	vector <bool> monthHolidays(1 + daysInMonth + 1, false); // свободен ли в этот день недели (изначально никакой выходным не явл)
	{
		int wi = firstDayOfWeek;
		for (int mi = 1; mi < daysInMonth; mi++) { //идем по всем дням месяца от 1 до кол-во дней месяца
			monthHolidays[mi] = weekHolidays[wi]; //
			if (wi == daysInWeek) { //если выходной индекс равняется последнему дню недели
				wi = 1; //тогда номер дня недели 1
			}
			else {
				wi++; // иначе он увеличивается на 1
			}
		}
		
	}
	int nMonthHolidays;
	cin >> nMonthHolidays; //количество дней месяца не подходящих для проведения олимпиады
	for (int i = 0; i < nMonthHolidays; i++) {
		int day;
		cin >> day; //номера этих дней
		monthHolidays[day] = true; //прописываем что это выходной
	}
	int curHolidays = 0, nWays =0; //количество выходных в текущем len / количество способой представить
	for (int i = 1; i <= len; i++) { //идем от 1 до длины
		if (monthHolidays[i]) { //если monthHolidays от i
			curHolidays++; //текущее кол-во выходных увеличивается
		}
	}
	if (curHolidays == 0) { // если кол-во выходных 0
		nWays++; //кол-во способов увеличивается
	}
	for (int i = len + 1; i <= daysInMonth; i++) { //сдвигаем этот интервал вправва
		if (monthHolidays[i]) {//если это день выходной в месяце
			curHolidays++; //кол-во выходных увеличивается
		}
		if (monthHolidays[i-len]) { //уходящих день, если он был выходной и он уходит
			curHolidays--;//то кол-во выходных уменьшится
		}
		if (curHolidays == 0) { //если текущее кол-во выходных 0
			nWays++; // то кол-во способов увеличилось
		}
	}
	cout << nWays;
	return 0;
}
