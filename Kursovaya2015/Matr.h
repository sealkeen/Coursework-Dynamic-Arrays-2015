#include "stdafx.h"
#include "iostream"
using namespace std;

										//Определяем тип данных "матрица целых чисел"
typedef int singleElem;  				//определение типа элементов массива
typedef singleElem *pStringOfElements;  //определение типа "указатель на singleElem"
typedef pStringOfElements *pSourceMatr;	//определение типа "указатель на указатель на singleElem"

									//Определяем дополнительную булевую матрицу, которая служит для определения
									//того, какие элементы надо занулить (которые программа не должна сортировать)
typedef bool boolVal;  				//определение типа элементов массива
typedef boolVal *pBoolStr;  		//определение типа "указатель на boolVal"
typedef pBoolStr *pBoolMatr;		//определение типа "указатель на указатель на boolVal"


class Matr
{
public :
	Matr::Matr(int strings, int rows);
	Matr::~Matr();
	void Matr::InitializeSource();
	void Matr::InitializeBool();
	void Matr::HandInput();
	void Matr::SortVstavka(); 
	void Matr::OutputSourceMatr();
	void Matr::OutputBoolMatr();
	void Matr::ZanulenieElementov(); 
private :
	int str; 
	int sto;
	pBoolMatr boolMatr;
	pSourceMatr srcMatr;
	bool allocated;
};

