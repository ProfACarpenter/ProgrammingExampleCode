/*********
A base class with any pure virtual functions is considered abstract, and thus cannot be instantiated in an object.  

In this case we show a completely abstract class with only pure virtual functions.
*********/

#include <iostream>
#include <string>

class abstract_c{

	public:
		virtual void print(float (array)[], int size) = 0;
		virtual float equation(float (array)[], int size) = 0;
};

class sum_c:public abstract_c{
	public:
		float equation(float (array)[], int size){
			float sum = 0;
			for(int i = 0; i < size; i++)
				sum += array[i];
			return sum;
		}
		void print(float (array)[], int size){
			std::cout << "This is a summing class, so the array of: ";
			for(int i = 0; i < size; i++){
				std::cout << array[i] << " ";
			}
			std::cout << std::endl << " gives a sum of " << equation(array, size) << std::endl;;
		}
};

class product_c:public abstract_c{
	public:
		float equation(float (array)[], int size){
			float product = 1;
			for(int i = 0; i < size; i++)
				product *= array[i];
			return product;
		}
		void print(float (array)[], int size){
			std::cout << "This is a multiplying class, so the array of: ";
			for(int i = 0; i < size; i++){
				std::cout << array[i] << " ";
			}
			std::cout << std::endl << " gives a product of " << equation(array, size) << std::endl;
		}
};

class zero_c:public abstract_c{
	public:
		float equation(float (array)[], int size){
			float count = 0;
			for(int i = 0; i < size; i++)
				if(array[i] == 0.0)
					count++;
			return count;
		}
		void print(float (array)[], int size){
			std::cout << "This is a zero counting class, so the array of: ";
			for(int i = 0; i < size; i++){
				std::cout << array[i] << " ";
			}
			std::cout << std::endl << " gives a count of " << equation(array, size) << " zeroes.\n";
		}
};

int main(){

	abstract_c *maths[3] = { 
	// each derived class is from the same abstract_c class (base class), so we can use pointers to go through it
		new sum_c,
		new product_c,
		new zero_c
	};

	float array1[] = {42.1, 3.3};
	float array2[] = {-1.2, -3.14159, 0.0, 121.5};

	for(int i = 0; i < 3; i++){
		maths[i]->print(array1, 2); //print will call the correct print functions based on the object's type, not the pointer's type
		maths[i]->print(array2, 4);
		std::cout << std::endl;
	}

	return 0;
}