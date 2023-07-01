#include <iostream>
#include "Matrix.h"
#include <locale.h>

using namespace std;

int main()
{
	setlocale(0, "rus");
	int s;
	cout << "Введите размерность квадратной матрицы: ";
	cin >> s;
	Matrix* A = new Matrix(s);
	Matrix* B = new Matrix(s);
	int x = 1;
	cout << "Вводите первую матрицу:\n";
	A->fillMatrix();
	cout << "Вводите вторую матрицу:\n";
	B->fillMatrix();
	while (x != 0) {
		cout << "Выберите пункт меню:\n";
		cout << "1. Вывести сумму матриц.\n";
		cout << "2. Вывести разность матриц.\n";
		cout << "3. Вывести произведение матриц.\n";
		cout << "4. Умножить матрицу A на число.\n";
		cout << "5. Умножить матрицу B на число.\n";
		cout << "6. Разделить матрицу A на число.\n";
		cout << "7. Разделить матрицу B на число.\n";
		cout << "8. Транспонировать матрицу A.\n";
		cout << "9. Транспонировать матрицу B.\n";
		cout << "10. Приравнять матрицу A к матрице B.\n";
		cout << "11. Приравнять матрицу B к матрице A.\n";
		cout << "12. Вывести матрицу A.\n";
		cout << "13. Вывести матрицу B.\n";
		cout << "0. Завершить работу программы.\n";
		cin >> x;
		switch (x) {
		case 1:
		{
			cout << "Сумма матриц A и B:\n" << *A + *B;
			break;
		}
		case 2:
		{
			cout << "Разность матриц A и B:\n" << *A - *B;
			break;
		}
		case 3:
		{
			cout << "Произведение матриц A и B:\n" << *A * *B;
			break;
		}
		case 4:
		{
			double tmp;
			cout << "Введите число, на которое умножать матрицу A: ";
			cin >> tmp;
			*A *= tmp;
			break;
		}
		case 5:
		{
			double tmp;
			cout << "Введите число, на которое умножать матрицу B: ";
			cin >> tmp;
			*B *= tmp;
			break;
		}
		case 6:
		{
			double tmp;
			cout << "Введите число, на которое делить матрицу A: ";
			cin >> tmp;
			*A /= tmp;
			break;
		}
		case 7:
		{
			double tmp;
			cout << "Введите число, на которое делить матрицу B: ";
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
		default: cout << "Такого пункта меню нет.\n";
		}
	}
	delete A;
	delete B;
	return 0;
}