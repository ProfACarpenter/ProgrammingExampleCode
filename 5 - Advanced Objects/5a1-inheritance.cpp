/*********
Inheritance takes a base class and creates new derived classes based off of it.  The derived classes add and adapt that base class.  
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
		void printItem(){
			std::cout << "Generic item, code " << libraryBarCode;
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
		void printBook(){
			std::cout << title << " by " << author << " with code " << libraryBarCode;
			if(isCheckedOut())
				std::cout << " is checked out.\n";
			else
				std::cout << " is available.\n";
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
		void printDVD(){
			std::cout << title << "(" << runTime << "hours), with code " << libraryBarCode;
			if(isCheckedOut())
				std::cout << " is checked out.\n";
			else
				std::cout << " is available.\n";
		}
};

int main(){

	libraryItem_c genericItem(12345, false);
	book_c bookItem(67890, true, "Africanfuturism", "Binti", "Nnedi Okorafor");
	dvd_c DVDItem(13579, false, "Memento", 1.5);

	genericItem.printItem();
	bookItem.printBook();
	DVDItem.printDVD();

	return 0;
}

