#include <iostream>
#include "MyString.h"
#include <vector>
using namespace std;

int main()
{
	MyString empty;
	MyString larry("lARRy");
	MyString barry;
	barry = MyString("barry"); // should be calling the move assignment operator;
	larry.display();
	larry = -larry;
	larry.display();
	MyString larryAndBarry {barry};
	larryAndBarry += larry;
	larryAndBarry.display();

	cout << (larry == barry) << endl;
	larry = barry;
	cout << (larry == barry) << endl;

	larry = barry * 3;
	larry.display();

	return 0;
}