#include <iostream>
using std::string;
using std::cout;

std::string reverse_string(const std::string& str)
{
	std::string reversed;
	const char* str_p{ str.c_str() };
	int size = str.size();
	for (int i{ size - 1 }; i >= 0; i--)
	{
		reversed.push_back(*(str_p + i));
	}

	return reversed;
}

int main()
{
	string hi{ "hello" };
	string newString{ reverse_string(hi) };
	cout << newString;
}
