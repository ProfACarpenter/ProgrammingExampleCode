/*****************
Here is singly-linked list code, including add, remove, search, print, deleteAll
For the videos, we will split these up into multiple, to reduce the length 
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
		book_c *next;			// pointer to the next node
	public:
		friend void remove(std::string);
		friend void add(int, bool, std::string, std::string, std::string);
		friend void deleteAll();
		friend void search(std::string);
		friend void print();

		void setAll(std::string s, std::string a, std::string t){
			section = s;
			author = a;
			title = t;
			next = NULL;
		}
		book_c(int code, bool co, std::string s, std::string t, std::string a):libraryItem_c(code, co), section(s), author(a), title(t){
			std::cout << title << " added." << std::endl;
				next = NULL;
		}
		~book_c(){ std::cout << title << " removed." << std::endl; }
		void print(){ std::cout << title << " by " << author << std::endl; }
};

book_c *Head = NULL;

void print(){ 
	// start the beginning (Head)
	// iterate one entry at a time (temp = temp->next)
	// if the temp is 0/NULL, you have reached the end

	for(book_c *temp = Head; temp != NULL; temp = temp->next){
		temp->print(); // could also just use std::cout here
	}
	return;
}

void search(std::string searchString){ // try to match the title, one at a time
	if(Head == NULL){
		std::cout << "Empty list\n";
		return;
	}
	for(book_c *temp = Head; temp != NULL; temp = temp->next){ // same as above for loop
		if(temp->title == searchString){
			temp->print();
			return;
		}
	}
	std::cout << "Not found!\n"; //nothing was found, tell the user
	return;
}

void remove(std::string searchString){
	if(Head){ 
	// if it matches the head, we have to move the head to the next one or risk losing the whole list
		if(Head->title == searchString){
			book_c *deleteThisOne = Head;	// temporary pointer for deleted node
			Head = Head->next;				// move the head
			delete deleteThisOne;			// then delete
		}
		for(book_c *temp = Head; temp->next != NULL; temp = temp->next){
			if(temp->next->title == searchString){ 	// have to stop one early
				book_c *deleteThisOne = temp->next;	// temporary pointer for deleted node
				temp->next = temp->next->next;		// wrap around the deleted one
				delete deleteThisOne;				// then delete
			}
		}
		std::cout << "Not found!\n";
		return;
	}
	else
		std::cout << "Empty list\n";

}

void add(int code, bool co, std::string sec, std::string title, std::string auth){
	book_c *newEntry = new book_c(code, co, sec, title, auth);
	if(!Head)		// if the list is empty, this is the only one, so it is head
		Head = newEntry;
	else{
		book_c *temp;	// need temp after the loop, so must declare it early
		for(temp = Head; temp->next != NULL; temp = temp->next){} 
												// just moving to the end
												// empty on purpose
												// could have a pointer to the end
												// or add to the head

		temp->next = newEntry;					// tie the new one to the end
		newEntry->next = NULL;					// make sure to ground the new one, since it is at the end;
	}
}

void deleteAll(){
	if(Head == NULL) // if empty, do nothing
		return;
	else{
		std::cout << "\t Deleting the remainder: \n";
		book_c *temp = Head->next;		// save the Head and the 2nd to Head
		while(Head){					// stop when the list is empty
			delete Head;				// delete oldest
			Head = temp;				// move pointers to the next 2
			if(temp)
				temp = temp->next;		
		}
		Head = NULL;					// reset pointers
	}
}

// dvd class has been removed from this example

int main(){

	int choice = 0;
	std::string searchString;
	int code; bool checkedOut;
	std::string section, title, author;
	do{
		std::cout << "Enter 0 to exit\nEnter 1 to print\nEnter 2 to search\nEnter 3 to remove an entry\nEnter 4 to add an entry\n";
		std::cin >> choice;
		switch(choice){
			case 0: break;
			case 1: 
				print();
				break;			
			case 2:
				std::cout << "What are you looking for? ";
				std::cin.clear(); std::cin.ignore();
				getline(std::cin,searchString);
				search(searchString);
				break;
			case 3:
				std::cout << "What title are you removing? ";
				std::cin.clear(); std::cin.ignore();
				getline(std::cin,searchString);
				remove(searchString);
				break;
			case 4: 
				std::cout << "What are you adding (code, 0/1, section, title, author)? ";
				std::cin >> code >> checkedOut >> section >> title >> author;
				add(code, checkedOut, section, title, author);
				break;
			default: 
				std::cout << "Invalid choice!\n";
				break;
		}

	}while(choice!=0);

	// always have a delete all
	deleteAll();

	return 0;
}


