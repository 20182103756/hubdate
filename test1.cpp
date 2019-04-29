// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//



#include "stdafx.h"  
#include "iostream"  
using namespace std;
class	HUbtai
{
private:
	int year;
	int month;
	int day;
	int check();
public:
	HUbtai();
	HUbtai(int y, int m, int d);
	int setDate(int y, int m, int d);
	void displayDate();
	void addOneDay();
};
HUbtai::HUbtai()
{
	year = 2019;
	month = 1;
	day = 1;
}
HUbtai::HUbtai(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	if (check() == 1 || check() == -1)
	{
		month = 1;
		day = 1;
		cout << "�����˴������ڣ���������1" << endl;
	}

}
int HUbtai::setDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	if (check() == 1 || check() == -1)
	{
		month = 1;
		day = 1;
		cout << "�����˴������ڣ���������1" << endl;
		return -1;
	}
	return 0;


}
void HUbtai::displayDate()
{
	cout << year << "��" << month << "��" << day << "��" << endl;
}
int HUbtai::check()
{
	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (month > 12 || month < 1)
		return -1;
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapYearDays[month - 1] < day || day < 1)
			return 1;
	}
	else
	{
		if (flatYearDays[month - 1] < day || day < 1)
			return 1;
	}
	return 0;
}
void HUbtai::addOneDay()
{
	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	day++;

	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapYearDays[month - 1] < day)
		{
			day = 1;
			month++;
		}
	}
	else
	{
		if (flatYearDays[month - 1] < day)
		{
			day = 1;
			month++;
		}
	}
	if (month > 12)
	{
		month = 1;
		year++;
	}

}
int main()
{
	HUbtai od;
	int i;
	od.setDate(2019, 4, 28);
	od.displayDate();
	for (i = 0; i<100; i++)
		od.addOneDay();
	od.displayDate();
	return 0;
}

