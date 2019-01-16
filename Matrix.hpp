//
// Created by elkanatovey on 1/15/19.
//

#ifndef EX3CPP_MATRIX_HPP
#define EX3CPP_MATRIX_HPP

#include <vector>
#include <iosfwd>
#include <iostream>

template <class T>
class Matrix{

    std::vector<T> _matrixContainer;
//    using _matrixContainer = std::vector<T>;
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

    Matrix trans() const;

    Matrix& operator+=(const Matrix &other);

    Matrix& operator-=(const Matrix &other);

    bool isSquareMatrix()const;

    friend std::ostream& operator<<(std::ostream& out, const Matrix& m);

    T operator()(unsigned int row, unsigned int column)const;

    T& operator()(unsigned int row, unsigned int column);

    int rows(){ return _rows;};

    int cols(){ return _columns;};

    typename std::vector<T>::const_iterator it;

    typedef cons =
//    using const_iterator = typename _matrixContainer::const_iterator;
//    const_iterator cbegin() const
//    {
//        return typename _matrixContainer.cbegin();
//    }
//    const_iterator cend() const { return _matrixContainer.cend(); }


    ~Matrix()= default;

};

/**
 * default constructor
 * @tparam T
 */
template <class T>
Matrix<T>::Matrix()
{
    _rows = 1;
    _columns = 1;
    _matrixContainer.push_back(T(0));
}

/**
 * 0 constructor
 * @tparam T
 * @param rows
 * @param columns
 */
template <class T>
Matrix<T>::Matrix(unsigned int rows, unsigned int columns)
{
    _rows = rows;
    _columns = columns;
    _matrixContainer(_rows * _columns, T(0));
}

/**
 * copy in place
 * @tparam T
 * @param other
 * @return
 */
template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix &other)
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
    std::vector<T> temp = _matrixContainer;
    for(int i = 0; i< _matrixContainer.size(); i++)
    {
     temp[i] += other._matrixContainer[i];
    }
    return Matrix(_rows, _columns , temp);
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix &other) const
{
    if(other._rows != _rows| other._columns != _columns)
    {
        throw
    }
    std::vector<T> temp = _matrixContainer;
    for(int i = 0; i < _matrixContainer.size(); i++)
    {
        temp[i] -= other._matrixContainer[i];
    }
    return Matrix(_rows, _columns , temp);
}

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix &other) const
{
    if(other._rows != _columns| other._columns != _rows)
    {
        throw
    }
    std::vector<T> temp(_rows * other._columns, T(0));
    for(int i = 0; i < _rows; i++)
    {
        for(int j = 0; j < other._columns; j++)
        {
            for(int k = 0; k < other._rows; k++)
            {
                temp[i * _rows + j]
                += _matrixContainer[i * _rows + k] * other._matrixContainer[k * other._rows + j];
            }
        }
    }
    return Matrix(_rows, _columns, temp);
}

template<class T>
bool Matrix<T>::operator!=(const Matrix &other) const
{
    if(this == &other)
    {
        return false;
    }
    if(other._rows != _rows| other._columns != _columns)
    {
        return false;
    }
    for(int i = 0; i < _matrixContainer.size(); i++)
    {
        if(other._matrixContainer[i] != _matrixContainer[i])
        {
            return true;
        }
    }
    return false;
}

template<class T>
bool Matrix<T>::operator==(const Matrix &other) const
{
    return !(*this != other);
}

template<class T>
Matrix<T> Matrix<T>::trans() const
{
    if(!isSquareMatrix())
    {
        throw
    }
    T temp;
    for(int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _columns; j++)
        {
            temp = _matrixContainer[i * _rows + j];
            _matrixContainer[i * _rows + j] = _matrixContainer[j * _rows + i];
            _matrixContainer[j * _rows + i] = temp;
        }
    }
    return this;
}

template<class T>
bool Matrix<T>::isSquareMatrix() const
{
    return _columns == _rows;
}

template<class T>
std::ostream &operator<<(std::ostream &out, const Matrix<T> &m) {
    for(int i = 0; i < m._rows; i++) {
        for (int j = 0; j < m._columns; j++) {
            out << m._matrixContainer[i * m._rows + j] << "\t";
        }
        out << std::endl;
    }
    return out;
}

template<class T>
T Matrix<T>::operator()(unsigned int row, unsigned int column) const
{
    return this->_matrixContainer[row * _rows + column];
}

template<class T>
T &Matrix<T>::operator()(unsigned int row, unsigned int column)
{
    return &_matrixContainer[row * _rows + column];
}

template<class T>
Matrix<T>& Matrix<T>::operator+=(const Matrix &other)
{
    this = this + other;
    return *this;
}

template<class T>
Matrix<T>& Matrix<T>::operator-=(const Matrix &other)
{
    this = this - other;
    return *this;
}

template<class T>
T *Matrix<T>::iterator() {
    return _matrixContainer;
}


#endif //EX3CPP_MATRIX_HPP
