#include <iostream>
#include <string> 
#include <vector>
#include "Movies.h"

int main()
{
    Movies my_movies;
    my_movies.print_Movies();
    my_movies.add_Movie("Big","PG-13",2);
    my_movies.add_Movie("Mulholland","R",2);
    my_movies.add_Movie("Lost Highway","R",2);
    my_movies.print_Movies();
    my_movies.count_Increment("Lost Highway");
    my_movies.print_Movies();
    return 0;
}


