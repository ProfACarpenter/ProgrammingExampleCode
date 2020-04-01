#include <iostream>
#include <string>

// Struct definition - Operator overloading must be done on classes/structs
struct fewNumbers_s{
	int i;
	float f;
	double d;
};

// This function will be called if we try to add two "fewNumbers_s" structs together
fewNumbers_s operator+(fewNumbers_s, fewNumbers_s);

// This function will be called when we try to use cout and struct, without doing the component pieces
std::ostream& operator<<(std::ostream&, fewNumbers_s);

int main(){

	fewNumbers_s structA, structB;

	structA.i = 2; structA.f = 3.3; structA.d = 4.44;
	structB.i = 20; structB.f = 30.3; structB.d = 40.44;

	fewNumbers_s structC = structA + structB; 
	// this will call the overloaded operator function

	std::cout << structA << std::endl; // the first << calls the overloaded function
	std::cout << structB << std::endl;
	std::cout << structC << std::endl;

	return 0;
}

// The compiler knows which function to match to based on the input type, since the names are the same
// In the operator function, we do need to have the breakdown per component of the struct
fewNumbers_s operator+(fewNumbers_s A, fewNumbers_s B){
	fewNumbers_s C;
	C.i = A.i + B.i;
	C.f = A.f + B.f;
	C.d = A.d + B.d;
	return C;
}

// ostream is the output stream, in this case cout; at the function call, it is one line, but here we break it down
std::ostream& operator<<(std::ostream& outputStream, fewNumbers_s localStruct){
	outputStream << "Numbers are: " << localStruct.i << " " << localStruct.f << " " << localStruct.d;
	return outputStream;
}