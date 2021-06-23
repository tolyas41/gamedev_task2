#include "Matrix.h"
#include <vector>

int main() {
	if (true) {

		//2. Contain a type conversion constructor that converts the 
		//directly specified numerical constant with a sign into a class object.

		Matrix* first_source = new Matrix(5, 3, 3);
		std::cout << "2. num object : \n\n";
		first_source->print_array();

		//4. Implement the correct work with objects of the developed class when copying, moving and initializing.

		std::cout << "\n\ncopy assignment operator : \n\n";
		//Matrix object_operator;
		//Matrix random_object(123, 2, 4);
		//object_operator = random_object;
		//object_operator.print_array();

		std::cout << "\n\nmove assignment operator : \n\n";
		Matrix moving_obj;
		moving_obj = Matrix{ 2,3,3 };
		moving_obj.print_array();

		//copy constructor
		Matrix copied_obj(*first_source);
		delete first_source;
		std::cout << "\n4. copied object from 2. num object : \n\n";
		copied_obj.print_array();


		//move constructor
		 Matrix move_ctr_obj(Matrix(1,1,1));
		 move_ctr_obj.print_array();

	//5. Contain the function of converting the internal structure of the object to a string, 
	// so that later you can intuitively show the result on the screen. String format: 
	// [a,b; c,d; …], where a, b, c, d, … – numbers.

		//Matrix object_tobeconvert(303, 3, 3);
		//std::string string_array = object_tobeconvert.to_string(object_tobeconvert);
		//std::cout << "\nobject was converted to a string : " << std::endl;
		//std::cout << string_array << std::endl;

		//6. Contain a type conversion constructor that converts the directly specified 
		//character type string (char *), which is a string representation of a mathematical 
		//object, into a class object. The conversion process must verify that the input is correct.

		char str_numbers[] = "[101,202,303; 404,505,606; 9,8,7]";
		int str_numbers_length = sizeof str_numbers / sizeof str_numbers[0];
		int str_cols{ 1 };
		for (int i = 0; i < str_numbers_length; i++)
			if (str_numbers[i] == ';') {
				str_cols++;
			}


		int str_rows{ 1 };
		for (int i = 0; str_numbers[i] != ';'; i++)
			if (str_numbers[i] == ',') {
				str_rows++;
			}


		bool valid_str_numbers = true;
		for (int i = 0; i < str_numbers_length; i++)
			if (str_numbers[i] == '[' || (str_numbers[i] >= '0' && str_numbers[i] <= '9') ||
				str_numbers[i] == ']' || str_numbers[i] == ',' || str_numbers[i] == ';' ||
				str_numbers[i] == ' ' || str_numbers[i] == '\0') {
			}
			else {
				valid_str_numbers = false;
			}

		//if (valid_str_numbers) {
		//	std::cout << "\nchar array was converted to object`s array : \n\n";
		//	Matrix* string_to_math = new Matrix(str_numbers, str_cols, str_rows);
		//	string_to_math->print_array();
		//	delete string_to_math;
		//}
		//else {
		//	std::cout << "\n==INVALID STRING==\n";
		//}
		//3. Contain a type conversion constructor that converts a directly specified 
		//2-dimensional array with numbers into a class object.

		std::cout << "\ndirectly specified 2d array was converted to object`s array : \n\n";
 
		//Matrix ni;
		//ni.print_array();

		return 0;
	}
}