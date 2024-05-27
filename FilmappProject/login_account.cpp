#include"header.h"
std::string User::login_account()
{
    system("cls");
    std::ifstream fin("accounts.csv");
    std::cout<<std::endl<<std::endl;
    std::string welcome_message="Log in to account";
    int spaces=(115-welcome_message.size())/2;
    std::cout<<std::string(spaces,' ')<<welcome_message;
    std::string user_username,user_password;
    std::cout<<std::endl<<"Enter the following details:"<<std::endl;
    std::cout<<"Enter the username or email:";
    std::cin>>user_username;
    std::cout<<"Enter the password:";
    std::cin>>user_password;

    std::vector<User> users;
    std::string line, username, email, password;
    while (std::getline(fin, line))
    {
        std::istringstream iss(line);
        std::getline(iss, username, ',');
        std::getline(iss, email, ',');
        std::getline(iss, password, ',');
        users.emplace_back(username, email, password);
    }
    bool logged_in = false, found_password = false, found_user = false;
    for (const auto& user : users)
    {
        if (user.getUsername() == user_username || user.getEmail() == user_username)
        {
            found_user = true;
            if (user.getPassword() == user_password)
            {
                return user.getUsername();
                found_password = true;
                system("cls");
                logged_in = true;
            }
        }
    }
    if (!logged_in)
    {
        if (found_user == true)
        {
            std::cout << "Invalid password. Do you want to reset your password? [1-2]: "<<std::endl;
            int num1;
            std::cout<<"[1] Yes"<<std::endl<<"[2] No"<<std::endl;
            std::cin>>num1;
            if (num1 == 1)
            {
                for (auto& user : users)
                {
                    if (user.getUsername() == username)
                    {

                        User new_user{" "," "," "};
                        forgot_my_password(user);
                        new_user.login_account();
                        break;
                    }
                }
            }
        }
        else
        {
            std::cout<<"Account not found! Do you want to create an account?"<<std::endl;
            int num2;
            std::cout<<"[1] Yes"<<std::endl<<"[2] No"<<std::endl;
            std::cin>>num2;
            if(num2 == 1)
            {
                User new_user{" "," "," "};
                new_user.create_account();
            }
        }
    }
}

void User::forgot_my_password(User& user)
{
    std::string new_password;
    std::cout << "Enter your new password: ";
    std::cin >> new_password;
    user.setPassword(new_password);
    user.update_password(new_password);
    std::cout << "Password updated successfully!" << std::endl;
}

void User::update_password(const std::string& new_password)
{
    std::ifstream infile("accounts.csv");
    std::stringstream buffer;
    buffer << infile.rdbuf();
    std::string file_contents = buffer.str();
    infile.close();

    std::ofstream outfile("accounts.csv");
    std::istringstream stream(file_contents);
    std::string line;
    bool found = false;
    while (std::getline(stream, line)) {
        std::istringstream linestream(line);
        std::string file_username, file_email, file_password;
        std::getline(linestream, file_username, ',');
        std::getline(linestream, file_email, ',');
        std::getline(linestream, file_password, ',');

        if (file_username == username && file_email == email) {
            outfile << username << "," << email << "," << password << "\n";
            found = true;
        } else {
            outfile << line << "\n";
        }
    }

    if (!found) {
        outfile << username << "," << email << "," << password << "\n";
    }

    outfile.close();
}
