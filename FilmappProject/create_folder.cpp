#include "header.h"
void Movie::folder(const std::string& username)
{
    system("cls");
    Movie movie{"","",0,0};
    std::cout<<"[1]Create new folder"<<std::endl;
    std::cout<<"[2]Add to folder"<<std::endl;
    std::cout<<"[3]View folder(s)"<<std::endl;
    std::cout<<"[4]Delete folder"<<std::endl;
    std::cout<<"Choose[1-3]:";
    int num5;
    std::cin>>num5;
    if(num5==1)
    {
        movie.create_folder(username);
    }

}
int is_in_watchlist(std::string moviefolder_title,std::string moviefolder_genre,std::string moviefolder_year)
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
            if (moviefolder_title==title&&moviefolder_genre==genre&&moviefolder_year==year_of_release)
            {
                return 1;

            }
        }
        fin.close();
    }
    return 0;
}
int is_in_movies(std::string moviefolder_title,std::string moviefolder_genre,std::string moviefolder_year)
{
    std::ifstream fin("movies.csv");
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
            if (moviefolder_title==title&&moviefolder_genre==genre&&moviefolder_year==year_of_release)
            {
                return 1;

            }
        }
        fin.close();
    }
    return 0;
}

void Movie::create_folder(const std::string& username)
{
    std::cout<<"Enter the name of the folder you want to create:";
    std::string folder_name;
    std::getline(std::cin >> std::ws,folder_name);
    int ok=1;std::string movie_name,movie_genre,movie_year_of_release;
    std::ofstream fout("folders.csv",std::ios::app);
    while(ok==1)
    {
        std::cout<<"Enter the title of the movie:";
        std::getline(std::cin >> std::ws,movie_name);
        std::cout<<"Enter the genre of the movie:";
        std::getline(std::cin >> std::ws,movie_genre);
        std::cout<<"Enter the year of the release of the movie:";
        std::cin>>movie_year_of_release;
        if(is_in_watchlist(movie_name,movie_genre,movie_year_of_release)==1||is_in_movies(movie_name,movie_genre,movie_year_of_release)==1)
            fout<<username<<','<<folder_name<<','<<movie_name<<','<<movie_genre<<','<<movie_year_of_release;
        else
        {std::cout<<"You need the movie first!"<<std::endl;
         std::cout<<"Do you want to proceed?"<<std::endl;
         std::cout<<"[1]Yes"<<std::endl<<"[2]No"<<std::endl;
         int num5;
         std::cin>>num5;
         if(num5==1)
         {Movie movie{"","",0,0};
         movie.add_movie(username);}
         else
         {
            User user{"","",""};
            user.menu(username);
         }
        }
        std::cout<<"Do you want to add another movie?"<<std::endl;
        std::cout<<"[1]Yes"<<std::endl<<"[2]No"<<std::endl;
        int num4;
        std::cout<<"Choose[1-2]:";
        std::cin>>num4;
        if(num4==2)
        {
            ok=0;
            User user{"","",""};
            user.menu(username);

        }

    }

}
