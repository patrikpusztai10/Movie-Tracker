#include "header.h"

void Movie::view_movie(const std::string& username)
{
    system("cls");
    bool found = false;
    std::ifstream fin("movies.csv");
    std::string line;
    std::cout<<"Rated movies:"<<std::endl;
    std::cout<<"---------------------------"<<std::endl;
    while (std::getline(fin, line))
        {
            std::stringstream ss(line);
            std::string movie_username, title, genre,rating;
            std::getline(ss, movie_username, ',');
            std::getline(ss, title, ',');
            std::getline(ss, genre, ',');
            std::getline(ss, rating, ',');
            if (movie_username==username)
            {

                std::cout<<"Title:"<<title<<std::endl;
                std::cout<<"Genre:"<<genre<<std::endl;
                std::cout<<"Rating:"<<rating<<std::endl;
                std::cout<<std::endl;

            }
        }
    std::ifstream fin2("watchlist.csv");
    std::string line2;
    std::cout<<"Movies from your watchlist:"<<std::endl;
    std::cout<<"---------------------------"<<std::endl;
        while (std::getline(fin2, line2))
        {
            std::stringstream ss(line2);
            std::string movie_username, title, genre;
            std::getline(ss, movie_username, ',');
            std::getline(ss, title, ',');
            std::getline(ss, genre, ',');
            if (movie_username==username)
            {

                std::cout<<"Title:"<<title<<std::endl;
                std::cout<<"Genre:"<<genre<<std::endl;
                std::cout<<std::endl;


            }
        }

    std::cout<<"Do you want to go back to the menu?"<<std::endl;
    std::cout<<"[1]Yes"<<std::endl<<"[2]No"<<std::endl;
    std::cout<<"Choose [1-2]:";
    int num4;
    std::cin>>num4;
    if(num4==1)
    {
        User user{" "," "," "};
        user.menu(username);
    }
    if(num4==2)
    {
       return ;
    }

    fin.close();
    fin2.close();
}
