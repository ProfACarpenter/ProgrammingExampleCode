/*********
Let's make a bunch of virtual functions at different levels, including a PURE virtual function
*********/

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

class arrayMath_c{ 
	// If a class has a pure virtual function, it CANNOT be instantiated as an object, as it is considered an abstract class
	// We can have some pure virtual functions, can have some just virtual functions, and then other functions that are just normal functions
	protected:
		const static int size = 5;
		float array[size];
	public:
		// if a virtual function is followed by "= 0;" it is considered a pure virtual function.  This is to serve as a place holder
		virtual float average() = 0; // pure virtual function
		virtual void print(){ // virtual function, but not pure
			std::cout << "The array is: ";
			for(int i = 0; i < size; i++)
				std::cout << array[i] << " ";
			std::cout << std::endl;
		}
		
		void initializeArrays(){  // just a typical function, can be called from any
			std::cout << "Enter 5 numbers: ";
			for(int i = 0; i < 5; i++){
				std::cin >> array[i];
			}
		}
		
};

class arithmetic_c:public arrayMath_c{
	public:
		void print(){
			arrayMath_c::print();
			std::cout << "The arithmetic average is = " << this->average() << std::endl;
		}

		float average(){
			float sum = 0;
			for(int i = 0; i < size; i++){
				sum += array[i];
			}
			return (float)sum/size;
		}
		
		arithmetic_c(){
			std::cout << "\t Arithmetic: \n";
			initializeArrays();
		}
		
};

class harmonic_c:public arrayMath_c{
	public:
		void print(){
			arrayMath_c::print();
			std::cout << "The harmonic average is = " << this->average() << std::endl;
		}
		float average(){
			float sum = 0; 
    		for (int i = 0; i < size; i++) {
        		sum = sum + (float)1 / array[i]; 
  			}
    		return (float)size/sum; 
    	}

		harmonic_c(){
			std::cout << "\t Harmonic: \n";
			initializeArrays();
		}

};

class geometric_c:public arrayMath_c{
	public:
		void print(){
			arrayMath_c::print();
			std::cout << "The geometric average is = " << this->average() << std::endl;
		}
		float average(){
			float product = 1; 
  			for (int i = 0; i < size; i++){
        		product = product * array[i]; 
        	}
        	return pow(product, (float)1/size);   
    	}
		geometric_c(){
			std::cout << "\t Harmonic: \n";
			initializeArrays();
		}
};


int main(){

	arithmetic_c arith;
	harmonic_c harm;
	geometric_c geo;

	arrayMath_c *arrayOfArrayMath[3] = {&arith, &harm, &geo};

	for(int i = 0; i < 3; i++){
		arrayOfArrayMath[i]->print();
		std::cout << "--\n";
	}

	return 0;
}