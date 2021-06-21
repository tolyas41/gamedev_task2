#pragma once
#include <string>

class Matrix
{
	int width;
	int height;
	int** two_d_array;
public:

	Matrix();
	Matrix(int num, int set_width, int set_height);

//2-dimensional array with numbers into a class object.
	Matrix(int array[][3]);

//copy constructor
	Matrix(const Matrix& source);

//copy assignment operator
	Matrix& operator=(const Matrix& source);

//move constructor
	Matrix(Matrix&& obj) noexcept;

//move operator
	Matrix& operator = (Matrix&& source);

//string to array conversion ctor
	Matrix(char char_array[], int number_of_rows, int size_array);
	~Matrix();
	
	void get_array();

	std::string array_converting(const Matrix& obj);
};

