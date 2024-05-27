#include "header.h"

void Movie::view_movie(const std::string& username)
{
    system("cls");
    std::ifstream fin("movies.csv");
    std::string line;
    bool found = false;
    while (std::getline(fin, line))
    {
        std::istringstream linestream(line);
        std::string file_username, title, genre;
        unsigned int year_of_release, rating;

        std::getline(linestream, file_username, ',');
        std::getline(linestream, title, ',');
        std::getline(linestream, genre, ',');
        linestream >> year_of_release;
        linestream.ignore(1, ',');
        linestream >> rating;

        if (file_username == username)
        {
            found = true;
            std::cout << "Title: " << title << std::endl;
            std::cout << "Genre: " << genre << std::endl;
            std::cout << "Year of Release: " << year_of_release << std::endl;
            std::cout << "Rating: " << rating << std::endl;
            std::cout << "-----------------------" << std::endl;
        }
    }

    if (!found)
    {
        std::cout << "No movies found for user: " << username << std::endl;
    }

    fin.close();
}
