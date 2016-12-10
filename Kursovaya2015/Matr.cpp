#include "stdafx.h"
#include "Matr.h"

//Конструктор матрицы
Matr::Matr(int rows, int columns)
{
	allocated = false;
	str = rows; sto = columns;
	srcMatr = new pStringOfElements[str];
	//выделение динамической памяти под массив						
	//указателей на строки массива
	for (int i = 0; i < str; i++) 				//цикл выделения памяти под каждую строку
		*(srcMatr + i) = new singleElem[sto];	//каждому элементу массива указателей
												//на строки присваивается адрес начала
												//области памяти, выделяемой под строку
	boolMatr = new pBoolStr[str];

	for (int i = 0; i < str; i++)
		*(boolMatr + i) = new boolVal[sto];

	allocated = true;
}

//Инициализация опциональными значениями
void Matr::InitializeSource( ) {
	if (!allocated) return;
	for (int i = 0; i < str; i++)
		for (int j = 0; j < sto; j++)
			*(*(srcMatr + i) + j) = (str*sto) - (i + j);
}

//Инициализация булевой сетки
void Matr::InitializeBool( )
{
	if (!allocated) return;
	for (int i = 0; i < str; i++)
		for (int j = 0; j < sto; j++)
			*(*(boolMatr + i) + j) = false;
}

//Ручной ввод чисел
void Matr::HandInput( )
{
	if (!allocated) return;
	int input = 0;
	int *inputPointer = &input;
	int *elemPointer;
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < sto; j++)
		{
			elemPointer = (*(srcMatr + i) + j);
			*elemPointer = 0;
			while (*elemPointer == 0)
			{
				try
				{
					cin >> *inputPointer;
					*elemPointer = (int)input;
				}
				catch (...)
				{
					cout << "Введите ещё раз для этой ячейки" << endl;
				}
			}

		}
	}
}

//Сортировка элементов массива по возрастанию методом вставки
void Matr::SortVstavka()
{
	boolVal * pointer = 0;
	if (!allocated) return;
	singleElem *curElem = 0;
	singleElem *nextElem = 0;

	if ((str >= 3) && (sto >= 3) && (str <= 500))
	{
#pragma region |sto > str| 
		//Соответственно, если количество столбцов больше строк :

		if (sto > str)
		{
			singleElem curTemp;
			int begStr = 0;
			int curStr = 0;
			double predelStr = 0;
			double predelSto = 0;
			//Этот цикл содержит 4 цикла выравнивания и повторяется столь-
			//ко раз, чтобы все элементы были выровнены по возрастанию
			const double BORDER = abs((str / 2) - sto + str + 1);
			for (int l = 0; l <= BORDER; l++)
			{
				(sto % 2 == 0) ? predelSto = sto / 2 : predelSto = (sto / 2) - 1;
				(str % 2 == 0) ? begStr = (str / 2) - 1 : begStr = (str / 2);
				predelStr = begStr + 1;
				int replacingLevel = begStr;

				//1-й цикл выравнивания
				for (int curSto = 0;
					curSto <= predelSto; curSto++)
				{
					curStr = begStr;
					if (predelStr >0)
						predelStr--;

					while (curStr >= predelStr)
					{
						boolVal *curBool = (*(boolMatr + curStr) + curSto);
						boolVal *nextBool = (*(boolMatr + curStr - 1) + curSto);
						curElem = (*(srcMatr + curStr) + curSto);
						curTemp = *curElem;
						if (curStr>0)
							nextElem =
							(*(srcMatr + curStr - 1) + curSto);

						if ((*curElem > *nextElem) && curStr > 0)
						{
							*curElem = *nextElem;
							*nextElem = curTemp;
						}
						if (curStr <= replacingLevel)
							*curBool = true;
						if (((curStr - 1) >= 0) &&
							((curStr + 1) <= str - 1))
						{
							//*nextBool = sto%2 == 0 ? true : false;
						}
						curStr--;
						if ((curSto > (sto / 2 + 1)))
							break;
					}
					replacingLevel++;
				}
				replacingLevel = begStr;

				predelStr = begStr + 1;
				//2-й цикл выравнивания
				for (int curSto = sto-1; curSto > predelSto; curSto--)
				{
					curStr = begStr;
					if (predelStr >0)
						predelStr--;

					while (curStr >= predelStr)
					{
						boolVal *curBool =
							(*(boolMatr + curStr) + curSto);
						boolVal *nextBool =
							(*(boolMatr + curStr - 1) + curSto);
						curElem = (*(srcMatr + curStr) + curSto);
						curTemp = *curElem;
						if (curStr>0)
							nextElem =
							(*(srcMatr + curStr - 1) + curSto);

						if ((*curElem > *nextElem) && curStr > 0)
						{
							*curElem = *nextElem;
							*nextElem = curTemp;
						}
						if (curStr <= replacingLevel)
							*curBool = true;
						if (((curStr - 1) >= 0) &&
							((curStr + 1) <= str - 1))
						{
							//*nextBool = sto % 2 == 0 ? true : false;
						}
						curStr--;
						if ((curSto < (sto / 2 - 1)))
							break;
					}
					replacingLevel++;
				}
				(str % 2 == 0) ? begStr = (str / 2) : begStr = (str / 2)+1;
				predelStr = begStr;

				replacingLevel = begStr;
				//3-й цикл выравнивания
				for (int curSto = (str % 2 == 0) ? 0 : 1; curSto <= predelSto; curSto++)
				{
					curStr = begStr;
					if (predelStr < str - 1)
						predelStr++;
					while (curStr <= predelStr)
					{
						boolVal *curBool =
							(*(boolMatr + curStr) + curSto);
						boolVal *nextBool =
							(*(boolMatr + curStr + 1)
								+ curSto);
						curElem =
							(*(srcMatr + curStr) + curSto);
						curTemp =
							*curElem;
						if (curStr<(str - 1))
							nextElem =
							(*(srcMatr + curStr + 1) + curSto);

						if ((*curElem > *nextElem)
							&& curStr < str - 1)
						{
							*curElem = *nextElem;
							*nextElem = curTemp;
						}

						if (curStr<=replacingLevel || curStr == begStr) {
							*curBool = true;
						}
						
						curStr++;
						if ((curSto >(sto / 2 + 1)))
							break;
					}
					replacingLevel++;
				}
				predelStr = begStr;

				replacingLevel = begStr;
				//4-й цикл выравнивания
				for (int curSto = str%2 == 0? sto - 1 : sto - 2;
					curSto > predelSto; curSto--)
				{
					curStr = begStr;
					if (predelStr < str - 1)
						predelStr++;

					while (curStr <= predelStr)
					{
						boolVal *curBool =
							(*(boolMatr + curStr) + curSto);
						boolVal *nextBool =
							(*(boolMatr + curStr + 1) + curSto);
						curElem = (*(srcMatr + curStr) + curSto);
						curTemp = *curElem;
						if (curStr<(str - 1))
							nextElem =
							(*(srcMatr + curStr + 1) +
								curSto);

						if ((*curElem > *nextElem) &&
							curStr < (str - 1))
						{
							*curElem = *nextElem;
							*nextElem = curTemp;
						}
						if(curStr<=replacingLevel)
							*curBool = true;
						curStr++;
						if ((curSto < ((sto / 2 - 1))))
							break;
					}
					replacingLevel++;
				}//4 end
			}
		}

		if (str % 2 != 0) {
			*(*(boolMatr + str / 2)) = true;
			*(*(boolMatr + str / 2) + sto - 1) = true;
		}

#pragma endregion

#pragma region |sto < str|

		if (sto < str)
		{
			singleElem curTemp;
			int begSto = 0;
			int begStr;
			if (str % 2 == 0)
				begStr = (str / 2) - 1;
			else
				begStr = (str / 2);

			for (int l = 0; l <= ((str / 2) - sto + str + 1); l++)
			{
				int curStr = begStr;
				double predelSto;
				double predelStr = 0;
				predelSto = sto / 2 - 1;
				predelStr = begStr + 1;
				begSto = 0;
				//1
				for (int curSto = begSto;
					curSto <= predelSto; curSto++)
				{
					curStr = begStr;
					if (predelStr >1)
						predelStr--;;

					while (curStr >= predelStr)
					{
						boolVal *curBool =
							(*(boolMatr + curStr) + curSto);
						curElem = (*(srcMatr + curStr) + curSto);
						curTemp = *curElem;
						if (curStr<(str - 1))
							nextElem =
							(*(srcMatr + curStr - 1) + curSto);
						if ((*curElem > *nextElem) &&
							curStr <(str - 1))
						{
							*curElem = *nextElem;
							*nextElem = curTemp;
						}
						*curBool = true;
						curStr--;
					}
				}
				//2-й цикл выравнивания
				predelStr = begStr + 1;										for (int curSto = sto - 1;
					curSto > predelSto; curSto--)
				{
					curStr = begStr;
					if (predelStr > 1)
						predelStr--;
					while (curStr >= predelStr)
					{
						boolVal *curBool =
							(*(boolMatr + curStr) + curSto);
						curElem = (*(srcMatr + curStr) + curSto);
						curTemp = *curElem;
						if (curStr<(str - 1))
							nextElem =
							(*(srcMatr + curStr - 1) + curSto);
						if ((*curElem > *nextElem) &&
							curStr <(str - 1))
						{
							*curElem = *nextElem;
							*nextElem = curTemp;
						}
						*curBool = true;
						curStr--;
					}
				}
				//3-й цикл выравнивания
				if (str % 2 == 0)
					begStr = (str / 2);
				else
					begStr = (str / 2);
				begSto = 0;
				predelStr = begStr - 1;
				for (int curSto = begSto;
					curSto <= predelSto; curSto++)
				{
					curStr = begStr;
					if (predelStr < (str - 1))
						predelStr++;;

					while (curStr <= predelStr)
					{
						boolVal *curBool =
							(*(boolMatr + curStr) + curSto);
						curElem = (*(srcMatr + curStr) + curSto);
						curTemp = *curElem;
						if (curStr<(str - 1))
							nextElem =
							(*(srcMatr + curStr + 1) + curSto);
						if ((*curElem > *nextElem) &&
							curStr < (str - 1))
						{
							*curElem = *nextElem;
							*nextElem = curTemp;
						}

						*curBool = true;
						curStr++;
					}
				}
				//4-й цикл выравнивания
				predelStr = begStr - 1;
				for (int curSto = sto - 1;
					curSto > predelSto; curSto--)
				{
					curStr = begStr;
					if (predelStr < (str - 1))
						predelStr++;
					while (curStr <= predelStr)
					{
						boolVal *curBool =
							(*(boolMatr + curStr) + curSto);
						curElem = (*(srcMatr + curStr) + curSto);
						curTemp = *curElem;
						if (curStr<(str - 1))
							nextElem =
							(*(srcMatr + curStr + 1) + curSto);
						if ((*curElem > *nextElem) &&
							curStr < (str - 1))
						{
							*curElem = *nextElem;
							*nextElem = curTemp;
						}
						*curBool = true;
						curStr++;
					}
				}

			}
		}
#pragma endregion

#pragma region |sto == str|

		if (sto == str)
		{
			singleElem curTemp;

			for (int l = 0; l <= ((str / 2) - sto + str + 1); l++)
			{
				int begSto = 0;
				int begStr = 0;
				int curStr = begStr;
				double predelSto = 0;
				double predelStr = 0;
				begSto = 0;

				if (str % 2 == 0)
					begStr = (str / 2) - 1;
				else
					begStr = (str / 2);

				(sto / 2 == 0) ? predelSto = sto / 2 :
					predelSto = (sto / 2) + 0.5;
				predelStr = begStr + 1;
				for (int curSto = begSto;
					curSto <= predelSto; curSto++)
				{
					curStr = begStr;
					if (predelStr >0)
						predelStr--;


					while (curStr >= predelStr)
					{
						boolVal *curBool =
							(*(boolMatr + curStr) + curSto);
						boolVal *nextBool =
							(*(boolMatr + curStr - 1) + curSto);
						curElem = (*(srcMatr + curStr) + curSto);
						curTemp = *curElem;
						if (curStr>0)
							nextElem =
							(*(srcMatr + curStr - 1) + curSto);

						if ((*curElem > *nextElem) &&
							curStr > 0)
						{
							*curElem = *nextElem;
							*nextElem = curTemp;
						}
						*curBool = true;

						curStr--;
					}
				}
				//2-й цикл выравнивания
				predelStr = begStr + 1;
				for (int curSto = sto - 1;
					curSto > predelSto; curSto--)
				{
					curStr = begStr;
					if (predelStr > 0)
						predelStr--;
					while (curStr >= predelStr)
					{
						boolVal *curBool =
							(*(boolMatr + curStr) + curSto);
						boolVal *nextBool =
							(*(boolMatr + curStr - 1) + curSto);
						curElem = (*(srcMatr + curStr) + curSto);
						curTemp = *curElem;
						if (curStr>0)
							nextElem = (*(srcMatr + curStr - 1) +
								curSto);
						if ((*curElem > *nextElem) &&
							curStr > 0)
						{
							*curElem = *nextElem;
							*nextElem = curTemp;
						}
						*curBool = true;
						curStr--;
					}
				}

				if (str % 2 == 0)
				{
					begStr = (str / 2);
					begSto = sto - 1;
				}
				else
				{
					begStr = (str / 2) + 1;
					begSto = sto - 2;
				}

				predelStr = begStr - 1;
				//3-й цикл выравнивания
				for (int curSto = begSto; curSto >= predelSto; curSto--)
				{
					curStr = begStr;
					if (predelStr < (str - 1))
						predelStr++;

					while (curStr <= predelStr)
					{
						boolVal *curBool =
							(*(boolMatr + curStr) + curSto);
						boolVal *nextBool =
							(*(boolMatr + curStr + 1) + curSto);
						curElem = (*(srcMatr + curStr) + curSto);
						curTemp = *curElem;
						if (curStr<(str - 1))
							nextElem = (*(srcMatr + curStr + 1) + curSto);

						if ((*curElem > *nextElem) &&
							curStr < (str - 1))
						{
							*curElem = *nextElem;
							*nextElem = curTemp;
						}
						*curBool = true;

						curStr++;
					}
				}

				if (str % 2 == 0)
				{
					begStr = (str / 2);
					begSto = 0;
				}
				else
				{
					begStr = (str / 2) + 1;
					begSto = 1;
				}

				predelStr = begStr - 1;
				//4-й цикл выравнивания
				for (int curSto = begSto;
					curSto < predelSto; curSto++)
				{
					curStr = begStr;
					if (predelStr < (str - 1))
						predelStr++;
					while (curStr <= predelStr)
					{
						boolVal *curBool =
							(*(boolMatr + curStr) + curSto);
						boolVal *nextBool =
							(*(boolMatr + curStr + 1) + curSto);
						curElem = (*(srcMatr + curStr) + curSto);
						curTemp = *curElem;
						if (curStr<(str - 1))
							nextElem =
							(*(srcMatr + curStr + 1) + curSto);
						if ((*curElem > *nextElem) &&
							curStr < (str - 1))
						{
							*curElem = *nextElem;
							*nextElem = curTemp;
						}
						*curBool = true;
						curStr++;
					}
				}
			}
		}
#pragma endregion
	}

	if ((str == 3) && (sto == 3))
	{
		int var = 0;
		int *one = (*(srcMatr + 1) + 1);
		int *two = (*(srcMatr + 0) + 1);
		if (one > two)
		{
			var = *one;
			*one = *two;
			*two = var;
		}
	}
}

//Название функции самодокументирующее
void Matr::ZanulenieElementov()
{
	if (!allocated) return;
	for (int stro = 0; stro <= (str - 1); stro++)
	{
		for (int stol = 0; stol <= (sto - 1); stol++)
		{
			if (*(*(boolMatr + stro) + stol) == false)
			{
				*(*(srcMatr + stro) + stol) = 0;
			}
		}
	}
}

//Опциональное выведение на экран консоли 
void Matr::OutputBoolMatr()
{
	if (!allocated) return;
	int i, j;
	for (i = 0; i < str; i++)
	{
		for (j = 0; j < sto; j++)
		{
			cout.width(3);	//ширина поля выводимого параметра
			cout << *(*(boolMatr + i) + j) << ' ';
		}
		cout << "\n\n";
	}
}

//Выведение на экран консоли 
void Matr::OutputSourceMatr()
{
	if (!allocated) return;
	int i, j;
	for (i = 0; i < str; i++)
	{
		for (j = 0; j < sto; j++)
		{
			cout.width(3);	//ширина поля выводимого параметра
			cout << *(*(srcMatr + i) + j) << ' ';
		}
		cout << "\n\n";
	}
}

//Деструктор
Matr::~Matr()
{
	if (!allocated) return;
	//Освобождение динамической памяти
	for (int i = 0; i < str; ++i)
	{
		delete srcMatr[i];
		delete boolMatr[i];
	}
	delete srcMatr;
	delete boolMatr;
}