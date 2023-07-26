#pragma once

#include <vector>
#include "Movie.h"

using std::vector;

class Movies
{
private:
	static int overall_movies_watched;
	vector<Movie> *movies {};
public:

	Movies(vector<Movie> Movies);
	~Movies();
	void DisplayMovies();
	void AddMovie(string Name, string Rating, int times_watche=0);
	void WatchMovie(string movieName);
	static int GetOverallMovieWatches();
	vector<Movie>* GetMovies();
};

