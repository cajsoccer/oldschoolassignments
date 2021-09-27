#include "Movies.h"

Movies::Movies()
{
}

Movies::~Movies()
{
}

void Movies::add_Movie(std::string name, std::string rating, int watched)
{
    bool canAdd {true};
    for (Movie movie: movie_list)
    {
        if (movie.get_name() == name)
        {
            canAdd = false;
            std::cout << "Cannot add this movie since it's already there." << std::endl;
        }
    }
    if (canAdd)
    {
        Movie new_Movie = Movie(name, rating, watched);
        movie_list.push_back(new_Movie);
        std::cout << name << " has been added to the list." << std::endl;
    }
}
void Movies::count_Increment(std::string name)
{
    bool found = false;
    for (Movie &movie: movie_list)
    {
       if (movie.get_name() == name)
       {
           found = true;
           movie.inc_watched();
           std::cout << "The count for the movie " << name << " has been incremented." << std::endl;
       }
    }
    if (!found)
        std::cout << "No such film found within the list." << std::endl;
}
void Movies::print_Movies()
{
    std::cout << "The movies within are:" << std::endl;
    for (Movie movie: movie_list)
    {
        std::cout << "Name: " << movie.get_name() << std::endl;
        std::cout << "Rating: " << movie.get_rating() << std::endl;
        std::cout << "Watched: " << movie.get_watched() << std::endl;
    }
}

