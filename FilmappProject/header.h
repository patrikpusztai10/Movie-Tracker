#pragma once
#include <iostream>
#include <fstream>
struct User{
std::string username;
std::string email;
std::string password;
};
struct Movie{
std::string title;
std::string genre;
int rating;
};
void create_account();
