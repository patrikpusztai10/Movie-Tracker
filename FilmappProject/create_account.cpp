#include"header.h"
void create_account()
{
std::cout<<std::endl<<std::endl;
    std::string welcome_message="Create account";
    int spaces=(115-welcome_message.size())/2;
std::ofstream fout;
fout.open("accounts.csv");
std::cout<<std::endl<<"Enter the following details:"<<std::endl;
User user;
std::cout<<"Enter the username:";
std::cin>>user.username;
std::cout<<"Enter the email:";
std::cin>>user.email;
std::cout<<"Enter the pawssord:";
std::cin>>user.password;
fout<<user.username<<","
    <<user.email<<","
    <<user.password
    <<"\n";
}
