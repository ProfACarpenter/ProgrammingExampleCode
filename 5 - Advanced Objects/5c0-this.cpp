/*********
This is a pointer that is implicitly created inside every object.  You can call it from within the class to refer to a particular object's members. It is useful for debugging, but also for reusing names (among other functionality).
*********/

#include <iostream>
#include <string>

class item_c{
	protected: 
		std::string name;
		float price;

	public:
		void setName(std::string name){this->name = name;} // now the "this->name"  refers to the object's member 'name', while the "name" on its own is a local variable.  We can use the same names now, which may make it more readable 
		void setPrice(bool price){this->price = price;} 
		std::string getName(){return this->name;}
		float getPrice(){return this->price;}

		void printAll(){
			std::cout << name << ": " << "$" << price << std::endl;
		}
		
		item_c():name("empty"),price(0.0){
			std::cout << "Empty item created.\n";
		}
		item_c(std::string n, float p):name(n), price(p){
			std::cout << name << " created.\n";
		}
		~item_c(){
			std::cout <<  name << " destructed.\n";
		}

		void printItem(){
			std::cout << name << " cost(s) $" << price << std::endl;
		}
};

int main(){
item_c item1("Cheerios", 3.99);
	item_c item2("Milk", 2.79);

	item_c item3 = item1;
	item_c item4 = item2;
	
	std::cout << "----------------\n";
	
	item1.printAll();
	item2.printAll();
	item3.printAll();
	item4.printAll();

	std::cout << "----------------\n";
}
