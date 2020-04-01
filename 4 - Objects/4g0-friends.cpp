/*********
If you want to make copies of objects you can use a default copy constructor as below.  This requires no additional work from you, as the object simply copies each variable in a "member-wise" assignment. 

Now we will create a custom copy constructor which also incorporates a static;
*********/

#include <iostream>
#include <iomanip>
#include <string>

class item_c{
	private:
		std::string name;
		float price;
		bool perishable;
		int localCount;
		
	public:
		friend void discount(item_c &localItem, float discount); 
		// friends must be declared inside the class

		static int itemCounter; // this will track how many item objects were created
		void setName(std::string n){name = n;}
		void setPrice(float p){price = p;}
		void setName(bool p){perishable = p;} 
		std::string getName(){return name;}
		float getPrice(){return price;}
		bool isPerishable(){return perishable;} //don't need to name the get with "get" in the name

		void printAll(){
			std::cout << localCount << " - ";
			std::cout << name << "(";
			if(!perishable)
				std::cout << "not ";
			std::cout << "perishable): " << "$" << price << std::endl;
		}
		// constructors/destructors (must be public)
		item_c():name("empty"),price(0.0),perishable(false){
			localCount = itemCounter++;
			std::cout << "Empty item created.\n";
		}
		item_c(std::string n, float pr, bool per):name(n),price(pr),perishable(per){
			localCount = itemCounter++;
			std::cout << name << " created.\n";
		}
		~item_c(){
			std::cout << name << " destructed.\n";
		}

		// Copy constructor
		// const means we can't change the item we are copying (copiedItem)
		// The const/& together make it so we can copy the original without changing it, but do so by reference for simplicity.
		// You then use the . notation to do member-wise manipulation of the copiedItem
		item_c(const item_c &copiedItem){
			localCount = itemCounter++; 
			name = copiedItem.name;
			price = copiedItem.price;
			perishable = copiedItem.perishable;
			std::cout << name << " copied.\n";
		}
};

int item_c::itemCounter = 1; // this allows us to initialize the static variable

void discount(item_c &localItem, float discount){
	localItem.price *= discount;
	std::cout.precision(2);
	std::cout << localItem.name << "'s new price is $" << std::fixed << localItem.price << std::endl;
}

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

	discount(item3, 0.90);

	std::cout << "----------------\n";
}