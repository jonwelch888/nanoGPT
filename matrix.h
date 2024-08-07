/*********************************************
* Name: Jon Welch
* Assignment: nanoGPT 
* Purpose of the file: This header file declares the Matrix class and its operations.
*********************************************/

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix
{
    public:
    Matrix(int rows, int cols);
    Matrix(const std::vector<std::vector<float>>& values);
    
    int rows() const;
    int cols() const;
    
    Matrix transpose() const;
    Matrix operator*(const Matrix& other) const;
    Matrix operator+(const Matrix& other) const;
    
    std::vector<float>& operator[](int index);
    const std::vector<float>& operator[](int index) const;

    private:
    std::vector<std::vector<float>> data_;
};

#endif // MATRIX_H
