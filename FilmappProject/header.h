#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <regex>
#include <cstring>
#include <cstdio>
class User
{
protected:
    std::string username;
    std::string email;
    std::string password;

public:
    User(std::string,std::string,std::string);
    void create_account();
    void uprint();
    std::string login_account();
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
    bool is_valid_email(const std::string& email);
    void forgot_my_password( User & user);
    void setPassword(const std::string& new_password) { password = new_password; }
    void update_password(const std::string& new_password);
    void menu(const std::string& username);
    void clear_users();


};

void create_account();
void uprint();
void menu();
void login();
void setPassword();
void update_password();
class Movie
{
protected:
    std::string title;
    std::string genre;
    unsigned int year_of_release;
    unsigned int rating;

public:
    Movie(std::string, std::string,unsigned int,unsigned int);
    void add_movie(const std::string &);
    void view_movie(const std::string& username);
    void mprint(const std::string&);

};
void add_movie();
void mprint();
