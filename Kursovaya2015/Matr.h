#include "stdafx.h"
#include "iostream"
using namespace std;

										//���������� ��� ������ "������� ����� �����"
typedef int singleElem;  				//����������� ���� ��������� �������
typedef singleElem *pStringOfElements;  //����������� ���� "��������� �� singleElem"
typedef pStringOfElements *pSourceMatr;	//����������� ���� "��������� �� ��������� �� singleElem"

									//���������� �������������� ������� �������, ������� ������ ��� �����������
									//����, ����� �������� ���� �������� (������� ��������� �� ������ �����������)
typedef bool boolVal;  				//����������� ���� ��������� �������
typedef boolVal *pBoolStr;  		//����������� ���� "��������� �� boolVal"
typedef pBoolStr *pBoolMatr;		//����������� ���� "��������� �� ��������� �� boolVal"


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

