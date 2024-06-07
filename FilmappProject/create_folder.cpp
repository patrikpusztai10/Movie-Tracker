#include "header.h"
void Movie::folder(const std::string& username)
{
    system("cls");
    Movie movie{"","",0};
    std::cout<<std::endl<<std::endl;
    std::cout<<"[1]Create new folder"<<std::endl;
    std::cout<<"[2]Update a folder"<<std::endl;
    std::cout<<"[3]View folder(s)"<<std::endl;
    std::cout<<"[4]Delete folder"<<std::endl;
    std::cout<<"[5]Back to menu"<<std::endl;
    std::cout<<"Choose[1-5]:";
    int num5;
    std::cin>>num5;
    if(num5==1)
    {
        movie.create_folder(username);
    }
    if(num5==2)
    {
        movie.update_folder(username);
    }
    if(num5==3)
    {
        movie.view_folder(username);
    }
    if(num5==4)
    {
        movie.delete_folder(username);
    }
    if(num5==5)
    {
        User user{" "," "," "};
        user.menu(username);
    }

}
int is_in_watchlist(std::string moviefolder_title,std::string moviefolder_genre)
{
    std::ifstream fin("watchlist.csv");
    std::string line;
    if (fin.is_open())
    {
        while (std::getline(fin, line))
        {
            std::stringstream ss(line);
            std::string movie_username, title, genre;
            std::getline(ss, movie_username, ',');
            std::getline(ss, title, ',');
            std::getline(ss, genre, ',');
            if (moviefolder_title==title&&moviefolder_genre==genre)
            {
                return 1;

            }
        }
        fin.close();
    }
    return 0;
}
int is_in_movies(std::string moviefolder_title,std::string moviefolder_genre)
{
    std::ifstream fin("movies.csv");
    std::string line;
    if (fin.is_open())
    {
        while (std::getline(fin, line))
        {
            std::stringstream ss(line);
            std::string movie_username, title, genre;
            std::getline(ss, movie_username, ',');
            std::getline(ss, title, ',');
            std::getline(ss, genre, ',');
            if (moviefolder_title==title&&moviefolder_genre==genre)
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
        if(is_in_watchlist(movie_name,movie_genre)==1||is_in_movies(movie_name,movie_genre)==1)
            fout<<username<<','<<folder_name<<','<<movie_name<<','<<movie_genre<<std::endl;
        else
        {std::cout<<"You need to add the movie first!"<<std::endl;
         std::cout<<"Do you want to proceed?"<<std::endl;
         std::cout<<"[1]Yes"<<std::endl<<"[2]No"<<std::endl;
         int num5;
         std::cin>>num5;
         if(num5==1)
         {Movie movie{"","",0};
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
void Movie::view_folder(const std::string& username)
{
    system("cls");
    bool found = false;
    std::ifstream fin("folders.csv");
    std::string line;
    std::set<std::string> displayed_folders;
    std::cout << "Folders:" << std::endl;
    std::cout << "---------------------------" << std::endl;

    while (std::getline(fin, line))
    {
        std::stringstream ss(line);
        std::string movie_username, folder_name, title, genre;
        std::getline(ss, movie_username, ',');
        std::getline(ss, folder_name, ',');
        std::getline(ss, title, ',');
        std::getline(ss, genre, ',');

        if (movie_username == username)
        {
            if (displayed_folders.find(folder_name) == displayed_folders.end())
            {

                displayed_folders.insert(folder_name);
                std::cout << folder_name << std::endl;
                std::cout << "---------------------------" << std::endl;
            }
            std::cout << "Title: " << title << std::endl;
            std::cout << "Genre: " << genre << std::endl;
            std::cout << std::endl;
        }
    }
    std::cout<<"Do you want to go back to the menu?"<<std::endl;
    std::cout<<"[1]Yes"<<std::endl<<"[2]No"<<std::endl;
    int choose5;
    std::cout<<"Choose [1-2]:";
    std::cin>>choose5;
    if(choose5==1)
    {
        Movie movie{" "," ",0};
        movie.folder(username);
    }
    else
    {
        return ;
    }

    fin.close();
}
void Movie::delete_folder(const std::string& username)
{
    std::ifstream fin("folders.csv");
    std::ofstream temp("temp.csv");
    std::string line;
    bool folder_found = false;
    std::cout<<"Enter the name of the folder you want to delete:";
    std::string folder_to_delete;
    std::cin>>folder_to_delete;

    while (std::getline(fin, line))
    {
        std::stringstream ss(line);
        std::string movie_username, folder_name, title, genre, rating;
        std::getline(ss, movie_username, ',');
        std::getline(ss, folder_name, ',');
        std::getline(ss, title, ',');
        std::getline(ss, genre, ',');

        if (movie_username == username && folder_name == folder_to_delete)
        {
            folder_found = true;
        }
        else
        {
            temp << line << std::endl;
        }
    }

    fin.close();
    temp.close();

    if (folder_found)
    {
        std::remove("folders.csv");
        std::rename("temp.csv", "folders.csv");
        std::cout << "Folder '" << folder_to_delete << "' has been deleted." << std::endl;
    }
    else
    {
        std::remove("temp.csv");
        std::cout << "Folder '" << folder_to_delete << "' not found." << std::endl;
    }
    std::cout<<"Do you want to go back to the menu?"<<std::endl;
    std::cout<<"[1]Yes"<<std::endl<<"[2]No"<<std::endl;
    int choose6;
    std::cout<<"Choose [1-2]:";
    std::cin>>choose6;
    if(choose6==1)
    {
        Movie movie{" "," ",0};
        movie.folder(username);
    }
    else
    {
        return ;
    }
}
void Movie::update_folder(const std::string& username)
{
    system("cls");
    std::cout<<std::endl<<std::endl;
    std::cout<<"[1]Add new movie to old folder"<<std::endl;
    std::cout<<"[2]Delete a movie from a folder"<<std::endl;
    int choice10,ok=0;
    std::cout<<"Enter choice[1-2]:";
    std::cin>>choice10;
    if (choice10 == 1)
    {
        std::cout << "Enter folder name: ";
        std::string tba_folder_name;
        std::cin >> tba_folder_name;

        std::ifstream folders_in("folders.csv");
        std::string line;
        std::vector<std::string> lines;
        bool folder_found = false;
        std::string movie_username, folder_name, title, genre;
        while (std::getline(folders_in, line))
        {
            lines.push_back(line);
            std::stringstream ss(line);

            std::getline(ss, movie_username, ',');
            std::getline(ss, folder_name, ',');
            std::getline(ss, title, ',');
            std::getline(ss, genre, ',');

            if (tba_folder_name == folder_name&&username==movie_username)
            {
                folder_found = true;
            }
        }
        folders_in.close();

        if (folder_found)
        {
            std::string new_title, new_genre;
            std::cout << "Enter the title of the movie you want to add: ";
            std::cin >> new_title;
            std::cout << "Enter the genre of the movie you want to add: ";
            std::cin >> new_genre;

            if (is_in_watchlist(new_title, new_genre) || is_in_movies(new_title, new_genre))
            {
                // Find the position to insert the new movie
                auto it = std::find_if(lines.rbegin(), lines.rend(), [&](const std::string& line) {
                    std::stringstream ss(line);
                    std::string movie_username, folder_name, title, genre;
                    std::getline(ss, movie_username, ',');
                    std::getline(ss, folder_name, ',');
                    return folder_name == tba_folder_name;
                });

                if (it != lines.rend())
                {
                    lines.insert(it.base(), username + ',' + tba_folder_name + ',' + new_title + ',' + new_genre);
                }
                else
                {
                    lines.push_back(username + ',' + tba_folder_name + ',' + new_title + ',' + new_genre);
                }

                // Write back to the file
                std::ofstream folders_out("folders.csv");
                for (const auto& line : lines)
                {
                    folders_out << line << std::endl;
                }
                folders_out.close();

                ok = 1;
            }
            else
            {
                std::cout << "You need to add the movie first!" << std::endl;
                std::cout << "Do you want to proceed?" << std::endl;
                std::cout << "[1] Yes" << std::endl << "[2] No" << std::endl;
                int num5;
                std::cin >> num5;
                if (num5 == 1)
                {
                    Movie movie{" "," ",0};
                    movie.add_movie(username);
                }
                else
                {
                    Movie movie{" "," ",0};
                    movie.folder(username);
                }
            }
        }
        else
        {
            std::cout << "Folder not found!" << std::endl;
        }
    }
    if(choice10==2)
    {
     std::cout << "Enter folder name: ";
    std::string folder_name;
    std::cin >> folder_name;
    std::cout << "Enter the title of the movie you want to delete: ";
    std::string movie_title;
    std::cin >> movie_title;

    std::ifstream folders_in("folders.csv");
    std::string line;
    std::vector<std::string> lines;
    bool movie_found = false;

    while (std::getline(folders_in, line))
    {
        std::stringstream ss(line);
        std::string movie_username, folder_name_csv, title, genre;
        std::getline(ss, movie_username, ',');
        std::getline(ss, folder_name_csv, ',');
        std::getline(ss, title, ',');
        std::getline(ss, genre, ',');

        if (folder_name_csv == folder_name && title == movie_title&&username==movie_username)
        {
            movie_found = true;
            continue; // Skip the line with the movie to be deleted
        }
        lines.push_back(line);
    }
    folders_in.close();

    if (movie_found)
    {
        std::ofstream folders_out("folders.csv");
        for (const auto& line : lines)
        {
            folders_out << line << std::endl;
        }
        folders_out.close();
        std::cout << "Movie deleted successfully." << std::endl;
    }
    else
    {
        std::cout << "Movie not found in the specified folder." << std::endl;
    }
    std::cout<<"Do you want to go back to the menu?"<<std::endl;
    std::cout<<"[1]Yes"<<std::endl<<"[2]No"<<std::endl;
    int choose6;
    std::cout<<"Choose [1-2]:";
    std::cin>>choose6;
    if(choose6==1)
    {
        Movie movie{" "," ",0};
        movie.folder(username);
    }
    else
    {
        return ;
    }

  }

}
