#include"header.h"
void User::menu(const std::string& username)
{
    system("cls");
    std::cout << "Login successful! Welcome " << username << "!" << std::endl;
    Movie movie{" "," ",0};
    User user{" "," "," "};
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"1.Add new movie"<<std::endl;
    std::cout<<"2.Watchlist"<<std::endl;
    std::cout<<"3.Folders"<<std::endl;
    std::cout<<"4.View your movies"<<std::endl;
    std::cout<<"5.Monthly reccomendation"<<std::endl;
    std::cout<<"6.Delete account"<<std::endl;
    std::cout<<"7.Delete movie"<<std::endl;
    std::cout<<"8.Exit"<<std::endl;
    std::cout<<"Enter choice[1-8]:";
    int num3;
    std::cin>>num3;
    if(num3==1)
        movie.add_movie(username);
    if(num3==2)
        movie.view_watchlist(username);
    if(num3==3)
        movie.folder(username);
    if(num3==4)
        movie.view_movie(username);
    if(num3==5)
        movie.movie_reccomendation(username);
    if(num3==6)
        user.delete_account(username);
    if(num3==7)
        movie.delete_movie(username);
    if(num3==8)
    {
        return ;
    }

}
