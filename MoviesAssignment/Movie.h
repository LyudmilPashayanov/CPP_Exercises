#pragma once
#include <string>
using std::string;


class Movie
{
private:
	string name;
	string rating;
	int watch_count;
public:
	Movie(string Name, string Rating, int Watch_count = 0);
	void Display();
	string get_name() const { return name; };
	void WatchMovie();
};

