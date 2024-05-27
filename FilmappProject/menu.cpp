#include"header.h"
void User::menu(const std::string& username)
{
    system("cls");
    std::cout << "Login successful! Welcome " << username << "!" << std::endl;
    Movie movie{" "," ",0,0};
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"1.Add new movie"<<std::endl;
    std::cout<<"2.Watchlist"<<std::endl;
    std::cout<<"3.Create new folder"<<std::endl;
    std::cout<<"4.View your movies"<<std::endl;
    std::cout<<"5.Monthly reccomendation"<<std::endl;
    std::cout<<"6.Exit"<<std::endl;
    std::cout<<"Enter choice[1-6]:";
    int num3;
    std::cin>>num3;
    if(num3==1)
        movie.add_movie(username);
    if(num3==4)
        movie.view_movie(username);

}
