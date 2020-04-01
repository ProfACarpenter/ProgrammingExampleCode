/*****************
Let's start from 6c1 but create a longer list.  
*****************/

#include <iostream>
#include <fstream>
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
		// want a friend to be able to use the sequel/prequel pointers, rather than making them public
		friend void printSeries(book_c *ptr);
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
			//libraryItem_c::print(); // Commenting for simpler print on screen
			std::cout << title << " by " << author << std::endl;
			if(prequel){ 		// if the prequel is still NULL, don't print
				std::cout << "\t This book is preceded by: " << prequel->title << std::endl;
			}
			if(sequel){			// if the sequel is still NULL, don't print
				std::cout << "\t This book is followed by: " << sequel->title << std::endl;
			}
		}
};

// start at the first book, print it, then move to the next book (marked sequel)
void printSeries(book_c *ptr){
	while(ptr != NULL){
		std::cout << "------------------ \n";
		ptr->print();
		ptr = ptr->sequel;
	}

}

// dvd class has been removed from this example

int main(){


	book_c *book1 = new book_c(934001, true, "Fiction", "Harry Potter and the Sorcerer's Stone", "JK Rowling");
	book_c *book2 = new book_c(934002, true, "Fiction", "Harry Potter and the Chamber of Secrets", "JK Rowling");
	book_c *book3 = new book_c(934003, true, "Fiction", "Harry Potter and the Prisoner of Azkaban", "JK Rowling");
	book_c *book4 = new book_c(934004, true, "Fiction", "Harry Potter and the Goblet of Fire", "JK Rowling");
	book_c *book5 = new book_c(934005, true, "Fiction", "Harry Potter and the Order of the Phoenix", "JK Rowling");
	book_c *book6 = new book_c(934006, true, "Fiction", "Harry Potter and the Half-Blood Prince", "JK Rowling");
	book_c *book7 = new book_c(934001, true, "Fiction", "Harry Potter and the Deathly Hallows", "JK Rowling");

	// send the corresponding book the pre/sequel pointer
	book1->setSequel(book2);
	book2->setPrequel(book1);
	book2->setSequel(book3);
	book3->setPrequel(book2);
	book3->setSequel(book4);
	book4->setPrequel(book3);
	book4->setSequel(book5);
	book5->setPrequel(book4);	
	book5->setSequel(book6);
	book6->setPrequel(book5);
	book6->setSequel(book7);
	book7->setPrequel(book6);


	// we can start at any book; the system just takes the pointer and moves down the line
	std::cout << "If we started at book 1 \n"; 
	printSeries(book1);
	std::cout << "\n If we started at book 3 \n"; 
	printSeries(book3);
	std::cout << "\n If we started at book 6 \n"; 
	printSeries(book6);

	// if you new, you must delete
	delete book1;
	delete book2;
	delete book3;
	delete book4;
	delete book5;
	delete book6;
	delete book7;


	return 0;
}


