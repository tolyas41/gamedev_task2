#include "Matrix.h"
#include <iostream>


Matrix::Matrix()
	: rows(0), columns(0), grid_of_numbers(nullptr) {
}

//2. Contain a type conversion constructor that converts the 
//directly specified numerical constant with a sign into a class object.

Matrix::Matrix(int num, int in_columns, int in_rows) 
	: columns(in_columns), rows(in_rows) {
		grid_of_numbers = new int* [columns];					
		for (int i = 0; i < columns; i++) {
			grid_of_numbers[i] = new int[rows];
		}
		
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < rows; j++) {
				grid_of_numbers[i][j] = num;
			}
		}		
}

//3. Contain a type conversion constructor that converts a directly specified 
//2-dimensional array with numbers into a class object.

Matrix::Matrix(const int* array, int in_columns, int in_rows)
	: columns(in_columns), rows(in_rows) {
		grid_of_numbers = new int* [columns];		  
		for (int i = 0; i < columns; i++) {
			grid_of_numbers[i] = new int[rows];
		}
			
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < rows; j++) {
				grid_of_numbers[i][j] = array[i * rows + j];
			}	
		}
}

//destructor
Matrix::~Matrix() {
	for (int i = 0; i < columns; i++) {
		delete[] grid_of_numbers[i];
	}
	delete[] grid_of_numbers;
}

//deep copy constructor
Matrix::Matrix(const Matrix& source) 
	: columns(source.columns), rows(source.rows) {
		grid_of_numbers = new int* [columns];
		for (int i = 0; i < columns; i++) {
			grid_of_numbers[i] = new int[rows];
		}
		
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < rows; j++) {
				grid_of_numbers[i][j] = source.grid_of_numbers[i][j];
			}
		}	
}

//move constructor
Matrix::Matrix(Matrix&& source) 
	: columns(source.columns), rows(source.rows), grid_of_numbers(source.grid_of_numbers) {
		source.columns = 0;
		source.rows = 0;
		source.grid_of_numbers = nullptr;
}

//string to array conversion ctor
Matrix::Matrix(const char* char_array) {
	int str_numbers_length = 0;
	int ch = 0;
	while (char_array[ch] != '\0') {
		str_numbers_length++;
		ch++;
	}
	int str_cols{ 1 };
	for (int i = 0; i < str_numbers_length; i++) {
		if (char_array[i] == ';') {
			str_cols++;
		}
	}
	int str_rows{ 1 };
	for (int i = 0; char_array[i] != ';'; i++) {
		if (char_array[i] == ',') {
			str_rows++;
		}
	}
	bool valid_str_numbers = true;
	for (int i = 0; i < str_numbers_length; i++) {
		if (char_array[i] == '[' || (char_array[i] >= '0' && char_array[i] <= '9') ||
			char_array[i] == ']' || char_array[i] == ',' || char_array[i] == ';' ||
			char_array[i] == ' ' || char_array[i] == '\0') {
		}
		else {
			valid_str_numbers = false;
		}
	}
	if (valid_str_numbers) {
		columns = str_cols;
		rows = str_rows;
		grid_of_numbers = new int* [columns];
		for (int i = 0; i < columns; i++) {
			grid_of_numbers[i] = new int[rows];
		}
		int k = 0;
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < rows; j++) {
				grid_of_numbers[i][j] = 0;
				k++;
				if (char_array[k] == ' ') {
					k++;
				}
				while (char_array[k] >= '0' && char_array[k] <= '9') {
					grid_of_numbers[i][j] = grid_of_numbers[i][j] * 10 + char_array[k] - '0';
					k++;
				}
			}
		}
	}
	else {
		columns = 0;
		rows = 0;
		grid_of_numbers = nullptr;
		std::cout << "\n==INVALID STRING==\n";
	}
}

//copy assignment operator
Matrix& Matrix::operator=(const Matrix& source) noexcept {
	if (this != &source) {
		for (int i = 0; i < columns; i++) {
			delete[] grid_of_numbers[i];
		}
		delete[] grid_of_numbers;
		columns = source.columns;
		rows = source.rows;
		grid_of_numbers = new int* [columns];
		for (int i = 0; i < columns; i++) {
			grid_of_numbers[i] = new int[rows];
		}
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < rows; j++) {
				grid_of_numbers[i][j] = source.grid_of_numbers[i][j];
			}		
		}	
	}
	return *this;
}

//move operator
Matrix& Matrix::operator=(Matrix&& source) noexcept {
	if (this != &source) {
		for (int i = 0; i < columns; i++) {
			delete[] grid_of_numbers[i];
		}
		delete[] grid_of_numbers;
		columns = source.columns;
		rows = source.rows;
		grid_of_numbers = source.grid_of_numbers;

		source.columns = 0;
		source.rows = 0;
		source.grid_of_numbers = nullptr;
	}
	return *this;
}

//print every element of the object's array
void Matrix::print_array() {
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			std::cout << "Element at grid_of_numbers[" << i << "][" << j << "]: ";
			std::cout << grid_of_numbers[i][j] << std::endl;
		}
	}
}

//object to string converter
std::string Matrix::to_string(const Matrix& source) {
	std::string temp;
	temp += "[";
	for (int i = 0; i < source.columns; i++) {
		if (i != 0) {
			temp += "; ";
		}
		for (int j = 0; j < source.rows; j++) {
			temp += std::to_string(grid_of_numbers[i][j]);
			if (j != source.rows - 1) {
				temp += ",";
			}
		}
	}
	temp += "]";
	return temp;
}
