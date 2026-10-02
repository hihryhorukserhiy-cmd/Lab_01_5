
#pragma once
#include <string>

class Triad
{
private:
	int first;
	int second;
	int third;
public:
	Triad();

	int GetFirst() const { return first; }
	int GetSecond() const { return second; }
	int GetThird() const { return third; }

	void SetFirst(int value) { first = value; }
	void SetSecond(int value) { second = value; }
	void SetThird(int value) { third = value; }

	bool Init(int f, int s, int t);
	void Read();
	void Display() const;
	std::string ToString() const;

	// Методи збільшення полів на 1

	void IncrementFirst() { first++; }
	void IncrementSecond() { second++; }
	void IncrementThird() { third++; }
	void IncrementAll();
};

