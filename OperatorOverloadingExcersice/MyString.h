#pragma once
class MyString
{

private:

	char* string;

public:

	friend MyString operator+(MyString& lhs, MyString& rhs);
	//default constr
	MyString();
	MyString(const char * string);
	
	//copy constr
	MyString(const MyString& source) ;
	
	//move constr
	MyString(MyString&& move_source)noexcept;

	//Destructor
	~MyString();

	// copy assignment operator overload
	MyString& operator=(const MyString& rhs);
	
	// move assignment operator overload
	MyString& operator=(MyString&& rhs);

	// - operator overload
	MyString operator-() const;
	// == equal operator overload
	bool operator==(MyString& rhs);
	MyString operator*(int multiplyer);
	void operator+=(MyString& rhs);
	int get_length() const;
	void display() const;
	char* get_string() const;

};

