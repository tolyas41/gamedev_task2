#include "Matrix.h"
#include <iostream>
#include <vector>
#include <string>

int main() {

//2. Contain a type conversion constructor that converts the 
//directly specified numerical constant with a sign into a class object.

	Matrix *first_obj = new Matrix(5, 3, 3);
	std::cout << "2. num object : \n\n";
	first_obj->get_array();			  
	
//4. Implement the correct work with objects of the developed class when copying, moving and initializing.
	
	std::cout << "\n\ncopy assignment operator : \n\n";
	Matrix object_operator;
	Matrix random_object(123, 2, 4);
	object_operator = random_object;
	object_operator.get_array();

	std::cout << "\n\nmove assignment operator : \n\n";
	object_operator = Matrix{ 2,3,3 };
	object_operator.get_array();

	//copy constructor
	Matrix copied_obj(*first_obj);
	delete first_obj;
	std::cout << "\n4. copied object from 2. num object : \n\n";
	copied_obj.get_array();


	//move constructor
	std::vector <Matrix> vec;
	vec.push_back(Matrix{ 1,4,4 });
	vec.push_back(Matrix{ 2,4,4 });
	vec.push_back(Matrix{ 3,4,4 });

//5. Contain the function of converting the internal structure of the object to a string, 
// so that later you can intuitively show the result on the screen. String format: 
// [a,b; c,d; Е], where a, b, c, d, Е Ц numbers.

	Matrix obj_tobeconvert(33, 3, 23);
	std::string string_array = obj_tobeconvert.array_converting(obj_tobeconvert);
	std::cout << "\nObject was converted to a string : " << std::endl;
	std::cout << string_array << std::endl;

//6. Contain a type conversion constructor that converts the directly specified 
//character type string (char *), which is a string representation of a mathematical 
//object, into a class object. The conversion process must verify that the input is correct.

	char numbers_1[]="101 202 303 404";
	
	int size_array_raw = sizeof numbers_1 / sizeof numbers_1[0];
	int size_array{1};
	for (int i = 0; i < size_array_raw; i++) {
		if (numbers_1[i] == ' ')
			size_array++;					//количество чисел в char numbers_1[] = количество пробелов +1
	}
	std::cout << "\nchar array was converted to object`s array : \n\n";
	Matrix *string_to_math = new Matrix(numbers_1, 4, size_array);	  // 4 - количество строк в массиве объекта Matrix
	string_to_math->get_array();									  // все строки одинаковые, с числами из char numbers_1[]


//3. Contain a type conversion constructor that converts a directly specified 
//2-dimensional array with numbers into a class object.
	std::cout << "\ndirectly specified 2d array was converted to object`s array : \n\n";
	int spec_array[4][3] = { {1,2,3},{4,5,6},{7,8,9},{10,11,12} };
	
	Matrix obj_from_spec_array(spec_array);
	obj_from_spec_array.get_array();



	return 0;
}