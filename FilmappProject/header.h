#pragma once
#include <iostream>
#include <fstream>
class User{
protected:
std::string username;
std::string email;
std::string password;
int numberofusers;
public:
User(std::string,std::string,std::string);
void create_account();
void uprint();
void addUser();
};
void create_account();
void uprint();
class Movie{
protected:
std::string title;
std::string genre;
int rating;
};

