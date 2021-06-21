#include "Matrix.h"
#include <iostream>
#include <string>

Matrix::Matrix() {
}

//2. Contain a type conversion constructor that converts the 
//directly specified numerical constant with a sign into a class object.

Matrix::Matrix(int num, int set_width, int set_height) 
	: width{ set_width }, height{ set_height }{
	two_d_array = new int* [width];					
	for (int i = 0; i < width; i++)
		two_d_array[i] = new int[height];

	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			two_d_array[i][j] = num;
}

//3. Contain a type conversion constructor that converts a directly specified 
//2-dimensional array with numbers into a class object.

Matrix::Matrix(int array[][3]) 
	: width{ 4 }, height{ 3 } {
		two_d_array = new int* [width];		  
		for (int i = 0; i < width; i++)
			two_d_array[i] = new int[height];	
		
		for (int i = 0; i < width; i++)
			for (int j = 0; j < height; j++)
				two_d_array[i][j] = array[i][j];
}


Matrix::~Matrix() {
	delete [] two_d_array; 
}

//deep copy constructor
Matrix::Matrix(const Matrix& source) {
	width = source.width;
	height = source.height;
	two_d_array = new int* [width];
	for (int i = 0; i < width; i++)
		two_d_array[i] = new int[height];

	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			two_d_array[i][j] = source.two_d_array[i][j];
}

//move constructor
Matrix::Matrix(Matrix&& obj) noexcept
	: two_d_array(obj.two_d_array) {
	obj.two_d_array = nullptr;
}

//string to array conversion ctor
Matrix::Matrix(char char_array[], int number_of_rows, int size_array)
	: width{ number_of_rows }, height{ size_array } {

	two_d_array = new int* [size_array];
	for (int i = 0; i < size_array; i++)
		two_d_array[i] = new int[number_of_rows];

	for(int i = 0; i < number_of_rows; i++)
		for (int j = 0, k = -1; j < size_array; j++) {
			two_d_array[i][j] = 0;
			k++;
				while (char_array[k] >= '0' && char_array[k] <= '9') {
					two_d_array[i][j] = two_d_array[i][j] * 10 + char_array[k] - '0';
					k++;
				}
		}
}

void Matrix::get_array() {
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
		{
			std::cout << "Element at two_d_array[" << i
				<< "][" << j << "]: ";
			std::cout << two_d_array[i][j] << std::endl;
		}
}

std::string Matrix::array_converting(const Matrix& obj) {
	std::string temp;
	for (int i = 0; i < obj.width; i++) {
		temp += "\n";
		for (int j = 0; j < obj.height; j++) {
			temp += std::to_string(two_d_array[i][j]);
			temp += " ";
		}
	}
	return temp;
}

Matrix& Matrix::operator=(const Matrix& source){
	if (this != &source)
	{
		delete[] two_d_array;
		width = source.width;
		height = source.height;
		two_d_array = new int* [width];
		for (int i = 0; i < width; i++)
			two_d_array[i] = new int[height];

		for (int i = 0; i < width; i++)
			for (int j = 0; j < height; j++)
				two_d_array[i][j] = source.two_d_array[i][j];
	}
	return *this;
}

Matrix& Matrix::operator = (Matrix&& source) {
	if (this != &source)
	{
		delete[] two_d_array;
		width = source.width;
		height = source.height;
		two_d_array = source.two_d_array;
		source.two_d_array = nullptr;
	}
	return *this;
}

