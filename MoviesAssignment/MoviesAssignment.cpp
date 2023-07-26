#include <iostream>
#include "Movies.h"

using namespace std;


int main()
{
	vector<Movie> movies_vec {};
	Movies my_movies (movies_vec);
	my_movies.DisplayMovies();
	my_movies.AddMovie("NBA", "2");
	my_movies.AddMovie("NBA", "2");
	my_movies.AddMovie("Cinderella", "3",5);
	my_movies.DisplayMovies();
	my_movies.WatchMovie("NBA");
	my_movies.GetOverallMovieWatches();
	my_movies.WatchMovie("NBAx");
	my_movies.WatchMovie("NBA");
	my_movies.WatchMovie("Cinderella");
	my_movies.WatchMovie("Cinderella");
	my_movies.WatchMovie("Cinderella");
	my_movies.DisplayMovies();
	my_movies.GetOverallMovieWatches();

	Movies my_newMovies((*my_movies.GetMovies()));
	my_newMovies.DisplayMovies();
	my_newMovies.GetOverallMovieWatches();
	my_movies.WatchMovie("NBA");
	my_newMovies.WatchMovie("NBA");
	my_newMovies.DisplayMovies();

	return 0;
}