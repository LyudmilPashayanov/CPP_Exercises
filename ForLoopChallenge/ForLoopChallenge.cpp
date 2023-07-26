#include <iostream>
#include <vector>
#include <string>

using namespace std;

void PrintNumbers(vector<int> const& list);
void AddNumber(vector<int> & list);
void GetMeanNumber(vector<int> const& list);
void GetSmallestNumber(vector<int> const& list);
void GetLargestNumber(vector<int> const& list);
char GetInput();

int main()
{
	string hi = "hi"; 
	cout << hi;
	vector<int> list {}; 
	char input {};
	do 
	{
		input = GetInput();
		switch (input)
		{
			case 'p':
			case 'P':
			{
				PrintNumbers(list);
				break;
			}
			case 'a':
			case 'A':
			{
				AddNumber(list);
				break;
			}
			case 'm':
			case 'M':
			{
				GetMeanNumber(list);
				break;
			}
			case 's':
			case 'S':
			{
				GetSmallestNumber(list);
				break;
			}
			case 'l':
			case 'L':
			{
				GetLargestNumber(list);
				break;
			}
			case 'q':
			case 'Q':
			{
				cout << "Goodbye." << endl;
				break;
			}
			default:
			{
				cout << "Invalid entry. Try again." << endl << endl;
				break;
			}
		}

	} while (input != 'Q' && input != 'q');

	return 0;
}

char GetInput() 
{
	char input{};
	cout << "Please select an option: " << endl;
	cout << "P - prints all the numbers in the list." << endl;
	cout << "A - add a number to the list." << endl;
	cout << "M - Get the avarage of all numbers in the list." << endl;
	cout << "S - Get the smallest number in the list. " << endl;
	cout << "L - Get the largest number in the list. " << endl;
	cout << "Q - Quit." << endl << endl;

	cout << "Option: ";
	cin >> input;
	return input;
}

void PrintNumbers(vector<int> const & list) 
{
	cout << "[ ";
	for (size_t i = 0; i < list.size(); i++)
	{
		cout << list.at(i) << " ";
	}
	cout << "]" << endl;
}

void AddNumber(vector<int> & list)
{
	int add{ 0 };
	cout << "Please write the number you want to input: ";
	cin >> add;
	list.push_back(add);
}

void GetMeanNumber(vector<int> const& list)
{
	double avg{ 0.0 };
	double sum{ 0.0 };
	for (int i : list)
	{
		sum += i;
	}
	avg = sum / list.size();
	cout << "The avarage sum of the numbers in the list is: " << avg << endl;
}

void GetSmallestNumber(vector<int> const& list)
{
	if (list.size() > 0)
	{
		int smallest = list.at(0);

		for (int i : list)
		{
			if (smallest > i)
			{
				smallest = i;
			}
		}
		cout << "Smallest number in the list is: " << smallest << endl;
	}
	else
	{
		cout << "The list is empty, so there is no smallest number." << endl << endl;
	}
}

void GetLargestNumber(vector<int> const& list)
{
	if (list.size() > 0)
	{
		int largest = list.at(0);

		for (int i : list)
		{
			if (largest < i)
			{
				largest = i;
			}
		}
		cout << "Largest number in the list is: " << largest << endl;
	}
	else
	{
		cout << "The list is empty, so there is no largest number." << endl << endl;
	}
}