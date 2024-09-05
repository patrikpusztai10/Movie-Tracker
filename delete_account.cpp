#include "header.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <cstdio>

void User::delete_account(const std::string& username) {
    std::ifstream accounts_in("accounts.csv");
    std::ofstream temp_accounts_out("temp_accounts.csv");
    std::string line;
    while (std::getline(accounts_in, line)) {
        std::stringstream ss(line);
        std::string username_in_file, email, password;
        std::getline(ss, username_in_file, ',');
        std::getline(ss, email, ',');
        std::getline(ss, password, ',');

        if (username_in_file != username) {
            temp_accounts_out << line << std::endl;
        }
    }

    accounts_in.close();
    temp_accounts_out.close();
    std::remove("accounts.csv");
    std::rename("temp_accounts.csv", "accounts.csv");

    std::ifstream movies_in("movies.csv");
    std::ofstream temp_movies_out("temp_movies.csv");

    while (std::getline(movies_in, line)) {
        std::stringstream ss(line);
        std::string movie_username, title, genre, year_of_release, rating;
        std::getline(ss, movie_username, ',');
        std::getline(ss, title, ',');
        std::getline(ss, genre, ',');
        std::getline(ss, year_of_release, ',');
        std::getline(ss, rating, ',');

        if (movie_username != username) {
            temp_movies_out << line << std::endl;
        }
    }

    movies_in.close();
    temp_movies_out.close();
    std::remove("movies.csv");
    std::rename("temp_movies.csv", "movies.csv");


    std::ifstream watchlist_in("watchlist.csv");
    std::ofstream temp_watchlist_out("temp_watchlist.csv");

    while (std::getline(watchlist_in, line)) {
        std::stringstream ss(line);
        std::string watchlist_username, title, genre, year_of_release, rating;
        std::getline(ss, watchlist_username, ',');
        std::getline(ss, title, ',');
        std::getline(ss, genre, ',');
        std::getline(ss, year_of_release, ',');
        std::getline(ss, rating, ',');

        if (watchlist_username != username) {
            temp_watchlist_out << line << std::endl;
        }
    }

    watchlist_in.close();
    temp_watchlist_out.close();
    std::remove("watchlist.csv");
    std::rename("temp_watchlist.csv", "watchlist.csv");

    std::ifstream folders_in("folders.csv");
    std::ofstream temp_folders_out("temp_folders.csv");

    while (std::getline(folders_in, line)) {
        std::stringstream ss(line);
        std::string folder_username, folder_name, title, genre, year_of_release, rating;
        std::getline(ss, folder_username, ',');
        std::getline(ss, folder_name, ',');
        std::getline(ss, title, ',');
        std::getline(ss, genre, ',');
        std::getline(ss, year_of_release, ',');
        std::getline(ss, rating, ',');

        if (folder_username != username) {
            temp_folders_out << line << std::endl;
        }
    }

    folders_in.close();
    temp_folders_out.close();
    std::remove("folders.csv");
    std::rename("temp_folders.csv", "folders.csv");
    std::cout << "Account and associated movies deleted successfully." << std::endl;
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

}
