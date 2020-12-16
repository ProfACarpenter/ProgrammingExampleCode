/*****************
Let's make a FIFO of the same Harry Potter books.  
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
		std::string section; 
		std::string author;
		std::string title;
		book_c *newer, *older;		// use pointer to refer to a possible sequel
	public:
		friend book_c *read();
		friend void write(int, bool, std::string, std::string, std::string);
		friend void deleteAll();
		void setAll(std::string s, std::string a, std::string t){
			section = s;
			author = a;
			title = t;
			newer = NULL;
			older = NULL;
		}
		book_c(int code, bool co, std::string s, std::string t, std::string a):libraryItem_c(code, co), section(s), author(a), title(t){
			std::cout << title << " added." << std::endl;
				newer = NULL;
				older = NULL;
		}
		~book_c(){
			std::cout << title << " removed." << std::endl;
		}
		void print(){
			std::cout << title << " by " << author << std::endl;
		}
};

book_c *Oldest, *Newest = NULL;

// reading is destructive, so read/delete are pretty much the same
// always read from the oldest side
book_c *read(){ 

	if(Oldest != NULL){
		book_c *temp = Oldest;
		Oldest = Oldest->newer;		// reading removes it, so move oldest to next oldest
		if(Oldest)					// if empty, skip
			Oldest->older = NULL;	// make sure the oldest one points to nothing older
		else
			Newest = NULL;			// if empty, make sure Newest is reset also
		return temp;
	}
	else
		return NULL;				// nothing to read
}

// always write to the newest side
void write(int code, bool checked, std::string section, std::string title, std::string author){ 
	
	// Make a new entry
	book_c *newEntry = new book_c(code, checked, section, title, author);

	if(Newest == NULL){ 			// if empty, this new one is the newest and oldest
		Newest = newEntry;
		Oldest = newEntry;
	}
	else{
		newEntry->newer = NULL;		// new entry is the newest
		newEntry->older = Newest;	// newest entry is one newer, so have it point back to the send-to-newest
		Newest->newer = newEntry;	// second-to-newest points to newest
		Newest = newEntry;			// make sure Newest is at the newest node
	}

	return;
}

void deleteAll(){
	if(Newest == NULL) // if empty, do nothing
		return;
	else{
		std::cout << "\t Deleting the remainder: \n";
		book_c *temp = Oldest;			// save the oldest and the 2nd oldest
		book_c *temp2 = Oldest->newer;
		while(temp){					// stop when the list is empty
			delete temp;				// delete oldest
			temp = temp2;				// move pointers to the next 2
			if(temp2)
				temp2 = temp2->newer;
		}
		Oldest = NULL;					// reset pointers
		Newest = NULL;
	}
}

// dvd class has been removed from this example

int main(){

	book_c *temp = NULL; // This will be used to catch the nodes that are read

	// adding three
	write(934001, true, "Fiction", "Harry Potter and the Sorcerer's Stone", "JK Rowling");
	write(934002, true, "Fiction", "Harry Potter and the Chamber of Secrets", "JK Rowling");
	write(934003, true, "Fiction", "Harry Potter and the Prisoner of Azkaban", "JK Rowling");
	
	// reading two and printing the resulting node
	// if it return NULL, the list is empty and it can't delete
	temp = read();
	if(temp)
		delete temp;
	temp = read();
	if(temp)
		delete temp;

	write(934004, true, "Fiction", "Harry Potter and the Goblet of Fire", "JK Rowling");
	write(934005, true, "Fiction", "Harry Potter and the Order of the Phoenix", "JK Rowling");

	temp = read();
	if(temp)
		delete temp;
	temp = read();
	if(temp)
		delete temp;
	temp = read();
	if(temp)
		delete temp;

	write(934006, true, "Fiction", "Harry Potter and the Half-Blood Prince", "JK Rowling");

	// always have a delete all
	deleteAll();

	return 0;
}


