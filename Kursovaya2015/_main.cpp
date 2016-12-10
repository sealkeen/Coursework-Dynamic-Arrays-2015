
//����������� : 
//�������� ������ �� ����
//"������ ���������� <������� ������������ ���������>"
//������� �� ������: ���������� ��������� ���� �����
//���������� ������� ����� ����� � ������� ����������� �� ������
//Created by Silkin Ivan (c) December 2015

#include "stdafx.h"
#include "Matr.h"

using namespace std;

int main()
{
	while (true)
	{
		int n = 0;   //����� ����� �������
		int m = 0;   //����� �������� �������

		bool answer = 0;

		setlocale(LC_ALL, "Russian");
		do 
		{
			cout << "\n���� ������� ����� �����!	: \n������� 2 ����� > 3 (������: 10 11):\n";
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

		cout << "������� 0 - ������� ���������� ����, ������� 1 � ������� ����� ����� enter.\n";
		
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
			cout << "�������� �������:\n";
			MatrixHandler.OutputSourceMatr();
			MatrixHandler.SortVstavka();
			cout << "������� � ���������������� ��������:\n" << endl;
			MatrixHandler.ZanulenieElementov();
			MatrixHandler.OutputSourceMatr();
		}
		else
		{
			cout << "\n\n���� ������� �� ������ � ���� ������� �� ������" << endl;
		}

		cout << endl;

		char isExit = 0;
		cout << "������� 1 ��� ������\n";
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




