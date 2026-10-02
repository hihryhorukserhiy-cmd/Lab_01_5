#include "Triad.h"
#include <iostream>
#include <string>

using namespace std;

Triad::Triad()
{
	first = 0;
	second = 0;
	third = 0;
}

bool Triad::Init(int f, int s, int t)
{
	SetFirst(f);	
	SetSecond(s);
	SetThird(t);
	return false;
}

void Triad::Read()
{
	int f, s, t;
	cout << "¬вед≥ть перше число: "; cin >> f;
	cout << "¬вед≥ть друге число: "; cin >> s;
	cout << "¬вед≥ть третЇ число: "; cin >> t;
	Init(f, s, t);
}

std::string Triad::ToString() const
{
	return "(" + to_string(first) + ", " + to_string(second) + ", " + to_string(third) + ")";
}



void Triad::Display() const
{
	cout << ToString() << endl;
}

void Triad::IncrementAll()
{
	IncrementFirst();
	IncrementSecond();
	IncrementThird();
}






