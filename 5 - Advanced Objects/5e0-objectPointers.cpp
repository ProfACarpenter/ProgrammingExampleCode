/*********
Instead of creating objects through hardcoding, we can use pointers. 
Pointers and memory allocation will let us create data structures than grow/shrink dynamically (more on this in later sections).
We will introduce "new" and "delete" here also, but not dive into them too much (will be done in the next level).
We will start from the 5d1 code, but will only change main.
*********/

#include <iostream>
#include <string>

class libraryItem_c{
	protected: // We likely want derived classes to use these, so we make them protected instead of private

		int libraryBarCode;
		bool checkedOut;
		// could add plenty more, but not going to bother here, just for brevity


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
		libraryItem_c(int code, bool co):libraryBarCode(code),checkedOut(co){ }
		void print(){
			std::cout << "Item code " << libraryBarCode;
			if(isCheckedOut())
				std::cout << " is checked out.\n";
			else
				std::cout << " is available.\n";
		}

};

class book_c:public libraryItem_c{
	protected:
		std::string section; //fiction, non-fiction, reference,
		std::string author;
		std::string title;
	public:
		void setAll(std::string s, std::string a, std::string t){
			section = s;
			author = a;
			title = t;
		}
		// remember the constructors need inputs for the derived AND the base class
		book_c(int code, bool co, std::string s, std::string t, std::string a):libraryItem_c(code, co), section(s), author(a), title(t){
			std::cout << "New book created with code: " << libraryBarCode << std::endl;
		}
		void print(){
			libraryItem_c::print(); // I can call the base version by specifying the scope
			std::cout << "\t" << title << " by " << author << std::endl;
		}

};

class dvd_c:public libraryItem_c{
	protected:
		std::string title;
		float runTime;

	public:
		void setAll(float r, std::string t){
			runTime = r;
			title = t;
		}
		// remember the constructors need inputs for the derived AND the base class
		dvd_c(int code, bool co, std::string t, float rt):libraryItem_c(code, co), runTime(rt), title(t){
			std::cout << "New dvd created with code: " << libraryBarCode << std::endl;
		}
		void print(){
			libraryItem_c::print(); // I can call the base version by specifying the scope
			std::cout << "\t" << title << " (" << runTime << "hours)" << std::endl;
		}
};

int main(){

	//The following lines create pointers to classes and then use "new" to create the object.
	// new is an operator that goes to memory, gets bits, and allocates them in the form of the data type that follows it (libraryItem_c in this case).
	// It returns the memory location of the object, hence a pointer.
	libraryItem_c *genericItem = new libraryItem_c(12345, false);
	book_c *bookItem = new book_c(67890, true, "Africanfuturism", "Binti", "Nnedi Okorafor");
	dvd_c *DVDItem = new dvd_c(13579, false, "Memento", 1.5);

	genericItem->print();
	bookItem->print();
	DVDItem->print();

	// when you use "new," you should also delete when done

	delete genericItem;
	delete bookItem;
	delete DVDItem;

	return 0;
}

