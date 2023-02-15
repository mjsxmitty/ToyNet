#include "matrix.h"


Matrix::Matrix(int row, int col) : row_(row), col_(col)
{
    pmat_ = new double [row_ * col_];
}

Matrix::Matrix(const Matrix &rhs) : row_(rhs.row_), col_(rhs.row_)
{
    int elem_cnt = row_ * col_;
    pmat_ = new double [row_ * col_];

    for (int ix = 0; ix < elem_cnt; ++ix)
        pmat_[ix] = rhs.pmat_[ix];
}

Matrix::~Matrix()
{
    delete [] pmat_;
}

Matrix& Matrix::operator+=(const Matrix &rhs)
{
    for (int i = 0; i < rhs.col(); ++i)
    {
        for (int j = 0; j < rhs.row(); ++j)
        {
            //pmat_[i][j] += rhs.pmat_[i][j];
        }
    }

    return *this;
}

Matrix& Matrix::operator=(const Matrix &rhs)
{
    if (this != &rhs)
    {
        col_ = rhs.col_;
        row_ = rhs.row_;

        int elem_cnt = row_ * col_;
        delete [] pmat_;
        pmat_ = new double [elem_cnt];

        for (int ix = 0; ix < elem_cnt; ++ix)
            pmat_[ix] = rhs.pmat_[ix];
    }

    return *this;
}