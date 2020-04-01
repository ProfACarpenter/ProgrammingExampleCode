#include <iostream>

void helloRecursion(int);

int main(){

	int times = 0;
	std::cout << "Enter a number of times to print \"Hello, world!\": ";
	std::cin >> times;

	helloRecursion(times-1);
	return 0;
}

void helloRecursion(int iterations){
	std::cout << iterations+1 << " Hello, world!\n";
	if(iterations) // always have a way out or you end up with infinite calls
		helloRecursion(iterations-1);
	else
		exit(0); //leave the program right now and don't do anything else

}