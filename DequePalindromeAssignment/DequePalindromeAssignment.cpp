// DequePalindromeAssignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>

bool is_palindrome(std::string input);

int main()
{
	std::cout << is_palindrome("a sasdnta at nasa");
}

bool is_palindrome(std::string input)
{
	
	auto it = std::remove_if(input.begin(), input.end(), [](char x) {return x == ' '; });
	input.erase(it, input.end());
	std::transform(input.begin(), input.end(), input.begin(), ::toupper);

	std::deque<char> deq;
	for (auto c : input)
	{
		deq.push_back(c);
	}

	while(deq.size() > 1)
	{
		char front = deq.front();
		deq.pop_front();
		char back = deq.back();
		deq.pop_back();
		if(front!=back)
		{
			return false;
		}
	}		
	return true;
}