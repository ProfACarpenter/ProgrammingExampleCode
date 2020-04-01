/*********
We briefly saw protected, but didn't see how it works.
Protected means that derived classes can use the variables as though they are private member functions of the derived class, but external to the class hierarchy, they appear inaccessible.  Protected variables are essentially public to the class hierarchy and private (meaning, can't be directly used) outside the classes. 
*********/

#include <iostream>
#include <string>

class base_c{
	private:
		int base_private;
	protected:
		int base_protected;
	public:
		int base_public;
		
		base_c(int a, int b, int c):base_private(a),base_protected(b),base_public(c){}
		void printBase(){
			std::cout << "From inside the base class: \n";
			std::cout << "Private: " << base_private << std::endl;
			std::cout << "Protected: " << base_protected << std::endl;
			std::cout << "Public: " << base_public << std::endl; 
		}
};

class derived_public_c:public base_c{
	public:
		derived_public_c(int a, int b, int c):base_c(a,b,c){}
		
		void printPublic(){
			std::cout << "From inside the derived public class class: \n";
			std::cout << "\t Private is not directly accessible from here." << std::endl;
			std::cout << "\t Protected (still seen as protected): " << base_protected << std::endl;
			std::cout << "\t Public (still seen as public): " << base_public << std::endl; 
		}
};

class derived_protected_c:protected base_c{
	public:
		derived_protected_c(int a, int b, int c):base_c(a,b,c){}
		void printProtected(){
			std::cout << "From inside the derived protected class class: \n";
			std::cout << "\t Private is not directly accessible from here." << std::endl;
			std::cout << "\t Protected (still seen as protected): " << base_protected << std::endl;
			std::cout << "\t Public (still seen as protected): " << base_public << std::endl; 
		}
};

class derived_private_c:private base_c{
	public:
		derived_private_c(int a, int b, int c):base_c(a,b,c){}
		void printPrivate(){
			std::cout << "From inside the derived private class class: \n";
			std::cout << "\t Private is not directly accessible from here." << std::endl;
			std::cout << "\t Protected (still seen as private): " << base_protected << std::endl;
			std::cout << "\t Public (still seen as private): " << base_public << std::endl; 
		}
};

int main(){

	base_c base(1,2,3);
	derived_public_c derived_public(4,5,6);
	derived_protected_c derived_protected(7,8,9);
	derived_private_c derived_private(10,11,12);

	base.printBase();
	std::cout << "----\n";
	derived_public.printPublic();
	std::cout << "----\n";
	derived_protected.printProtected();
	std::cout << "----\n";
	derived_private.printPrivate();
	std::cout << "----\n";

	std::cout << "From main: " << std::endl;
	std::cout << "Can't see anything from the derived_private, as everything is private.\n";
	std::cout << "Can't see anything from the derived_protected, as everything is protected, which can be seen inside the classes, but not outside.\n";
	std::cout << "Can only see the public variable " << derived_public.base_public << " from the derived_public \n";
	std::cout << "Can only see the public variable " << base.base_public << " from the base class \n";




	return 0;
}

