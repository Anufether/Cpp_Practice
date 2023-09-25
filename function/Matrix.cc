#include "Matrix.hpp"
#include <iostream>

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols)
{
    data.resize(rows, std::vector<double>(cols, 0.0));
}

int Matrix::num_rows() const
{
    return rows;
}

int Matrix::num_cols() const
{
    return cols;
}

void Matrix::set(int row, int col, double value)
{
    if (row >= 0 && row < rows && col >= 0 && col < cols)
    {
        data[row][col] = value;
    }
}

double Matrix::get(int row, int col) const
{
    if (row >= 0 && row < rows && col >= 0 && col < cols)
    {
        return data[row][col];
    }
    else
    {
        return 0.0; // 默认返回0.0
    }
}

bool Matrix::operator==(const Matrix &other) const
{
    if (rows != other.rows || cols != other.cols)
    {
        return false; // 行数或列数不同，直接返回false
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (data[i][j] != other.data[i][j])
            {
                return false; // 找到不同的元素，返回false
            }
        }
    }

    return true; // 没有找到不同的元素，返回true
}

// 在Matrix.cpp中添加新的方法定义：替换矩阵中特定位置的值
void Matrix::replaceValue(int row, int col, double newValue)
{
    if (row >= 0 && row < rows && col >= 0 && col < cols)
    {
        data[row][col] = newValue;
    }
}

// 打印矩阵的内容
void Matrix::print() const
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}