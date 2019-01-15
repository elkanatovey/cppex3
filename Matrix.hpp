//
// Created by elkanatovey on 1/15/19.
//

#ifndef EX3CPP_MATRIX_HPP
#define EX3CPP_MATRIX_HPP

#include <vector>

template <typename T>
class Matrix {

    std::vector<T> _matrixContainer;

public:

    Matrix(unsigned int rows, unsigned int columns);

    Matrix(unsigned int rows, unsigned int columns, const std::vector<T>& cells);


    ~Matrix()= default;

};


#endif //EX3CPP_MATRIX_HPP
