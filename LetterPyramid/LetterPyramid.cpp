#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input { };

	cout << "Write your string: ";
	cin >> input;
	size_t initialSpaces { input.size() };

	for (size_t i = 1; i <= input.size(); i++)
	{
		size_t spaces{ ((initialSpaces * 2) - 2) / 2 };
		for (size_t l = 0; l < spaces; l++)
		{
			cout << " ";
		}
		for (size_t j = 0; j < i; j++)
		{
			cout << input.at(j);
		}

		for (size_t k = i-1; k > 0; k--)
		{
			cout << input.at(k-1);
		}
		for (size_t l = 0; l < spaces; l++)
		{
			cout << " ";
		}
		initialSpaces-- ;
		cout << endl;
	}

	return 0;
}