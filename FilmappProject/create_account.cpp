#include"header.h"
User::User(std::string username,std::string email,std::string password)
{

    this->username=username;
    this->email=email;
    this->password=password;

}
bool User::is_valid_email(const std::string& email) {
    const std::regex pattern(R"((\w+)(\.|\+)?(\w*)@(\w+)\.(\w+))");
    return std::regex_match(email, pattern);
}
bool User::is_username_available(const std::string& username) {
    std::ifstream accounts_in("accounts.csv");
    std::string line;

    if (!accounts_in.is_open()) {
        std::cerr << "Error opening accounts file." << std::endl;
        return false;
    }

    while (std::getline(accounts_in, line)) {
        std::stringstream ss(line);
        std::string username_in_file;
        std::getline(ss, username_in_file, ',');
        if (username_in_file == username) {
            return false;
        }
    }

    return true;
}
void User::create_account()
{
    system("cls");
    std::cout << std::endl << std::endl;
    std::string welcome_message = "Create account";
    int spaces = (115 - welcome_message.size()) / 2;
    std::cout << std::string(spaces, ' ') << welcome_message;
    std::string username, email, password;
    std::cout << std::endl << "Enter the following details:" << std::endl;
    do {
        std::cout << "Enter the username: ";
        std::getline(std::cin >> std::ws, username);
        if (!is_username_available(username)) {
            std::cout << "Username is unavailable. Please enter a different username." << std::endl;
        }
    } while(!is_username_available(username));
    do {
        std::cout << "Enter the email: ";
        std::cin >> email;
        if (!is_valid_email(email)) {
            std::cout << "Invalid email format. Please try again." << std::endl;
        }
    } while (!is_valid_email(email));
    std::cout << "Enter the password: ";
    std::cin >> password;
    User newUser(username, email, password); // Creating User object directly
    newUser.uprint();
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
