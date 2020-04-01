/*****************
new is used to create entities from the memory heap.  Its operator requires a data type, and then returns a pointer
 delete takes a pointer and reallocates the data/variables at the memory location
*****************/

#include <iostream>

struct bunchOfNumbers_s{
	int a, b, c;
	float d, e, f;
};

int main(){

	// syntax: type *pointerName = new type;
	bunchOfNumbers_s *ptr;
	std::cout << "Initial ptr (w/ no initialization) at a random location = " << ptr << std::endl;

	ptr = new bunchOfNumbers_s;
	std::cout << "New ptr (pointing to a struct) = " << ptr << std::endl;
	
	ptr->a = 1;
	ptr->b = 2;
	ptr->c = 3;
	ptr->d = 4;
	ptr->e = 5;
	ptr->f = 6;

	std::cout << ptr->a << " " << ptr->b << " " << ptr->c << " " << ptr->d << " " << ptr->e << " " << ptr->f << std::endl;

	//syntax: delete pointer
	delete ptr;
	std::cout << "After delete ptr (still has same value, but it is pointing at nothing) = " << ptr << std::endl;

	ptr = NULL; // always a good idea to reset the pointer after it deletes

	return 0;
}

