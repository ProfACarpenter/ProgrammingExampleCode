#include <iostream>
#include <string>

// function declarations must be done earlier in the code than the function call
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