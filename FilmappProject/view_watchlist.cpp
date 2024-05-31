#include "header.h"
void Movie::view_watchlist(const std::string& username)
{
    std::ifstream fin("watchlist.csv");

    std::string line;

    if (fin.is_open())
    {
        while (std::getline(fin, line))
        {
            std::stringstream ss(line);
            std::string movie_username, title, genre, year_of_release;
            std::getline(ss, movie_username, ',');
            std::getline(ss, title, ',');
            std::getline(ss, genre, ',');
            std::getline(ss, year_of_release, ',');
            if (movie_username == username)
            {
                std::cout << "Title: " << title << std::endl;
                std::cout << "Genre: " << genre << std::endl;
                std::cout << "Year of release: " << year_of_release << std::endl;
                std::cout << "-----------------------" << std::endl;
            }
        }
        fin.close();
    }

    std::cout << "Have you watched any of these movies yet?" << std::endl;
    std::cout << "[1] Yes" << std::endl << "[2] No" << std::endl;
    int choose3;
    std::cout << "Choose [1-2]: ";
    std::cin >> choose3;

    if (choose3 == 1)
    {
        std::string watchlist_title, watchlist_year_of_release;
        std::cout << "Enter the title of the movie that you watched: ";
        std::cin.ignore();
        std::getline(std::cin, watchlist_title);
        std::cout << "Enter the year of release: ";
        std::getline(std::cin, watchlist_year_of_release);

        std::ifstream fin2("watchlist.csv");
        std::ofstream temp_watchlist_out1("temp_watchlist.csv");

        if (fin2.is_open() && temp_watchlist_out1.is_open())
        {
            while (std::getline(fin2, line))
            {
                std::stringstream ss(line);
                std::string movie_username, title, genre, year_of_release;
                std::getline(ss, movie_username, ',');
                std::getline(ss, title, ',');
                std::getline(ss, genre, ',');
                std::getline(ss, year_of_release, ',');

                if (title == watchlist_title && year_of_release == watchlist_year_of_release && movie_username == username)
                {
                    std::cout << "What do you rate this movie? (1-5): ";
                    int rating3;
                    std::cin >> rating3;
                    while (rating3 < 1 || rating3 > 5)
                    {
                        std::cout << "Number is not between 1 and 5. Enter a new rating: ";
                        std::cin >> rating3;
                    }

                    std::ofstream fout2("movies.csv", std::ios::app);
                    if (fout2.is_open())
                    {
                        fout2 << username << ',' << title << ',' << genre << ',' << year_of_release << ',' << rating3 << std::endl;
                        fout2.close();
                    }
                }
                else
                {
                    temp_watchlist_out1 << line << std::endl;
                }
            }
            fin2.close();
            temp_watchlist_out1.close();

            std::remove("watchlist.csv");
            std::rename("temp_watchlist.csv", "watchlist.csv");
        }
    }
    else if (choose3 == 2)
    {
        User user{" ", " ", " "};
        user.menu(username);
    }
}
