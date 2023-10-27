#include "matrix.h"

using namespace std;

Matrix::Matrix(int row, int col) : row_(row), col_(col)
{
    pmat_ = new double* [row_];
    for (int i = 0; i < row_; ++i)
    {
        pmat_[i] = new double;
    }
}

Matrix::Matrix(const Matrix &rhs) : row_(rhs.row_), col_(rhs.row_)
{
    pmat_ = new double* [row_];
    for (int i = 0; i < row_; ++i)
    {
        pmat_[i] = new double;
    }

    for (int ix = 0; ix < rhs.row(); ++ix)
    {
        for (int jx = 0; jx < rhs.col(); ++jx)
            pmat_[ix][jx] = rhs.pmat_[ix][jx];
    }
}

Matrix::~Matrix()
{
    Destory();
}

void Matrix::Destory()
{
    for (int i = 0; i < row_; ++i)
    {
        if (pmat_[i] != nullptr)
        {
            delete [] pmat_[i];
            pmat_[i] = nullptr;
        }
    }

    if (pmat_ != nullptr)
    {
        delete [] pmat_;
        pmat_ = nullptr;
    }
}

Matrix& Matrix::operator+=(const Matrix &rhs)
{
    for (int i = 0; i < rhs.col(); ++i)
    {
        for (int j = 0; j < rhs.row(); ++j)
        {
            pmat_[i][j] += rhs.pmat_[i][j];
        }
    }

    return *this;
}

Matrix& Matrix::operator=(const Matrix &rhs)
{
    if (this != &rhs)
    {
        Destory();

        col_ = rhs.col();
        row_ = rhs.row();

        for (int ix = 0; ix < rhs.row(); ++ix)
            for (int jx = 0; jx < rhs.col(); ++jx)
                pmat_[ix][jx] = rhs.pmat_[ix][jx];
    }

    return *this;
}

ostream& Matrix::Print(ostream &os)const
{
    for (int ix = 0; ix < row_; ++ix)
    {
        for (int jx = 0; jx < col_; ++jx)
            os << pmat_[ix][jx] << " ";
        os << endl;
    }

    return os;
}

ostream& operator<<(ostream &os, const Matrix &rhs)
{
    rhs.Print(os);
    return os;
}

Matrix operator+(const Matrix &lhs, const Matrix &rhs)
{
    Matrix ret(lhs);
    ret += rhs;
    return ret;
}