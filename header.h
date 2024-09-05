#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <regex>
#include <set>
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
    void delete_account(const std::string& username);
    bool is_username_available(const std::string& username);
    friend std::ostream& operator<<(std::ostream& os, const User &user);

};

void create_account();
void uprint();
void menu();
void login();
void setPassword();
void update_password();
void delete_account();
class Movie
{
protected:
    std::string title;
    std::string genre;
    unsigned int year_of_release;
    unsigned int rating;

public:
    Movie(std::string, std::string,unsigned int);
    void add_movie(const std::string &);
    void view_movie(const std::string& username);
    void mprint(const std::string&);
    void add_to_watchlist(const std::string& username, const std::string& title, const std::string&,int );
    void view_watchlist(const std::string& username);
    void update_rating(const std::string& title, unsigned int new_rating);
    void create_folder(const std::string& username);
    void folder(const std::string& username);
    void movie_reccomendation(const std::string& username);
    void view_folder(const std::string& username);
    void update_folder(const std::string& username);
    void delete_movie(const std::string& username);
    void delete_folder(const std::string& username);
};
void add_movie();
void mprint();
void view_folder();
void delete_movie();
void delete_folder();
int is_in_watchlist(std::string moviefolder_title,std::string moviefolder_genre);
int is_in_movies(std::string moviefolder_title,std::string moviefolder_genre);
