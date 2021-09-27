#ifndef MOVIES_H
#define MOVIES_H

#include "Movie.h"
#include <iostream>
#include <vector> 

class Movies
{
private:
    std::vector<Movie> movie_list; 
public:
    Movies();
    ~Movies();
    void add_Movie(std::string name, std::string rating, int watched);
    void count_Increment(std::string name);
    void print_Movies();
};

#endif // MOVIES_H
