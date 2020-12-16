/**************
When we use the template on a class, we can use the same benefits as the function template: flexible type, reduced code, increased reuse/abstraction, and resizability

We will use a matrix and associated features of a matrix as the foundation for this.
**************/
#include <iostream>
#include <string>

// T will be the variable type, and then RowSize and ColSize will be the array boundaries
template <class T, int RowSize, int ColSize>
class matrix_t{
	private: // if we didn't use templating, we would need a new class type for each data type
		T matrixArray[RowSize][ColSize];
	public:
		void print(){
			std::cout << "The array, as entered, is: \n";
			for(int i = 0; i < RowSize; i++){
				std::cout << "\t";
				for(int j = 0; j < ColSize; j++)
					std::cout << matrixArray[i][j] << " ";
				std::cout << std::endl;
			}
			return;
		}
		
		bool search(T searchVar){
			for(int i = 0; i < RowSize; i++)
				for(int j = 0; j < ColSize; j++)
					if(searchVar == matrixArray[i][j])
						return true;
			return false;
		}
	
		matrix_t(){
			std::cout << "Enter " << RowSize << " x " << ColSize << " variables:\n";
			for(int i = 0; i < RowSize; i++)
				for(int j = 0; j < ColSize; j++)
					std::cin >> matrixArray[i][j];

			print();
			return;
		}
};

int main(){

	matrix_t<int, 2, 2> intMatrix;

	matrix_t<char, 1, 4> charMatrix;

	matrix_t<std::string, 3, 2> stringMatrix;

	if(intMatrix.search(0))
		std::cout << "Found a 0 in the integer matrix\n";

	if(charMatrix.search('F'))
		std::cout << "Don't put in an F, that's a fail.\n";

	if(stringMatrix.search("Hello"))
		std::cout << "Hello to you too!\n";

}
