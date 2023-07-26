#include "MyString.h"
#include <iostream>
#include <cstring>

using std::cout;

MyString::MyString() : string{nullptr}
{
	string = new char[1];
	*string = '\0';
}

// string ctr
MyString::MyString(const char* String) : string {nullptr}
{
	cout << "string constructor: " << String << std::endl;
	if(String == nullptr)
	{
		string = new char[1];
		*string = '\0';
	}
	else
	{
		string = new char[std::strlen(String) + 1]; // + 1 so that it can save space for the null terminator '\0'
		strcpy_s(string, (std::strlen(String) + 1), String);
	}
}

// copy ctr
MyString::MyString(const MyString &source) : string(nullptr)
{
	cout << "copy constructor: " << source.string << std::endl;
	string = new char[std::strlen(source.string) + 1];
	strcpy_s(string, (std::strlen(source.string) + 1), source.string);
}

// move constructor
MyString::MyString(MyString&& move_source) noexcept : string(nullptr)
{
	cout << "move constructor: " << move_source.string << std::endl;

	string = new char[std::strlen(move_source.string) + 1];
	strcpy_s(string, (std::strlen(move_source.string) + 1), move_source.string);
	move_source.string = nullptr;
}

// copy assignment operator overloaded- used when we want to assign another object MyString with the = sign, when it is a L-value
MyString& MyString::operator=(const MyString &rhs)
{
	cout << "copy assignment operator!" << std::endl;

	if (this == &rhs) 
	{
		return *this;
	}
	delete [] string;
	string = new char[(strlen(rhs.string)) + 1];
	strcpy_s(string,(strlen(rhs.string) + 1),rhs.string);
	return *this;
}

// move assignment operator overloaded- used when you want to assign an R-Value to a MyString object;
MyString& MyString::operator=(MyString&& rhs)
{
	cout << "move assignment operator!" << std::endl;

	if (this == &rhs)
	{
		return *this;
	}
	delete[] this->string;
	this->string = rhs.string;
	rhs.string = nullptr;
	return *this;
}

MyString MyString::operator-() const 
{
	char* buffer = new char[(strlen(string))+1];
	strcpy_s(buffer, ((strlen(string)) + 1), string);
	for (size_t i = 0; i < strlen(buffer); i++)
	{
		buffer[i] = std::tolower(buffer[i]);
	}
	MyString temp {buffer};
	delete [] buffer;
	return temp;
}
#pragma warning(disable:4996) // Allowing to use strcpy and strcat without the strcat_s and strcpy_s
MyString operator+(MyString& lhs, MyString& rhs)
{
	char* buffer = new char[(strlen(lhs.string) + strlen(rhs.string) + 1)];
	strcpy(buffer,lhs.string);
	strcat(buffer, rhs.string);
	MyString temp {buffer};
	delete [] buffer;
	return temp;
}

bool MyString::operator==(MyString& rhs) 
{
	if(stricmp(this->string, rhs.string) == 0)
	{
		return true;
	}
	return false;
}

MyString MyString::operator*(int multiplyer) 
{
	char* buffer = new char [(strlen(this->string) * multiplyer) + 1];
	strcpy(buffer, this->string);
	for (size_t i = 0; i < multiplyer-1; i++)
	{
		strcat(buffer, this->string);
	}
	MyString temp{buffer};
	delete[] buffer;
	return temp;
}

void MyString::operator+=(MyString& rhs) 
{
	MyString temp{ *this + rhs };
	*this = temp;
}

MyString::~MyString()
{
	delete [] string;
}

int MyString::get_length() const
{
	return std::strlen(string);
}

void MyString::display() const
{
	cout << string << " : " << get_length() << std::endl;
}

char* MyString::get_string() const
{
	return string;
}