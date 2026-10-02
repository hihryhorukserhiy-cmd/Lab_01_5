#pragma once
#include "Triad.h"
#include <string>

class Data
{
private:
	Triad triad;

	static bool  isLeapYear(int year);
	static int DaysInMonth(int year, int month);
public:	
	Data();

	Triad GetTriad() const { return triad; }
	void SetTriad(const Triad& t);

	int GetYear() const { return triad.GetFirst(); }
	int GetMonth() const { return triad.GetSecond(); }
	int GetDay() const { return triad.GetThird(); }

	bool SetYear(int y);
	bool SetMonth(int m);
	bool SetDay(int d);

	bool Init(int year, int month, int day);
	bool Init(const Triad& t);
	void Read();
	void Display() const;
	std::string toString() const;

	// Перевизначені методи збільшення на 1 з урахуванням календаря
	void IncrementDay();
	void IncrementMonth();
	void IncrementYear();

	void AddDays(int n);
};

