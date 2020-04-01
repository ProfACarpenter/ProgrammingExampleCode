/*****************
new is used to create entities from the memory heap.  Its operator requires a data type, and then returns a pointer
 delete takes a pointer and reallocates the data/variables at the memory location

 Let's look at it with a class.
*****************/

#include <iostream>

class libraryItem_c{
	protected:
		int libraryBarCode;
		bool checkedOut;
	public: 
		int getCode(){return libraryBarCode;}
		bool isCheckedOut(){return checkedOut;}
		void setCode(int code){libraryBarCode = code;}
		void checkOut(){
			std::cout << libraryBarCode << " checked out.\n";
			checkedOut = 1;}  // note: these are mutator functions
		void checkIn(){
			std::cout << libraryBarCode << " checked in.\n";
			checkedOut = 0;}
		libraryItem_c():libraryBarCode(00000), checkedOut(0){}
		libraryItem_c(int code, bool co):libraryBarCode(code),checkedOut(co){ }
		void print(){
			std::cout << "Item code " << libraryBarCode;
			if(isCheckedOut())
				std::cout << " is checked out.\n";
			else
				std::cout << " is available.\n";
		}
};

int main(){

	// syntax: type *pointerName = new type;
	libraryItem_c *itemPtr1 = new libraryItem_c;
	itemPtr1->setCode(12345);
	itemPtr1->checkOut();

	libraryItem_c *itemPtr2 = new libraryItem_c(67890, 0);

	itemPtr1->print();
	itemPtr2->print();

	// always delete what you new
	delete itemPtr1;
	delete itemPtr2;

	return 0;
}

