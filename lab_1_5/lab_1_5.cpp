#include <iostream>
#include <Windows.h>
#include "Data.h"

using namespace std;

Data makeData(int y, int m, int d)
{
	Data dt;
	if (!dt.Init(y, m, d))
	{
		cout << "Помилка ініціалізації! Встановлено дату за замовчуванням (01.01.2000).\n" << endl;
	}
	return dt;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "=== 1. Перевірка базового класу Triad ===\n";
	Triad tr;
	tr.Init(10, 20, 30);
	cout << "Початкова трійка: "; tr.Display();
	tr.IncrementAll();
	cout << "Трійка після IncrementAll(): "; tr.Display();

	cout << "\n=== 2. Перевірка класу-контейнера Data ===\n";
	Data d1 = makeData(2024, 2, 28); // Високосний рік
	cout << "Дата d1: "; d1.Display();

	d1.IncrementDay();
	cout << "Після IncrementDay() (29 лютого): "; d1.Display();

	d1.IncrementDay();
	cout << "Після ще одного IncrementDay() (1 березня): "; d1.Display();

	d1.AddDays(35);
	cout << "Після AddDays(35): "; d1.Display();

	cout << "\n=== 3. Демонстрація покажчика на об'єкт (->) ===\n";
	Data* ptrData = new Data();
	ptrData->Init(2023, 12, 31);
	cout << "Дата через вказівник: "; ptrData->Display();
	ptrData->IncrementDay();
	cout << "Після переходу нв новий рік: "; ptrData->Display();
	delete ptrData;

	cout << "\n=== 4. Демонстрація динамічного масиву об'єктів ===\n";
	int n = 3;
	Data* arr = new Data[n];
	arr[0].Init(2025, 1, 15);
	arr[1].Init(2025, 6, 20);
	arr[2].Init(2025, 9, 1);

	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "] = ";
		arr[i].Display();
	}
	delete[] arr;

	cout << "\n=== 5. ІНтерактивне введення дати (Read()) ===\n";
	Data userData;
	userData.Read();
	cout << "Ви ввели дату: "; userData.Display();
	int addCount;
	cout << "Скільки днів додати? "; cin >> addCount;
	userData.AddDays(addCount);
	cout << "Оновлена дата: "; userData.Display();

	return 0;
}