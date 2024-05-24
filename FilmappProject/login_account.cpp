#include"header.h"
void User::login_account()
{
    std::ifstream fin("accounts.csv");
    std::cout<<std::endl<<std::endl;
    std::string welcome_message="Create account";
    int spaces=(115-welcome_message.size())/2;
    std::string user_username,user_password;
    std::cout<<std::endl<<"Enter the following details:"<<std::endl;
    std::cout<<"Enter the username or email:";
    std::cin>>user_username;
    std::cout<<"Enter the password:";
    std::cin>>user_password;
    std::string line, username, email, password;
    while (std::getline(fin, line)) {
        std::istringstream iss(line);
        std::getline(iss, username, ',');
        std::getline(iss, email, ',');
        std::getline(iss, password, ',');
        users.push_back(std::make_shared<User>(username, email, password));
    }
    bool logged_in = false;
    for (const auto& user : users) {
        if ((user->getUsername() == user_username||user->getEmail() == user_username)&& user->getPassword() == user_password) {
            std::cout << "Login successful! Welcome " << username << "!" << std::endl;
            logged_in = true;
            break;
        }
    }

    if (!logged_in) {
        std::cout << "Invalid username or password. Please try again." << std::endl;
    }
}

