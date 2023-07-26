#include <iostream>
#include <string>
using namespace std;


string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
string key{ "pxlVktTAaPRXLGQHrwNKvCFJUebnMmuIYODgEjzdhiosZSfqWcyB" };


string Encrypt(string const& message)
{
	string encrypted{};
	for (char i : message)
	{
		size_t indexToGet = alphabet.find(i);
		if (indexToGet != string::npos)
		{
			encrypted += key.at(indexToGet);
		}
		else
		{
			encrypted += i;
		}
	}

	return encrypted;
}

string Decrypt(string const& message)
{
	string decrypted {};
	for (char i : message)
	{
		size_t indexToGet = key.find(i);
		if (indexToGet != string::npos)
		{
			decrypted += alphabet.at(indexToGet);
		}
		else
		{
			decrypted += i;
		}
	}

	return decrypted;
}

int main()
{


	string message{};

	cout << "Enter your secret message: ";
	getline(cin, message);
	string encrypted{ Encrypt(message) };
	cout << endl <<"Encrypting to: " << encrypted;
	
	cout << endl << "Decrypting to: " << Decrypt(encrypted);


	return 0;
}