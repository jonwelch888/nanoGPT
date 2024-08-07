/*********************************************
* Name: Jon Welch
* Assignment: nanoGPT Project
* Purpose of the file: This source file contains the implementation of the Matrix class.
* It handles operations such as addition, multiplication, and transposition.
* 
* @note This file is associated with [matrix.h]
*********************************************/

#include "matrix.h"

Matrix::Matrix(int rows, int cols) : data_(rows, std::vector<float>(cols, 0.0f))
{
    /*********************************************
    Constructor to initialize the Matrix with given rows and columns.
    
    @param rows : number of rows
    @param cols : number of columns
    *********************************************/
}

Matrix::Matrix(const std::vector<std::vector<float>>& values) : data_(values)
{
    /*********************************************
    Constructor to initialize the Matrix with given values.
    
    @param values : 2D vector of values
    *********************************************/
}

int Matrix::rows() const
{
    /*********************************************
    rows: Returns the number of rows in the matrix.
    @return : number of rows
    *********************************************/
    return data_.size();
}

int Matrix::cols() const
{
    /*********************************************
    cols: Returns the number of columns in the matrix.
    @return : number of columns
    @note : ternary operator instead of a classic if-statement for one line 
    *********************************************/
    return data_.empty() ? 0 : data_[0].size();
}

Matrix Matrix::transpose() const
{
    /*********************************************
    transpose: Returns the transpose of the matrix.
    @return : transposed matrix
    *********************************************/
    int rowCount = rows();
    int colCount = cols();
    Matrix result(colCount, rowCount);
    for (int i = 0; i < rowCount; ++i)
    {
        for (int j = 0; j < colCount; ++j)
        {
            result[j][i] = data_[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const
{
    /*********************************************
    operator*: Multiplies the matrix with another matrix.
    @param other : matrix to multiply with
    @return : resultant matrix
    *********************************************/
    if (cols() != other.rows())
    {
        throw std::invalid_argument("Matrix dimensions do not match for multiplication");
    }

    int rowCount = rows();
    int colCount = other.cols();
    int innerDim = cols();
    Matrix result(rowCount, colCount);

    for (int i = 0; i < rowCount; ++i)
    {
        for (int j = 0; j < colCount; ++j)
        {
            float sum = 0.0f;
            for (int k = 0; k < innerDim; ++k)
            {
                sum += data_[i][k] * other[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

Matrix Matrix::operator+(const Matrix& other) const
{
    /*********************************************
    operator+: Adds the matrix with another matrix.
    @param other : matrix to add with
    @return : resultant matrix
    *********************************************/
    if (rows() != other.rows() || cols() != other.cols())
    {
        throw std::invalid_argument("Matrix dimensions do not match for addition");
    }

    int rowCount = rows();
    int colCount = cols();
    Matrix result(rowCount, colCount);

    for (int i = 0; i < rowCount; ++i)
    {
        for (int j = 0; j < colCount; ++j)
        {
            result[i][j] = data_[i][j] + other[i][j];
        }
    }
    return result;
}

std::vector<float>& Matrix::operator[](int index)
{
    /*********************************************
    operator[]: Accesses a row of the matrix.
    @param index : row index
    @return : reference to the row
    *********************************************/
    return data_[index];
}

const std::vector<float>& Matrix::operator[](int index) const
{
    /*********************************************
    operator[]: Accesses a row of the matrix (const version).
    @param index : row index
    @return : const reference to the row
    *********************************************/
    return data_[index];
}
