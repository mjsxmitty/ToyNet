

#ifndef __ESSENTIAL_CPP_CHAPTER_04_MATRIX_H__
#define __ESSENTIAL_CPP_CHAPTER_04_MATRIX_H__


class Matrix
{
public:
    Matrix(int row, int col);
    Matrix(const Matrix &rhs);
    ~Matrix();

    Matrix& operator+=(const Matrix &rhs);

    int col() const {return col_; }
    int row() const { return row_; }
public:
    Matrix& operator=(const Matrix &rhs);
private:
    int     row_,col_;
    double  *pmat_;
};

#endif // __ESSENTIAL_CPP_CHAPTER_04_MATRIX_H__
