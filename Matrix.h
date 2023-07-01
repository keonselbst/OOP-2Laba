#pragma once
#include <iostream>

class Matrix {
    int size;
    double** p;
public:
    Matrix(int);
    Matrix(const Matrix& m);
    Matrix();
    ~Matrix();
    friend std::ostream& operator<<(std::ostream&, const Matrix&);
    friend std::istream& operator>>(std::istream&, Matrix&);
    void allocSpace();
    void fillMatrix();
    Matrix& operator=(const Matrix&);
    Matrix& operator+=(const Matrix&);
    Matrix& operator-=(const Matrix&);
    Matrix& operator*=(const Matrix&);
    Matrix& operator*=(double);
    Matrix& operator/=(double);
    Matrix transpose();
};


Matrix operator+(const Matrix&, const Matrix&);
Matrix operator-(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, double);
Matrix operator*(double, const Matrix&);
Matrix operator/(const Matrix&, double);