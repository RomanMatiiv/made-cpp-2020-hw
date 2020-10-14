#include "matrix.h"

using namespace task;


class Matrix
{
public:

    Matrix()
    {
        matrix = create_matrix(1,1);
    }

    Matrix(size_t rows, size_t cols)
    {
        matrix = create_matrix(rows, cols);
    }

    ~Matrix()
    {
        delete_matrix(matrix);
    }
//    Matrix(const Matrix& copy);
//    Matrix& operator=(const Matrix& a);
//
//    double& get(size_t row, size_t col);
//    const double& get(size_t row, size_t col) const;
//    void set(size_t row, size_t col, const double& value);
//    void resize(size_t new_rows, size_t new_cols);
//
//    /* ??? */ operator[](size_t row);
//    /* ??? */ operator[](size_t row) const;
//
//    Matrix& operator+=(const Matrix& a);
//    Matrix& operator-=(const Matrix& a);
//    Matrix& operator*=(const Matrix& a);
//    Matrix& operator*=(const double& number);
//
//    Matrix operator+(const Matrix& a) const;
//    Matrix operator-(const Matrix& a) const;
//    Matrix operator*(const Matrix& a) const;
//    Matrix operator*(const double& a) const;
//
//    Matrix operator-() const;
//    Matrix operator+() const;
//
//    double det() const;
//    void transpose();
//    Matrix transposed() const;
//    double trace() const;
//
//    std::vector<double> getRow(size_t row);
//    std::vector<double> getColumn(size_t column);
//
//    bool operator==(const Matrix& a) const;
//    bool operator!=(const Matrix& a) const;

    // Your code goes here...
private:

    double** matrix;

    double** create_matrix(size_t rows, size_t cols)
    {
        size_t n_elements = rows * cols;
        double** array = new double* [rows];
        array[0] = new double[n_elements];

        for (int i = 0; i < rows; ++i)
        {
            array[i] = &array[0][i * cols];
        }

        return array;
    }

    void delete_matrix(double** array)
    {
        delete [] array[0];

        delete [] array;
    }

};