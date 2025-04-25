

#ifndef __ESSENTIAL_CPP__MATRIX_H__
#define __ESSENTIAL_CPP__MATRIX_H__

#include <iostream>
class Matrix
{
    friend std::ostream& operator<<(std::ostream &os, const Matrix &rhs);
    friend Matrix operator+(const Matrix &lhs, const Matrix &rhs);
public:
    Matrix(int row, int col);
    Matrix(const Matrix &rhs);
    ~Matrix();

    Matrix& operator=(const Matrix &rhs);
public:
    Matrix& operator+=(const Matrix &rhs);

    int col() const {return col_; }
    int row() const { return row_; }

    double& operator()(int row, int col) { return pmat_[row][col]; }
    double operator()(int row, int col) const { return pmat_[row][col]; }

    std::ostream& Print(std::ostream &os = std::cout)const;
private:
    void Destory();
    void Assign(int row, int col);
private:
    int     row_,col_;
    double  **pmat_;
};

std::ostream& operator<<(std::ostream &os, const Matrix &rhs);
Matrix operator+(const Matrix &lhs, const Matrix &rhs);

#endif // __ESSENTIAL_CPP__MATRIX_H__
