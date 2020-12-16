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
	public:
		void setAll(std::string s, std::string a, std::string t){
			section = s;
			author = a;
			title = t;
		}
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
		dvd_c(int code, bool co, std::string t, float rt):libraryItem_c(code, co), runTime(rt), title(t){
			std::cout << "New dvd created with code: " << libraryBarCode << std::endl;
		}
		void print(){
			libraryItem_c::print(); // I can call the base version by specifying the scope
			std::cout << "\t" << title << " (" << runTime << "hours)" << std::endl;
		}
};

int main(){

	// new can be used for inheritance also
	// new provides the pointers to items and allocates the memory

	libraryItem_c *allItems[3] = {
		new libraryItem_c(12345, false),
		new book_c(67890, true, "Africanfuturism", "Binti", "Nnedi Okorafor"),
		new dvd_c(13579, false, "Memento", 1.5)
	};

	// now with pointers I can move throughout the array
	for(int i = 0; i < 3; i++){
		allItems[i]->print();
	}
	
	// delete what you new	
	for(int i = 0; i < 3; i++){
		delete allItems[i];
	}

	return 0;
}


