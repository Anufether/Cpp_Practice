#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix
{
private:
    std::vector<std::vector<double>> data;
    int rows;
    int cols;

public:
    Matrix(int num_rows, int num_cols);

    int num_rows() const;
    int num_cols() const;

    void set(int row, int col, double value);
    double get(int row, int col) const;

    bool operator==(const Matrix &other) const;

    // 新增方法声明：替换矩阵中特定位置的值
    void replaceValue(int row, int col, double newValue);
    void print() const;

    std::vector<double>::iterator change_val(int row, std::vector<double> newValue);
};

#endif // MATRIX_H
