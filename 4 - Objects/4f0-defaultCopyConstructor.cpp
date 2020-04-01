/*********
If you want to make copies of objects you can use a default copy constructor as below.  This requires no additional work from you, as the object simply copies each variable in a "member-wise" assignment.  
*********/

#include <iostream>
#include <string>

class item_c{
	private:
		std::string name;
		float price;
		bool perishable;
	public:
		void setName(std::string n){name = n;}
		void setPrice(float p){price = p;}
		void setPerishable(bool p){perishable = p;} 
		std::string getName(){return name;}
		float getPrice(){return price;}
		bool isPerishable(){return perishable;} //don't need to name the get with "get" in the name

		void printAll(){
			std::cout << name << "(";
			if(!perishable)
				std::cout << "not ";
			std::cout << "perishable): " << "$" << price << std::endl;
		}
		// constructors/destructors (must be public)
		item_c():name("empty"),price(0.0),perishable(false){
			std::cout << "Empty item created.\n";
		}
		item_c(std::string n, float pr, bool per):name(n),price(pr),perishable(per){
			std::cout << name << " created.\n";
		}
		~item_c(){
			std::cout << name << " destructed.\n";
		}
};

int main(){

	item_c item1("Cheerios", 3.99, 0);
	item_c item2("Milk", 2.79, 1);

	item_c item3 = item1;
	item_c item4 = item2;
	
	std::cout << "----------------\n";
	
	item1.printAll();
	item2.printAll();
	item3.printAll();
	item4.printAll();

	std::cout << "----------------\n";
}