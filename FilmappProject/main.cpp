#include "header.h"
int main()
{   User user{" "," "," "};
    std::cout<<std::endl<<std::endl;
    std::string welcome_message="Welcome to Filmboxd";
    int spaces=(115-welcome_message.size())/2;
    std::cout<<std::string(spaces,' ')<<welcome_message;
    std::cout<<std::endl<<std::endl;
    std::cout<<"[1]Login"<<std::endl<<"[2]Create account"<<std::endl;
    std::cout<<"Choose [1-2]:";
    int num;
    std::cin>>num;
    if(num==2)
       user.create_account();
    return 0;
}
