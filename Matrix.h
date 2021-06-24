#pragma once
#include <string>
#include <iostream>


class Matrix
{
	int columns;
	int rows;
	int** grid_of_numbers;
	static int default_columns, default_rows, default_numbers;
public:

	Matrix();
	Matrix(int num, int in_columns, int in_rows);

//2-dimensional array with numbers into a class object.
	Matrix(const int* array, int row, int col);

//copy constructor
	Matrix(const Matrix& source);

//copy assignment operator
	Matrix& operator=(const Matrix& source) noexcept;

//move constructor
	Matrix(Matrix&& source);

//move operator
	Matrix& operator=(Matrix&& source) noexcept;

//string to array conversion ctor
	Matrix(const char* char_array, int str_cols, int str_rows);
	~Matrix();
	
	void print_array();

	std::string to_string(const Matrix& source);
};

