#include"header.h"
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

    // Remove movies added by the user from movies.csv
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

    while (std::getline(movies_in, line)) {
        std::stringstream ss(line);
        std::string movie_username, title, genre, year_of_release, rating;
        std::getline(ss, movie_username, ',');
        std::getline(ss, title, ',');
        std::getline(ss, genre, ',');
        std::getline(ss, year_of_release, ',');
        std::getline(ss, rating, ',');

        if (movie_username != username) {
            temp_watchlist_out << line << std::endl;
        }
    }

    watchlist_in.close();
    temp_watchlist_out.close();
    std::remove("watchlist.csv");
    std::rename("temp_watchlist.csv", "watchlist.csv");

    std::ifstream folders_in("folders.csv");
    std::ofstream temp_folders_out("temp_folders.csv");

    while (std::getline(movies_in, line)) {
        std::stringstream ss(line);
        std::string movie_username, folder_name,title, genre, year_of_release, rating;
        std::getline(ss, movie_username, ',');
        std::getline(ss, folder_name, ',');
        std::getline(ss, title, ',');
        std::getline(ss, genre, ',');
        std::getline(ss, year_of_release, ',');
        std::getline(ss, rating, ',');

        if (movie_username != username) {
            temp_folders_out << line << std::endl;
        }
    }

    folders_in.close();
    temp_folders_out.close();
    std::remove("folders.csv");
    std::rename("temp_folders.csv", "folders.csv");
    std::cout << "Account and associated movies deleted successfully." << std::endl;
}
