#include "Matrix.h"
#include <iostream>

using namespace std;


Matrix::Matrix(int _size) : size(_size)
{
    allocSpace();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {    
            p[i][j] = 0;
        }
    }
}

Matrix::Matrix() : size(1)
{
    allocSpace();
    p[0][0] = 0;
}

Matrix::~Matrix()
{
    for (int i = 0; i < size; ++i) {
        delete[] p[i];
    }
    delete[] p;
}

Matrix::Matrix(const Matrix& m) : size(m.size)
{
    allocSpace();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            p[i][j] = m.p[i][j];
        }
    }
}

Matrix& Matrix::operator=(const Matrix& m)
{
    if (this != &m) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                p[i][j] = m.p[i][j];
            }
        }
    }
    return *this;
}

Matrix& Matrix::operator+=(const Matrix& m)
{
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            p[i][j] += m.p[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& m)
{
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            p[i][j] -= m.p[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& m)
{
    Matrix temp(m.size);
    for (int i = 0; i < temp.size; ++i) {
        for (int j = 0; j < temp.size; ++j) {
            for (int k = 0; k < size; ++k) {
                temp.p[i][j] += (p[i][k] * m.p[k][j]);
            }
        }
    }
    return (*this = temp);
}

Matrix& Matrix::operator*=(double num)
{
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            p[i][j] *= num;
        }
    }
    return *this;
}

Matrix& Matrix::operator/=(double num)
{
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            p[i][j] /= num;
        }
    }
    return *this;
}
void Matrix::allocSpace() // создание пустой матрицы
{
    p = new double* [size];
    for (int i = 0; i < size; ++i) {
        p[i] = new double[size];
    }
}

void Matrix::fillMatrix() // заполнение матрицы руками
{
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cin >> p[i][j];
        }
    }
}

Matrix Matrix::transpose() 
{
    Matrix ret(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            ret.p[j][i] = p[i][j];
        }
    }
    return ret;
}
Matrix operator+(const Matrix& m1, const Matrix& m2)
{
    Matrix temp(m1);
    return (temp += m2);
}

Matrix operator-(const Matrix& m1, const Matrix& m2)
{
    Matrix temp(m1);
    return (temp -= m2);
}

Matrix operator*(const Matrix& m1, const Matrix& m2)
{
    Matrix temp(m1);
    return (temp *= m2);
}

Matrix operator*(const Matrix& m, double num)
{
    Matrix temp(m);
    return (temp *= num);
}

Matrix operator*(double num, const Matrix& m)
{
    return (m * num);
}

Matrix operator/(const Matrix& m, double num)
{
    Matrix temp(m);
    return (temp /= num);
}

ostream& operator<<(ostream& os, const Matrix& m) // потоковое вывод + ввод
{
    for (int i = 0; i < m.size; ++i) {
        os << m.p[i][0];
        for (int j = 1; j < m.size; ++j) {
            os << " " << m.p[i][j];
        }
        os << endl;
    }
    return os;
}

istream& operator>>(istream& is, Matrix& m)
{
    for (int i = 0; i < m.size; ++i) {
        for (int j = 0; j < m.size; ++j) {
            is >> m.p[i][j];
        }
    }
    return is;
}