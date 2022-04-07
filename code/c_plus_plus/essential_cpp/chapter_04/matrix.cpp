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
