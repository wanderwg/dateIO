#include <iostream>
using namespace std;

bool IsLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	return false;
}
int GetMonthOfDay(int year, int month) {
	int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (IsLeapYear(year)) {
		days[2] += 1;
	}
	return days[month];
}
bool IsVliadDate(int year, int month, int day) {
	if (year <= 0 || month < 1 || month>12
		|| day<0 || day>GetMonthOfDay(year, month)) {
		return false;
	}
	return true;
}

int ConvertDate(int year, int month, int day) {
	int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (IsLeapYear(year)) {
		days[2] += 1;
	}
	int totalDays = 0;
	for (int i = 0; i < month; ++i) {
		totalDays += days[i];
	}
	totalDays += day;
	return totalDays;
}

int main()
{
	int year, month, day;
	while (cin >> year >> month >> day) {
		if (IsVliadDate(year, month, day)) {
			cout<<ConvertDate(year, month, day)<<endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	return 0;
}