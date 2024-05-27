#include "header.h"
void Movie::add_movie(const std::string& username)
{
    system("cls");
    std::string message = "Add new movie";
    int spaces = (115 - message.size()) / 2;
    std::cout << std::string(spaces, ' ') << message << std::endl;

    std::string title;
    std::string genre;
    unsigned int year_of_release, rating;

    std::cout << "Enter the following details:" << std::endl;
    std::cout << "Enter the title of the movie:";
    std::getline(std::cin >> std::ws, title);
    std::cout << "Enter the genre:";
   std::getline(std::cin >> std::ws, genre);
    std::cout << "Enter the year of release:";
    std::cin >> year_of_release;
    std::cout << "Enter the rating:";
    std::cin >> rating;

    Movie* movie = new Movie(title, genre, year_of_release, rating);
    std::ofstream fout("movies.csv", std::ios::app);
    if (fout.is_open())
    {
        fout << username << ',' << title << ',' << genre << ',' << year_of_release << ',' << rating << std::endl;
        fout.close();
    }

}

Movie::Movie(std::string title, std::string genre, unsigned int year_of_release,unsigned int rating )
{
    this->title=title;
    this->genre=genre;
    this->year_of_release=year_of_release;
    this->rating=rating;
}
