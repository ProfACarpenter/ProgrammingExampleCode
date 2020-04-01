#include <iostream>

void message(int time);

int main(){

	int times = 0;
	std::cout << "Enter a number of messages you want: ";
	std::cin >> times;

	message(times);
	return 0;
}

void message(int times) {
	std::cout << "This is the beginning of iteration " << times << std::endl;
	if(times > 0)
		message(times-1);
	else
		std::cout << "No more recursive iterations; heading back! \n";
	std::cout << "This is the end of iteration " << times << std::endl;
}
