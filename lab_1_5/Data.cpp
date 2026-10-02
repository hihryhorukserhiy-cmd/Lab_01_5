#include "Data.h"
#include <iostream>
#include <string>

using namespace std;

bool Data::isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Data::DaysInMonth(int year, int month)
{
    switch (month)
    { 
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        if (isLeapYear(year))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    default:
        return 0;
    }
   
}

Data::Data()
{
    triad.Init(2000, 1, 1);
}

void Data::SetTriad(const Triad& t)
{
    if (t.GetSecond() >= 1 && t.GetSecond() <= 12 && t.GetThird() >= 1 && t.GetThird() <= DaysInMonth(t.GetFirst(), t.GetSecond()))
    {
        triad = t;
    }
    else
    {
		triad.Init(2000, 1, 1);
    }
}

bool Data::SetYear(int y)
{
    if (y > 0)
    {
		triad.SetFirst(y);
        if (triad.GetSecond() == 2 && triad.GetThird() > DaysInMonth(y, 2))
        {
			triad.SetThird(DaysInMonth(y, 2));
        }
        return true;
    }
    return false;
}

bool Data::SetMonth(int m)
{
    if (m >= 1 && m <= 12)
    {
        triad.SetSecond(m);
        if (triad.GetThird() > DaysInMonth(triad.GetFirst(), m))
        {
			triad.SetThird(DaysInMonth(triad.GetFirst(), m));
        }
        return true;
    }
    return false;
}

bool Data::SetDay(int d)
{
    if (d >= 1 && d <= DaysInMonth(triad.GetFirst(), triad.GetSecond()))
    {
        triad.SetThird(d);
        return true;
    }
    return false;
}

bool Data::Init(int year, int month, int day)
{
    if (year > 0 && month >= 1 && month <= 12 && day >= 1 && day <= DaysInMonth(year, month))
    {
        triad.Init(year, month, day);
        return true;
    }
    triad.Init(2000, 1, 1);
    return false;
}

bool Data::Init(const Triad& t)
{
    return Init(t.GetFirst(), t.GetSecond(), t.GetThird());
}

void Data::Read()
{
    int y, m, d;
    do
    {
        cout << "¬вед≥ть р≥к: "; cin >> y;
        cout << "¬вед≥ть м≥с€ць: "; cin >> m;
        cout << "¬вед≥ть день: "; cin >> d;
        if (!Init(y, m, d))
        {
			cout << "Ќев≥рна дата. —пробуйте ще раз." << endl;
        }
	} while (triad.GetFirst() != y || triad.GetSecond() != m || triad.GetThird() != d);

}

string Data::toString() const
{
	string yStr = to_string(triad.GetFirst());
    string mStr = "";
    if (triad.GetSecond() < 10)
    {
        mStr = "0" + to_string(triad.GetSecond());
    }
    else
    {
        mStr = to_string(triad.GetSecond());
    }

    string dStr = "";
    if (triad.GetThird() < 10)
    {
        dStr = "0" + to_string(triad.GetThird());
    }
    else
    {
        dStr = to_string(triad.GetThird());
    }

    return dStr + "." + mStr + "." + yStr;
}

void Data::Display() const
{
    cout << toString() << endl;
}

void Data::IncrementDay()
{
    int d = triad.GetThird() + 1;
    int m = triad.GetSecond();
    int y = triad.GetFirst();

    if (d > DaysInMonth(y, m))
    {
        d = 1;
        m++;
        if (m > 12)
        {
            m = 1;
            y++;
        }
    }
    triad.Init(y, m, d);
}

void Data::IncrementMonth()
{
    int m = triad.GetSecond() + 1;
    int y = triad.GetFirst();
    int d = triad.GetThird();

    if (m > 12)
    {
        m = 1;
		y++;
    }
    if (d > DaysInMonth(y, m))
    {
        d = DaysInMonth(y, m);
    }
    triad.Init(y, m, d);
}

void Data::IncrementYear()
{
    int y = triad.GetFirst() + 1;
    int m = triad.GetSecond();
    int d = triad.GetThird();

    if (m == 2 && d == 29 && !isLeapYear(y))
    {
        d = 28;
    }
    triad.Init(y, m, d);
}

void Data::AddDays(int n)
{
    for (int i = 0; i < n; i++)
    {
        IncrementDay();
    }
}
