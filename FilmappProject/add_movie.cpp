#include "header.h"
void Movie::add_movie(const std::string& username)
{
    system("cls");
    Movie movie{" "," ",0,0};
    std::string message = "Add new movie";
    int spaces = (115 - message.size()) / 2;
    std::cout << std::string(spaces, ' ') << message << std::endl;

    std::string title, genre;
    std::string year_of_release;
    unsigned int rating;
    char watched;

    std::cout << "Enter the following details:" << std::endl;
    std::cout << "Enter the title of the movie: ";
    std::getline(std::cin >> std::ws, title);
    std::cout << "Enter the genre: ";
    std::getline(std::cin >> std::ws, genre);
    std::cout << "Enter the year of release: ";
    std::cin >> year_of_release;
    if(is_in_watchlist(title,genre,year_of_release)==1||is_in_movies(title,genre,year_of_release)==1)
    {
        std::cout<<"Movie is already added!Choose a new one!";
        std::cout<<"Do you want to proceed?"<<std::endl;
        std::cout<<"[1]Yes"<<std::endl<<"[2]No"<<std::endl;
        int num5;
        std::cout<<"Choose[1-2]:";
        std::cin>>num5;
        if(num5==1)
        movie.add_movie(username);
        else
        {

        User user{" "," "," "};
        user.menu(username);
        }
    }
    std::cout<<"Have you watched this movie"<<std::endl;
    std::cout<<"[1]Yes"<<std::endl<<"[2]No"<<std::endl;
    std::cout<<"Choose[1-2]:";
    int choice2;
    std::cin>>choice2;

    if (choice2==1)
    {
        do
        {
            std::cout << "Enter the rating (1-5): ";
            std::cin >> rating;
        }
        while (rating < 1 || rating > 5);

        // Save movie details to the file
        std::ofstream fout("movies.csv", std::ios::app);
        if (fout.is_open())
        {
            fout << username << ',' << title << ',' << genre << ',' << year_of_release << ',' << rating << std::endl;
            fout.close();
        }
    }
    else
    {
    std::ofstream fout("watchlist.csv", std::ios::app);
    if (fout.is_open())
    {
        fout << username << ',' << title << ','<<genre<<','<<year_of_release<<std::endl;
        fout.close();
    }
    }
    std::cout<<"Do you want to add other movies?"<<std::endl;
    std::cout<<"[1]Yes"<<std::endl<<"[2]No"<<std::endl;
    std::cout<<"Choose[1-2]:";
    int choice;
    std::cin>>choice;
    if (choice==1)
    {
        Movie movie{"","",0,0};
        movie.add_movie(username);
    }
    else
    {
        User user{" "," "," "};
        user.menu(username);
    }
}



Movie::Movie(std::string title, std::string genre, unsigned int year_of_release,unsigned int rating )
{
    this->title=title;
    this->genre=genre;
    this->year_of_release=year_of_release;
    this->rating=rating;
}
