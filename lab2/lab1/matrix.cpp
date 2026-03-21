#include "matrix.hpp"
#include <iostream>
#include <stdexcept>

Matrix::Matrix(int n) : rows(n), cols(n) {
  data = new double[n * n]; // Allocate a single flat array of n*n elements
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      data[i * n + j] = (i == j) ? 1.0 : 0.0; // Convert 2D (i,j) to 1D index, place 1 on diagonal, 0 elsewhere
    }
  }
}

Matrix::Matrix(int m, int n, double fill_value) : rows(m), cols(n) {
  data = new double[m * n];
  for (int i = 0; i < m * n; ++i)
    data[i] = fill_value;
}

Matrix::Matrix(const Matrix &other) : rows(other.rows), cols(other.cols) {
  data = new double[rows * cols];
  for (int i = 0; i < rows * cols; ++i)
    data[i] = other.data[i];
}

Matrix &Matrix::operator=(const Matrix &other) {
  if (this != &other) {
    delete[] data;
    rows = other.rows;
    cols = other.cols;
    data = new double[rows * cols];
    for (int i = 0; i < rows * cols; ++i)
      data[i] = other.data[i];
  }
  return *this;
}

Matrix::~Matrix() { delete[] data; }

double Matrix::get(int i, int j) const {
  if (i < 0 || i >= rows || j < 0 || j >= cols)
    throw std::out_of_range("Matrix index out of bounds");
  return data[i * cols + j];
}

void Matrix::set(int i, int j, double value) {
  if (i < 0 || i >= rows || j < 0 || j >= cols)
    throw std::out_of_range("Matrix index out of bounds");
  data[i * cols + j] = value;
}

int Matrix::get_height() const { return rows; }
int Matrix::get_width() const { return cols; }

void Matrix::negate() {
  for (int i = 0; i < rows * cols; ++i)
    data[i] = -data[i];
}

void Matrix::add_in_place(const Matrix &other) {
  if (rows != other.rows || cols != other.cols)
    throw std::invalid_argument("Matrix dimensions must match for addition");
  for (int i = 0; i < rows * cols; ++i)
    data[i] += other.data[i];
}

Matrix Matrix::multiply(const Matrix &other) const {
  if (cols != other.rows)
    throw std::invalid_argument(
        "Matrix dimensions incompatible for multiplication");
  Matrix result(rows, other.cols);
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < other.cols; ++j) {
      double sum = 0;
      for (int k = 0; k < cols; ++k) {
        sum += get(i, k) * other.get(k, j);
      }
      result.set(i, j, sum);
    }
  }
  return result;
}
