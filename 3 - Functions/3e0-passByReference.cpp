// If we wanted a function to be able to manipulate the variable, we can pass the variable by "reference" which refers to the memory address
// We can start with our encrypt/decrypt functions from 3b1-functionInputs.cpp

#include <iostream>
#include <string>

// The referenced variable will act as both an input and an output here, and will not make a copy.  The "inputText" variable from encrypt/decrypt and the "text" variable from main are the same variable, but with two names in their own places

void encrypt(std::string &inputText){
	for(int i = 0; i < inputText.length(); i++){
		inputText[i]++;
		if(inputText[i] > 126)
			inputText[i] -= 93;
	}
	return;
}
void decrypt(std::string &inputText){
	for(int i = 0; i < inputText.length(); i++){
		inputText[i]--;
		if(inputText[i] < 33)
			inputText[i] += 93;
	}
	return;
}


int main(){

	int choice = 0;

	do{
		std::cout << "Encrypt (1), Decrypt (2), or Exit (0): ";
		std::cin >> choice;
		std::string text;

		if(choice == 1){
			std::cout << "Please input a word for encryption: ";
			std::cin >> text;
			encrypt(text); 
			// instead of embedding the call and expecting a return, the encrypt function actually changes the value of text directly
			// Note you don't do anything different in terms of the argument
			std::cout << "The encrypted version is: " << text << std::endl;
		}
		else if(choice == 2){
			std::cout << "Please input a word for encryption: ";
			std::cin >> text;
			decrypt(text); 
			// instead of embedding the call and expecting a return, the decrypt function actually changes the value of text directly
			// Note you don't do anything different in terms of the argument
			std::cout << "The encrypted version is: " << text << std::endl;
		}

	}while(choice != 0);
	std::cout << "Bye!\n";

}