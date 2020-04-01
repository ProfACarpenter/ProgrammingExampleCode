/*****************
Let's review 5e2 with more focus on the new/delete
*****************/

#include <iostream>
#include <string>

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
		libraryItem_c(int code, bool co):libraryBarCode(code),checkedOut(co){ }
		virtual void print(){
			std::cout << "Item code " << libraryBarCode;
			if(isCheckedOut())
				std::cout << " is checked out.\n";
			else
				std::cout << " is available.\n";
		}
};

class book_c:public libraryItem_c{
	protected:
		std::string section; 
		std::string author;
		std::string title;
		book_c *prequel;   	// use pointer to refer to a possible prequel
		book_c *sequel;		// use pointer to refer to a possible sequel
	public:
		void setAll(std::string s, std::string a, std::string t){
			section = s;
			author = a;
			title = t;
			prequel = NULL; // want to initialized pointers to NULL
			sequel = NULL;	// want to initialized pointers to NULL
		}
		book_c(int code, bool co, std::string s, std::string t, std::string a):libraryItem_c(code, co), section(s), author(a), title(t){
			std::cout << "New book created with code: " << libraryBarCode << std::endl;
				prequel = NULL;	// want to initialized pointers to NULL
				sequel = NULL;	// want to initialized pointers to NULL
		}
		void setSequel(book_c *ptr){
			sequel = ptr;		// here we can actually set the sequel
		}
		void setPrequel(book_c *ptr){
			prequel = ptr;		// here we can actually set the prequel
		}
		void print(){
			libraryItem_c::print(); // I can call the base version by specifying the scope
			std::cout << "\t" << title << " by " << author << std::endl;
			if(prequel){ 		// if the prequel is still NULL, don't print
				std::cout << "This book is preceded by: " << prequel->title << std::endl;
			}
			if(sequel){			// if the sequel is still NULL, don't print
				std::cout << "This book is followed by: " << sequel->title << std::endl;
			}
		}
};

// dvd class has been removed from this example

int main(){

	// new creates two books
	// they are 2 books in a series, so we want to create the prequel and sequel
	// can only set them when we have the books created

	book_c *bookOne = new book_c(24680, false, "Fiction", "Parable of the Sower", "Octavia Butler");
	book_c *bookTwo = new book_c(24681, true, "Fiction", "Parable of the Talents", "Octavia Butler");

	// send the corresponding book the pre/sequel pointer
	bookTwo->setPrequel(bookOne);
	bookOne->setSequel(bookTwo);

	bookOne->print();
	std::cout << "------\n";
	bookTwo->print();

	// if you new, you must delete
	delete bookOne;
	delete bookTwo;

	return 0;
}


