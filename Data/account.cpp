#include "account.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#include <ctime>
#include <string>
// CLASS
Person *CG;
Person::Person()
{
    std::cout << "\n\tBuilding a PERSON.";
}
Person::~Person()
{
    delete CG;
    std::cout << "\n\tDestroying a Person.";
}
// Globals

// Creating random account number

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

//-------------------------------------------------------------------------------------------------------------------//

// Building person
void CreatePerson()
{
    CG = new Person();
}

// Destroy person
void DestroyPerson()
{
    std::cout << "\n\tDestroying a Person.";
    delete CG;
    Sleep(2000);
}

//-------------------------------------------------------------------------------------------------------------------//

// Saving values to a text file
void SavePerson()
{
    try
    {
        std::ofstream datafile;
        datafile.open("user_accounts.txt", std::ios::out);

        datafile << CG->GetFirstName() << "\n";
        datafile << CG->GetLastName() << "\n";
        datafile << CG->GetCountrytBirth() << "\n";
        datafile << CG->GetPersonalId() << "\n";
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

// File loading
void LoadPerson()
{
    try
    {
        std::string TEMP;
        std::ifstream datafile;
        datafile.open("user_accounts.txt", std::ios::in);
        getline(datafile, TEMP);
        CG->SetFirstName(TEMP);

        getline(datafile, TEMP);
        CG->SetLastName(TEMP);

        getline(datafile, TEMP);
        CG->SetCountryBirth(TEMP);

        getline(datafile, TEMP);
        CG->SetPersonalId(TEMP);

        getline(datafile, TEMP);
        CG->SetAccountNumber(TEMP);

        datafile.close();
        DisplayAccount();
        std::cout << "\n\tSuccess! Data was loaded\n";
        Sleep(1000);
    }
    catch (std::string exc)
    {
        std::cout << "File empty" << std::endl;
    }
}

//-------------------------------------------------------------------------------------------------------------------//

// Displaying the account number after creating a new user
void DisplayAccount()
{
    system("cls");
    std::cout << "\n\tThis is your account number, remember it you will need it to log in: " << CG->GetAccountNumber() << "\n";
    Sleep(3000);
    system("cls");
}

//-------------------------------------------------------------------------------------------------------------------//

// Creating a new user account
void NewAccount()
{
    std::string TEMP;
    system("cls");
    std::cout << "\n\tEnter your first name: ";
    std::cin.ignore();
    getline(std::cin, TEMP);
    CG->SetFirstName(TEMP);

    std::cout << "\n\tEnter your last name: ";
    getline(std::cin, TEMP);
    CG->SetLastName(TEMP);

    std::cout << "\n\tEnter your birth country: ";
    getline(std::cin, TEMP);
    CG->SetCountryBirth(TEMP);

    std::cout << "\n\tEnter your personal id: ";
    getline(std::cin, TEMP);
    CG->SetPersonalId(TEMP);
    SavePerson();
    LoadPerson();
}

//-------------------------------------------------------------------------------------------------------------------//

// Login section, checking that the account number is correct and first name
void LoginPerson()
{
    while (true)
    {
        std::string TEMP;
        std::cout << "\n\tPlease enter your first name: ";
        std::cin.ignore();
        getline(std::cin, TEMP);
        std::cout << "\n\tPlease enter your password( account number): ";
        getline(std::cin, TEMP);
        if (TEMP == CG->GetAccountNumber() || TEMP == CG->GetFirstName())
        {
            std::cout << "\n\tSuccess! you have successfully logged into your account";
            Sleep(4000);
            AccountPanel();
            break;
        }
        else
        {
            std::cout << "\n\tTry again your password or name doesn't match";
            Sleep(2000);
            system("cls");
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------//

// User interface
void AccountPanel()
{
    system("cls");
    std::cout << "\n\n\t\t\tWelcome " << CG->GetFirstName() << "" << std::endl;
    system("pause");
}