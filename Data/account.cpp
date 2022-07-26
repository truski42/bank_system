#include "account.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#include <ctime>
// Globals

std::string first_name;
std::string last_name;
std::string personal_id;
std::string country_of_birth;
std::string account;
std::string gen_random(const int len)
{
    // ofstream user_account("user_accounts.txt", ofstream::app);
    static const char alphanum[] = "0123456789";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i)
    {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return tmp_s;
}
void SavePerson()
{
    try
    {
        std::ofstream datafile;
        datafile.open("user_accounts.txt", std::ios::out);

        datafile << first_name << "\n";
        datafile << last_name << "\n";
        datafile << country_of_birth << "\n";
        datafile << personal_id << "\n";
        datafile << gen_random(9) << "\n";
        datafile.close();
        std::cout << "\n\tSuccess! Data was saved to file";
    }
    catch (std::string exc)
    {
        std::cout << exc << std::endl;
    }
}
//-------------------------------------------------------------------------------------------------------------------//
void LoadPerson()
{
    try
    {
        std::ifstream datafile;
        datafile.open("user_accounts.txt", std::ios::in);

        getline(datafile, first_name);
        getline(datafile, last_name);
        getline(datafile, country_of_birth);
        getline(datafile, personal_id);
        getline(datafile, account);

        datafile.close();
        std::cout << "\n\tSuccess! Data was loaded" << "\n";
        Sleep(1000);
    }
    catch (std::string exc)
    {
        std::cout << "File empty" << std::endl;
    }
}
//-------------------------------------------------------------------------------------------------------------------//
void DisplayPerson()
{
    system("cls");
    std::cout << account << "\n";
}
//-------------------------------------------------------------------------------------------------------------------//
void EditPerson()
{
    system("cls");
    std::cout << "\n\tEnter your first name: ";
    std::cin.ignore();
    getline(std::cin, first_name);

    std::cout << "\n\tEnter your last name: ";
    getline(std::cin, last_name);

    std::cout << "\n\tEnter your birth country: ";
    getline(std::cin, country_of_birth);

    std::cout << "\n\tEnter your personal id: ";
    getline(std::cin, personal_id);
    SavePerson();
}