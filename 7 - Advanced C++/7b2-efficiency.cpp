/************
Efficiency in code is about how many lines of code, how much memory, and how complex the operations are.  We will talk about overall performance in terms of just time for now.
************/
// Thanks to www.pluralsight.com for the pieces of code regarding the timing

#include <iostream>
#include <chrono> //high-resolution clock


void slowSwap(char (&array)[26]){
	char temp = array[0];
	array[0] = array[25];
	array[25] = temp;
	temp = array[1];
	array[1] = array[24];
	array[24] = temp;
	temp = array[2];
	array[2] = array[23];
	array[23] = temp;
	temp = array[3];
	array[3] = array[22];
	array[22] = temp;
	temp = array[4];
	array[4] = array[21];
	array[21] = temp;
	temp = array[5];
	array[5] = array[20];
	array[20] = temp;
	temp = array[6];
	array[6] = array[19];
	array[19] = temp;
	temp = array[7];
	array[7] = array[18];
	array[18] = temp;
	temp = array[8];
	array[8] = array[17];
	array[17] = temp;
	temp = array[9];
	array[9] = array[16];
	array[16] = temp;
	temp = array[10];
	array[10] = array[15];
	array[15] = temp;
	temp = array[11];
	array[11] = array[14];
	array[14] = temp;
	temp = array[12];
	array[12] = array[13];
	array[13] = temp;
}

void fastSwap(char (&array)[26]){
	for(int i = 0; i < 26; i++){
		char temp = array[i];
		array[i] = array[25-i];
		array[i] = temp;
	}
}

int main(){

	auto start = std::chrono::high_resolution_clock::now(); 
	// Code to time:
	char array[26];
	array[0] = 'a';
	for(int i = 1; i<26;i++){
		array[i] = array[i-1]+1;
	}

	slowSwap(array);

	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsedSmall = finish - start;
	std::cout << "Elapsed time line-by-line swap: " << elapsedSmall.count() << " s\n";
	start = std::chrono::high_resolution_clock::now(); 
	// Code to time (part 2)
	fastSwap(array);
	
	finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsedLarge = finish - start;
	std::cout << "Elapsed time for swap in a loop: " << elapsedLarge.count() << " s\n";

	std::cout << "The first run takes " << (float)elapsedSmall.count()/elapsedLarge.count() << "x longer than the second run.\n";

	return 0;
}

/**
$./a.out
Elapsed time line-by-line swap: 3.02e-07 s
Elapsed time for swap in a loop: 2.41e-07 s
The first run takes 1.25311x longer than the second run.
**/