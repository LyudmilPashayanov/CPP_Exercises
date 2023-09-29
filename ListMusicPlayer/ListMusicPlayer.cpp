#include <iostream>
#include "Song.h"
#include <list>

int main()
{
    Song song1{ "Song_1" , "Author_1" , 5 };
    Song song2{ "Song_2" , "Author_2" , 1 };
    Song song3{ "Song_3" , "Author_3" , 2 };
    Song song4{ "Song_4" , "Author_4" , 5 };
    Song song5{ "Song_5" , "Author_5" , 2 };

    std::list<Song> playlist {song1,song2,song3,song4,song5};

    /*std::list<Song>::iterator */ auto iterator = playlist.begin();

    if(/*forward command */true)
    {
        iterator++;
        if (iterator == playlist.end())
        {
            iterator = playlist.begin();
        }
    }
    
    if(/*back command */true)
    {
        if (iterator == playlist.begin())
        {
            iterator = playlist.end();
        }
        else
        {
            iterator--;
        }
    }
    
    if(/*add song command */true)
    {
        Song newSongToAdd {"newSong","newAuthor",3};
        playlist.insert(iterator, newSongToAdd);
    }

    if(/*go to first song*/ true)
    {
        iterator = playlist.begin();
    }
}