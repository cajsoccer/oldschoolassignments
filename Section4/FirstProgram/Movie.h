#ifndef MOVIE_H
#define MOVIE_H
#include <string>

class Movie
{
private: 
    std::string name;
    std::string rating;
    int watched;
public:
    Movie(std::string name = "Default Name", std::string rating = "Default Rating" , int watched = 0);
    ~Movie();
    std::string get_name();
    std::string get_rating();
    int get_watched();
    void inc_watched();
};

#endif // MOVIE_H
