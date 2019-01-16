//
// Created by elkanatovey on 1/15/19.
//

#ifndef EX3CPP_MATRIX_HPP
#define EX3CPP_MATRIX_HPP

#include <vector>
#include <iosfwd>

template <class T>
class Matrix{

    std::vector<T> _matrixContainer;
    unsigned int _rows;
    unsigned int _columns;

public:

    Matrix();

    Matrix(unsigned int rows, unsigned int columns);

    Matrix(unsigned int rows, unsigned int columns, const std::vector<T>& cells):_rows(rows),
           _columns(columns), _matrixContainer(cells){};

    Matrix(const Matrix& toCopy):_rows(toCopy._rows), _columns(toCopy._columns), _matrixContainer
                                  (toCopy._matrixContainer){};  // to be checked



    Matrix& operator=(const Matrix& other);

    Matrix operator+(const Matrix& other) const;

    Matrix operator-(const Matrix& other) const;

    Matrix operator*(const Matrix& other) const;

    bool operator!=(const Matrix& other) const;

    bool operator==(const Matrix& other) const;

    Matrix trans(const Matrix& other) const;

    bool isSquareMatrix()const;

    friend std::ostream& operator<<(std::ostream& out, const Matrix& m);

    T operator()(unsigned int row, unsigned int column)const;

    T& operator()(unsigned int row, unsigned int column);



    ~Matrix()= default;

};

template <class T>
Matrix<T>::Matrix()
{
    _rows = 1;
    _columns = 1;
    _matrixContainer.push_back(T(0));
}

template <class T>
Matrix<T>::Matrix(unsigned int rows, unsigned int columns)
{
    _rows = rows;
    _columns = columns;
    for()
    _matrixContainer.push_back(T(0));
}

template<class T>
Matrix<T> &Matrix<T>::operator=(const Matrix &other)
{
    if(this == &other)
    {
        return *this;
    }
    this->_matrixContainer = other._matrixContainer;
    this->_columns = other._columns;
    this->_rows = other._rows;
    return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix &other) const
{
    if(other._rows != _rows| other._columns != _columns)
    {
        throw
    }
    return Matrix();
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix &other) const
{
    if(other._rows != _rows| other._columns != _columns)
    {
        throw
    }
    return Matrix();
}

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix &other) const
{
    if(other._rows != _columns| other._columns != _rows)
    {
        throw
    }
    return Matrix();
}

template<class T>
bool Matrix<T>::operator!=(const Matrix &other) const
{
    if(this == &other)
    {
        return true;
    }
    if()
    return false;
}


#endif //EX3CPP_MATRIX_HPP
