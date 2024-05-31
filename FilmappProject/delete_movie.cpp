#include"header.h"
void Movie::delete_movie(const std::string& username)
{
    std::ifstream movies_in("movies.csv");
    std::ofstream temp_movies_out("temp_movies.csv");
    std::string line;
    std::string movie_title,movie_year;
    std::cout<<"Enter the title of the movie you want to delete:";
    std::getline(std::cin >> std::ws, movie_title);
    std::cout<<"Enter the year the movie you want to delete was released:";
    std::getline(std::cin >> std::ws, movie_year);
    while (std::getline(movies_in, line)) {
        std::stringstream ss(line);
        std::string movie_username, title, genre, year_of_release, rating;
        std::getline(ss, movie_username, ',');
        std::getline(ss, title, ',');
        std::getline(ss, genre, ',');
        std::getline(ss, year_of_release, ',');
        std::getline(ss, rating, ',');
        if (movie_username!=username&&movie_title!=title&&movie_title!=year_of_release)
        temp_movies_out << line << std::endl;
        if(movie_username==username&&movie_title!=title)
                temp_movies_out << line << std::endl;
        }

    movies_in.close();
    temp_movies_out.close();
    std::remove("movies.csv");
    std::rename("temp_movies.csv", "movies.csv");
    std::ifstream watchlist_in("watchlist.csv");
    std::ofstream temp_watchlist_out("temp_watchlist.csv");

    while (std::getline(watchlist_in, line)) {
        std::stringstream ss(line);
        std::string movie_username, title, genre, year_of_release, rating;
        std::getline(ss, movie_username, ',');
        std::getline(ss, title, ',');
        std::getline(ss, genre, ',');
        std::getline(ss, year_of_release, ',');
        std::getline(ss, rating, ',');

        if (movie_username!=username&&movie_title!=title&&movie_title!=year_of_release)
        temp_watchlist_out << line << std::endl;
        if(movie_username==username&&movie_title!=title)
                temp_watchlist_out << line << std::endl;
        }


    watchlist_in.close();
    temp_watchlist_out.close();
    std::remove("watchlist.csv");
    std::rename("temp_watchlist.csv", "watchlist.csv");
}
