#include "Movies.h"
#include <iostream>

using std::cout;
using std::endl;

int Movies::overall_movies_watched{ 0 };

Movies::Movies(vector<Movie> Movies) 
{
	movies = new vector<Movie>;
	*movies = Movies;
	cout << "Creating the object movies with new movies pointer. " << endl;
}

Movies::~Movies()
{
	delete movies;
	cout << "Destroying the movies object." << endl;
}

void Movies::DisplayMovies()
{
	if((*movies).size() == 0)
	{
		cout << "No movies are currently in the library. " << endl;
	}
	for (Movie movie: *movies)
	{
		movie.Display();
	}
}

void Movies::AddMovie(string Name, string Rating, int times_watched) 
{
	for (const Movie &movie : *movies)
	{
		if (movie.get_name() == Name)
		{
			cout << "This movies is already in the library. " << endl;
			return;
		}
	}
	Movie movie(Name, Rating, times_watched);
	cout << "Adding the movie in the library. " << endl;
	(*movies).push_back(movie);
}

void Movies::WatchMovie(string movieName) 
{
	for (Movie &movie : *movies)
	{
		if (movie.get_name() == movieName)
		{
			overall_movies_watched++;
			movie.WatchMovie();
			return;
		}
	}
	cout << "No movie with name: " << movieName <<" is in the library. "  << endl;
}

int Movies::GetOverallMovieWatches(){
	cout << "Overall movies watched during this session: " << overall_movies_watched << endl;
	return overall_movies_watched;
}

vector<Movie>* Movies::GetMovies() 
{
	return movies;
}


