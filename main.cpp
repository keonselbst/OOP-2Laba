#include <iostream>
#include "Matrix.h"
#include <locale.h>

using namespace std;

int main()
{
	setlocale(0, "rus");
	int s;
	cout << "������� ����������� ���������� �������: ";
	cin >> s;
	Matrix* A = new Matrix(s);
	Matrix* B = new Matrix(s);
	int x = 1;
	cout << "������� ������ �������:\n";
	A->fillMatrix();
	cout << "������� ������ �������:\n";
	B->fillMatrix();
	while (x != 0) {
		cout << "�������� ����� ����:\n";
		cout << "1. ������� ����� ������.\n";
		cout << "2. ������� �������� ������.\n";
		cout << "3. ������� ������������ ������.\n";
		cout << "4. �������� ������� A �� �����.\n";
		cout << "5. �������� ������� B �� �����.\n";
		cout << "6. ��������� ������� A �� �����.\n";
		cout << "7. ��������� ������� B �� �����.\n";
		cout << "8. ��������������� ������� A.\n";
		cout << "9. ��������������� ������� B.\n";
		cout << "10. ���������� ������� A � ������� B.\n";
		cout << "11. ���������� ������� B � ������� A.\n";
		cout << "12. ������� ������� A.\n";
		cout << "13. ������� ������� B.\n";
		cout << "0. ��������� ������ ���������.\n";
		cin >> x;
		switch (x) {
		case 1:
		{
			cout << "����� ������ A � B:\n" << *A + *B;
			break;
		}
		case 2:
		{
			cout << "�������� ������ A � B:\n" << *A - *B;
			break;
		}
		case 3:
		{
			cout << "������������ ������ A � B:\n" << *A * *B;
			break;
		}
		case 4:
		{
			double tmp;
			cout << "������� �����, �� ������� �������� ������� A: ";
			cin >> tmp;
			*A *= tmp;
			break;
		}
		case 5:
		{
			double tmp;
			cout << "������� �����, �� ������� �������� ������� B: ";
			cin >> tmp;
			*B *= tmp;
			break;
		}
		case 6:
		{
			double tmp;
			cout << "������� �����, �� ������� ������ ������� A: ";
			cin >> tmp;
			*A /= tmp;
			break;
		}
		case 7:
		{
			double tmp;
			cout << "������� �����, �� ������� ������ ������� B: ";
			cin >> tmp;
			*B /= tmp;
			break;
		}
		case 8:
		{
			*A = A->transpose();
			break;
		}
		case 9:
		{
			*B = B->transpose();
			break;
		}
		case 10:
		{
			*A = *B;
			break;
		}
		case 11:
		{
			*B = *A;
			break;
		}
		case 12:
		{
			cout << *A;
			break;
		}
		case 13:
		{
			cout << *B;
			break;
		}
		case 0: break;
		default: cout << "������ ������ ���� ���.\n";
		}
	}
	delete A;
	delete B;
	return 0;
}