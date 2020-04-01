#include <iostream>
#include <string>

// Function prototypes/declarations must have a return, a name, and the inputs (no names are necessary, but you can have them - one example of each is below

std::string encrypt(std::string);

std::string decrypt(std::string inputText);

int main(){

	int choice = 0;

	do{
		std::cout << "Encrypt (1), Decrypt (2), or Exit (0): ";
		std::cin >> choice;
		std::string text;

		if(choice == 1){
			std::cout << "Please input a word for encryption: ";
			std::cin >> text;
			std::cout << "The encrypted version is: " << encrypt(text) << std::endl;
		}
		else if(choice == 2){
			std::cout << "Please input a word for decryption: ";
			std::cin >> text;
			std::cout << "The decrypted version is: " << decrypt(text) << std::endl;
		}

	}while(choice != 0);
	std::cout << "Bye!\n";

}

//Function definitions can be done later, since the prototypes are declared prior to the function call. These can also be done in a separate file (typically another cpp with the prototypes in a header file)

std::string encrypt(std::string inputText){
	for(int i = 0; i < inputText.length(); i++){
		inputText[i]++;
		if(inputText[i] > 126)
			inputText[i] -= 93;
	}
	return inputText;
}

std::string decrypt(std::string inputText){
	for(int i = 0; i < inputText.length(); i++){
		inputText[i]--;
		if(inputText[i] < 33)
			inputText[i] += 93;
	}
	return inputText;
}
