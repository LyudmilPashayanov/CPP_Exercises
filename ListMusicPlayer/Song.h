#pragma once
#include <iostream>
#include <cstring>
#include <string>


class Song
{
	friend std::ostream& operator<<(std::ostream& os, const Song& obj);
private:
	std::string Name;
	std::string Author;
	int Rating;
public:
	Song(std::string SongName="Noname", std::string AuthorName="Unknown", int SongRating=-1);
	bool operator<(const Song& rhs) const;
	bool operator==(const Song& rhs) const;
};

std::ostream& operator<<(std::ostream& os, const Song& obj)
{
	os << obj.Name << "     " << obj.Author << "     " << obj.Rating;
	return os;
}


