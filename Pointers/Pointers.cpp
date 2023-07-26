#include <iostream>

using namespace std;

int* apply_all(int *arr1,size_t size1, int* arr2, size_t size2);
void print(int* arr, size_t size);

int main()
{
	const size_t array_size_1 {5};
	const size_t array_size_2 {3};

	int array1[5]{ 1,2,3,4,5 };
	int array2[3]{ 10,20,30 };

	cout << "array 1: " << endl;
	print(array1, array_size_1);
	
	cout << "array 2: " << endl;
	print(array2, array_size_2);
	
	int* result {apply_all(array1,array_size_1,array2,array_size_2)};
	size_t result_size {array_size_1 * array_size_2};
	
	
	cout << "new array: " << endl;
	print(result, result_size);
	delete [] result;
	return 0;
}

void print(int* arr, size_t size) 
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int* apply_all(int* arr1, size_t size1, int* arr2, size_t size2) 
{
	const int newArraySize = size1 * size2;
	int *newArray = new int[newArraySize];
	int indexTracker{ 0 };
	for (size_t k = 0; k < size2; k++)
	{
		for (size_t i = 0; i < size1; i++)
		{
			newArray[indexTracker] = arr1[i] * arr2[k];
			indexTracker++;
		}
	}

	return newArray;
}
