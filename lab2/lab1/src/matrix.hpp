#ifndef MATRIX_HPP
#define MATRIX_HPP


class Matrix {
public:
  Matrix(int n);                               // Identity matrix constructor
  Matrix(int m, int n, double fill_value = 0); // Parameterized constructor

 
  Matrix(const Matrix &other);

  // TODO: what is the difference between this operator and copy c-tor?
  Matrix &operator=(const Matrix &other);

  ~Matrix();

  double get(int i, int j) const;
  void set(int i, int j, double value);
  int get_height() const;
  int get_width() const;

  // Mathematical operations
  void negate();  //flips the sign of EVERY element
  void add_in_place(const Matrix &other);
  Matrix multiply(const Matrix &other) const;

private:
  int rows;
  int cols;
  double *data; // Pointer to heap-allocated memory
};

#endif // MATRIX_HPP
