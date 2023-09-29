#include "Song.h"

Song::Song(std::string SongName, std::string AuthorName, int SongRating) : Name{ SongName }, Author{ AuthorName }, Rating{ SongRating}
{ }

bool Song::operator<(const Song & rhs) const
{
	return this->Rating < rhs.Rating;
}

bool Song::operator==(const Song& rhs) const
{
	return this->Name == rhs.Name;
}
