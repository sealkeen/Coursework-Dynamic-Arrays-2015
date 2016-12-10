
//Определение : 
//Курсовая работа на тему
//"Методы сортировки <Массивы динамические двумерные>"
//Задание на работу: Сортировка элементов всех строк
//двумерного массива целых чисел в порядке возрастания от центра
//Created by Silkin Ivan (c) December 2015

#include "stdafx.h"
#include "Matr.h"

using namespace std;

int main()
{
	while (true)
	{
		int n = 0;   //число строк матрицы
		int m = 0;   //число столбцов матрицы

		bool answer = 0;

		setlocale(LC_ALL, "Russian");
		do 
		{
			cout << "\nСорт матрицы целых чисел!	: \nВведите 2 числа > 3 (Пример: 10 11):\n";
			cin.sync();
			try
			{
				char n1[3], m1[3];
				cin >> n1 >> m1;
				n = (int)atof(n1);
				m = (int)atof(m1);
			}
			catch (...)
			{

			}
		} while (n < 3 || m < 3);

		Matr MatrixHandler = Matr(n, m);

		cout << "Введите 0 - матрица заполнится сама, введите 1 и вводите числа через enter.\n";
		
		char p {'2'};
		do {
			cin.sync();
			try { cin >> p; }
			catch (...) {}
		} while (p > '1' || p < '0');

		answer = p-48;

		if (!answer)
		{
			MatrixHandler.InitializeSource();
		}
		else
		{
			MatrixHandler.HandInput();
		}
		MatrixHandler.InitializeBool();

		if (n <= 500)
		{
			cout << "Исходная матрица:\n";
			MatrixHandler.OutputSourceMatr();
			MatrixHandler.SortVstavka();
			cout << "Матрица с отсортированными строками:\n" << endl;
			MatrixHandler.ZanulenieElementov();
			MatrixHandler.OutputSourceMatr();
		}
		else
		{
			cout << "\n\nВаша матрица НЕ ВЛЕЗЕТ в Вашу консоль по ширине" << endl;
		}

		cout << endl;

		char isExit = 0;
		cout << "Введите 1 для выхода\n";
		try
		{
			cin.sync();
			cin >> isExit;
			if (isExit == '1')
				return 0;
		}
		catch (...)
		{

		}
	}
}




