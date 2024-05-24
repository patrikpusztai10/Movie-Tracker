#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <sstream>
class User
{
protected:
    std::string username;
    std::string email;
    std::string password;
    std::vector<std::shared_ptr<User>> users;
public:
    User(std::string,std::string,std::string);
    void create_account();
    void uprint();
    void login_account();
    const std::string& getUsername() const
    {
        return username;
    }
    const std::string& getEmail() const
    {
        return email;
    }
    const std::string& getPassword() const
    {
        return password;
    }
};
void create_account();
void uprint();
class Movie
{
protected:
    std::string title;
    std::string genre;
    int rating;
};

