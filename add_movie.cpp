#include "header.h"
void Movie::add_movie(const std::string& username)
{
    system("cls");
    Movie movie{" "," ",0};
    User user{" "," "," "};
    std::string message = "Add new movie";
    int spaces = (115 - message.size()) / 2;
    std::cout << std::string(spaces, ' ') << message << std::endl;

    std::string title, genre;
    unsigned int rating;
    char watched;

    std::cout << "Enter the following details:" << std::endl;
    std::cout << "Enter the title of the movie: ";
    std::getline(std::cin >> std::ws, title);
    std::cout << "Enter the genre: ";
    std::getline(std::cin >> std::ws, genre);
    if(is_in_movies(title,genre)==1||is_in_watchlist(title,genre)==1)
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
            fout << username << ',' << title << ',' << genre << ',' << rating << std::endl;
            fout.close();
        }
    }
    else
    {
    std::ofstream fout("watchlist.csv", std::ios::app);
    if (fout.is_open())
    {
        fout << username << ',' << title << ','<<genre<<std::endl;
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
        movie.add_movie(username);
    }
    else
    {

        user.menu(username);
    }
}
void Movie::movie_reccomendation(const std::string& username)
{
    system("cls");
    std::cout<<"What genre do you want your movie to be?"<<std::endl;
    std::cout<<"1.Horror"<<std::endl;
    std::cout<<"2.Fantasy/Sci-Fi"<<std::endl;
    std::cout<<"3.Adventure/Thriller"<<std::endl;
    std::cout<<"4.Classic"<<std::endl;
    std::cout<<"5.Romance"<<std::endl;
    int movie_choice1;
    std::cout<<"Choice[1-5]:";
    std::cin>>movie_choice1;
    if(movie_choice1==1)
    {
        std::cout<<"What subgenre do you want your movie to be?"<<std::endl;
        std::cout<<"1.Creature horror"<<std::endl;
        std::cout<<"2.Found footage horror"<<std::endl;
        std::cout<<"3.Paranormal horror"<<std::endl;
        std::cout<<"4.Classic horror movies"<<std::endl;
        int movie_choice2;
        std::cout<<"Choice[1-4]:";
        std::cin>>movie_choice2;
        if(movie_choice2==1)
        {
            std::cout<<"Do you want the creature to be supernatural?"<<std::endl;
            std::cout<<"1.Yes"<<std::endl;std::cout<<"2.No"<<std::endl;
            int movie_choice4;
            std::cout<<"Choice[1-2]:";
            std::cin>>movie_choice4;
            if(movie_choice1==1)
            {
                std::cout<<"Then you should watch 'A Quiet Place'"<<std::endl;
            }
            else
                std::cout<<"Then you should watch 'Jaws'"<<std::endl;

        }
        if(movie_choice2==2)
        {
            std::cout<<"Do you want a more panaromal found footage horror movie?"<<std::endl;
            std::cout<<"1.Yes"<<std::endl;std::cout<<"2.No"<<std::endl;
            int movie_choice4;
            std::cout<<"Choice[1-2]:";
            std::cin>>movie_choice4;
            if(movie_choice4==1)
            {
                std::cout<<"Then you should watch 'Gonjiam:Haunted Asylum'"<<std::endl;
            }
            if(movie_choice4==2)
                std::cout<<"Then you should watch 'Megan is Missing'"<<std::endl;

        }
        if(movie_choice2==3)
        {
            std::cout<<"Do you want your movie to be a newer one?"<<std::endl;
            std::cout<<"1.Yes"<<std::endl;std::cout<<"2.No"<<std::endl;
            int movie_choice5;
            std::cout<<"Choice[1-2]:";
            std::cin>>movie_choice5;
            if(movie_choice1==1)
            {
                std::cout<<"Then you should watch 'The Conjuring'"<<std::endl;
            }
            else
                std::cout<<"Then you should watch 'The Exorcist'"<<std::endl;

        }
        if(movie_choice2==4)
        {
            std::cout<<"Do you want your movie to be more psychological?"<<std::endl;
            std::cout<<"1.Yes"<<std::endl;std::cout<<"2.No"<<std::endl;
            int movie_choice3;
            std::cout<<"Choice[1-2]:";
            std::cin>>movie_choice3;
            if(movie_choice3==1)
            std::cout<<"Then you should watch 'The Shining'!";
            else
            std::cout<<"Then you should watch 'Scream'!";

        }

    }
    if(movie_choice1==2)
    {
    std::cout << "Choose a fantasy subgenre:" << std::endl;
    std::cout << "1. High fantasy" << std::endl;
    std::cout << "2. Urban fantasy" << std::endl;
    std::cout << "3. Fairy tale fantasy" << std::endl;

    std::cout << "Choice [1-3]: ";
    int movie_choice8;
    std::cin >> movie_choice8;

    if (movie_choice8 == 1) {
        std::cout << "Do you want your movie to have mythical creatures?" << std::endl;
        std::cout << "1. Yes" << std::endl;
        std::cout << "2. No" << std::endl;

        int movie_choice2;
        std::cout << "Choice [1-2]: ";
        std::cin >> movie_choice2;

        if (movie_choice2 == 1) {
            std::cout << "Then you should watch 'The Lord of the Rings trilogy'!" << std::endl;
        } else {
            std::cout << "Then you should watch 'Dune'!" << std::endl;
        }
    } else if (movie_choice8 == 2) {
        std::cout << "Do you prefer fantasy stories set in modern cities?" << std::endl;
        std::cout << "1. Yes" << std::endl;
        std::cout << "2. No" << std::endl;

        int movie_choice3;
        std::cout << "Choice [1-2]: ";
        std::cin >> movie_choice3;

        if (movie_choice3 == 1) {
            std::cout << "Then you should watch 'Stardust'!" << std::endl;
        } else {
            std::cout << "Then you should watch 'ET'!" << std::endl;
        }
    } else if (movie_choice8 == 3) {
        std::cout << "Do you want a classic fairy tale with a modern twist?" << std::endl;
        std::cout << "1. Yes" << std::endl;
        std::cout << "2. No" << std::endl;

        int movie_choice4;
        std::cout << "Choice [1-2]: ";
        std::cin >> movie_choice4;

        if (movie_choice4 == 1) {
            std::cout << "Then you should watch 'Enchanted'!" << std::endl;
        } else {
            std::cout << "Then you should watch the 'Harry Potter' series!" << std::endl;
        }
    }

    }
    if(movie_choice1==3)
    {
        std::cout<<"Choose a thriller subgenre:"<<std::endl;
        std::cout<<"1.Paranormal"<<std::endl;
        std::cout<<"2.Crime"<<std::endl;
        std::cout<<"3.Unreliable narrator"<<std::endl;
        int choice9;
        std::cin>>choice9;
        if(choice9==1)
        {
            std::cout<<"Do you want your movie to be more paranormal?"<<std::endl;
            std::cout << "1. Yes" << std::endl;
            std::cout << "2. No" << std::endl;
            std::cout<<"Choose [1-2]:"<<std::endl;
            int choice11;
            if(choice11==1)
                std::cout<<"Then you should watch The Nun"<<std::endl;
            if(choice11==2) std::cout<<"Then you should watch Suspiria"<<std::endl;

        }
        if(choice9==3)
        {
            std::cout<<"Do you want your movie to be more psychological?"<<std::endl;
            std::cout << "1. Yes" << std::endl;
            std::cout << "2. No" << std::endl;
            std::cout<<"Choose [1-2]:"<<std::endl;
            int choice10;
            if(choice10==1)
                std::cout<<"Then you should watch Gone Girl"<<std::endl;
            if(choice10==2) std::cout<<"Then you should watch The Woman Window"<<std::endl;

        }
        if(choice9==2)
        {   std::cout<<"Do you want your movie to be about a serial killer?"<<std::endl;
            std::cout << "1. Yes" << std::endl;
            std::cout << "2. No" << std::endl;
            std::cout<<"Choose [1-2]:"<<std::endl;
            int choice11;
            if(choice11==1)
                std::cout<<"Then you should watch The Silence of the Lambs"<<std::endl;;
            if(choice11==2)std::cout<<"Then you should watch Gothika"<<std::endl;
            else std::cout<<"Invalid choice";

        }

    }
    if(movie_choice1==4)
    {
        int choice3;
    std::cout << "Choose a classic movie genre:" << std::endl;
    std::cout << "1. Classic comedy" << std::endl;
    std::cout << "2. Classic drama" << std::endl;
    std::cout << "3. Classic romance" << std::endl;

    std::cout << "Choice [1-3]: ";
    std::cin >> choice3;

    if (choice3 == 1) {
        std::cout << "Do you prefer more humor or witty dialogue?" << std::endl;
        std::cout << "1. Humor" << std::endl;
        std::cout << "2. Witty dialogue" << std::endl;

        int movie_choice2;
        std::cout << "Choice [1-2]: ";
        std::cin >> movie_choice2;

        if (movie_choice2 == 1) {
            std::cout << "Then you should watch 'Some Like It Hot'!" << std::endl;
        } else {
            std::cout << "Then you should watch 'It Happened One Night'!" << std::endl;
        }
    } else if (choice3 == 2) {
        std::cout << "Do you prefer intense emotional stories or thought-provoking narratives?" << std::endl;
        std::cout << "1. Intense emotional stories" << std::endl;
        std::cout << "2. Thought-provoking narratives" << std::endl;

        int movie_choice3;
        std::cout << "Choice [1-2]: ";
        std::cin >> movie_choice3;

        if (movie_choice3 == 1) {
            std::cout << "Then you should watch 'Casablanca'!" << std::endl;
        } else {
            std::cout << "Then you should watch 'Cleo from 5 to 7'!" << std::endl;
        }
    } else if (choice3 == 3) {
        std::cout << "Do you prefer romantic comedies or more dramatic romances?" << std::endl;
        std::cout << "1. Romantic comedies" << std::endl;
        std::cout << "2. Dramatic romances" << std::endl;

        int movie_choice4;
        std::cout << "Choice [1-2]: ";
        std::cin >> movie_choice4;

        if (movie_choice4 == 1) {
            std::cout << "Then you should watch 'Roman Holiday'!" << std::endl;
        } else {
            std::cout << "Then you should watch 'Gone with the Wind'!" << std::endl;
        }
    }

    }
    if(movie_choice1==5)
    {
    std::cout << "Choose a romantic subgenre:" << std::endl;
    std::cout << "1. Romantic comedy" << std::endl;
    std::cout << "2. Drama" << std::endl;
    std::cout << "3. Romantic fantasy" << std::endl;
    std::cout << "4. Period romance" << std::endl;
    int movie_choice4;
    std::cout << "Choice [1-4]: ";
    std::cin >> movie_choice4;

    if (movie_choice4 == 1) {
        std::cout << "Do you prefer a light-hearted romantic comedy?" << std::endl;
        std::cout << "1. Yes" << std::endl;
        std::cout << "2. No" << std::endl;

        int movie_choice5;
        std::cout << "Choice [1-2]: ";
        std::cin >> movie_choice5;

        if (movie_choice5 == 1) {
            std::cout << "Then you should watch '10 Things I Hate About You'!" << std::endl;
        } else {
            std::cout << "Then you should watch 'Crazy, Stupid, Love'!" << std::endl;
        }
    }
    else if (movie_choice4 == 2) {
        std::cout << "Do you prefer a serious drama?" << std::endl;
        std::cout << "1. Yes" << std::endl;
        std::cout << "2. No" << std::endl;

        int movie_choice6;
        std::cout << "Choice [1-2]: ";
        std::cin >> movie_choice6;

        if (movie_choice6 == 1) {
            std::cout << "Then you should watch 'The Notebook'!" << std::endl;
        } else {
            std::cout << "Then you should watch 'La La Land'!" << std::endl;
        }
    }
    else if (movie_choice4 == 3) {
        std::cout << "Do you want a romance intertwined with fantasy elements?" << std::endl;
        std::cout << "1. Yes" << std::endl;
        std::cout << "2. No" << std::endl;

        int movie_choice8;
        std::cout << "Choice [1-2]: ";
        std::cin >> movie_choice4;

        if (movie_choice8 == 1) {
            std::cout << "Then you should watch 'The Shape of Water'!" << std::endl;
        } else {
            std::cout << "Then you should watch 'Stardust'!" << std::endl;
        }
    } else if (movie_choice4 == 4) {
        std::cout << "Do you prefer a romance set in a historical period?" << std::endl;
        std::cout << "1. Yes" << std::endl;
        std::cout << "2. No" << std::endl;

        int movie_choice9;
        std::cout << "Choice [1-2]: ";
        std::cin >> movie_choice9;

        if (movie_choice9== 1) {
            std::cout << "Then you should watch 'Pride and Prejudice'!" << std::endl;
        } else {
            std::cout << "Then you should watch 'Titanic'!" << std::endl;
        }}
      else {
        std::cout << "Invalid choice." << std::endl;
     }}
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

Movie::Movie(std::string title, std::string genre,unsigned int rating )
{
    this->title=title;
    this->genre=genre;
    this->rating=rating;
}
