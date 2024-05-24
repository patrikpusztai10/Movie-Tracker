#include"header.h"
User::User(std::string username,std::string email,std::string password)
{

    this->username=username;
    this->email=email;
    this->password=password;

}

void User::create_account()
{
    std::cout<<std::endl<<std::endl;
    std::string welcome_message="Create account";
    int spaces=(115-welcome_message.size())/2;
    std::string username,email,password;
    std::cout<<std::endl<<"Enter the following details:"<<std::endl;
    std::cout<<"Enter the username:";
    std::cin>>username;
    std::cout<<"Enter the email:";
    std::cin>>email;
    std::cout<<"Enter the pawssord:";
    std::cin>>password;
    std::shared_ptr<User> user = std::make_shared<User>(username, email, password);
    users.push_back(user);
    user->uprint();
}
void User::uprint()
{
    std::ofstream fout("accounts.csv", std::ios::app);
    if (fout.is_open())
    {
        fout << username << ',' << email << ',' << password << std::endl;
    }
    else
    {
        std::cerr << "Unable to open file" << std::endl;
    }
}
