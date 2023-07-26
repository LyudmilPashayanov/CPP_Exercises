#include "Movie.h"
#include <iostream>
using std::cout;
using std::endl;

Movie::Movie(string Name, string Rating, int Watch_count) : name{ Name }, rating{Rating}, watch_count{Watch_count}
{
	cout << "Creating movie: " << name << endl;
}

void Movie::Display()
{
	cout << "Name: " << name <<  " <-> ";
	cout << "Rating: " << rating << " <-> ";
	cout << "Times Watched: " << watch_count << endl;
}
void Movie::WatchMovie() 
{
	watch_count++;
}

