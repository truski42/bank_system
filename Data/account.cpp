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
        datafile << CG->GetUserBalance() << "\n";
        datafile.close();
        std::cout << "\n\tSuccess! Data was saved to file";
    }
    catch (std::string exc)
    {
        std::cout << exc << std::endl;
    }
}

//-------------------------------------------------------------------------------------------------------------------//

// Function that saves the account balance after operations on it
void SaveTheSavings()
{
    try
    {
        std::ofstream datafile;
        datafile.open("user_accounts.txt", std::ios::out);

        datafile << CG->GetFirstName() << "\n";
        datafile << CG->GetLastName() << "\n";
        datafile << CG->GetCountrytBirth() << "\n";
        datafile << CG->GetPersonalId() << "\n";
        datafile << CG->GetAccountNumber() << "\n";
        datafile << CG->GetUserBalance() << "\n";
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
        int Balance;
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

        datafile >> Balance;
        CG->SetUserBalance(Balance);

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
    int Balance;
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

    std::cout << "\n\tEnter your first deposit: ";
    std::cin >> Balance;
    if (Balance == 0)
    {
        CG->SetUserBalance(Balance);
    }
    else
    {
        CG->SetUserBalance(Balance);
    }

    SavePerson();
    LoadPerson();
}

//-------------------------------------------------------------------------------------------------------------------//

// Login section, checking that the account number is correct and first name
void LoginPerson()
{
    for (int i = 3; i >= 0; --i)
    {
        system("cls");
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
        else if (i == 0)
        {
            std::cout << "Too many invalid attempts" << std::endl;
            std::cout << "Your account has been blocked" << std::endl;
            exit(0);
        }
        else
        {
            std::cout << "\n\tTry again your password or name doesn't match" << std::endl;
            std::cout << "\n\tLeft attempts: " << i << std::endl;
            Sleep(2000);
            system("cls");
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------//

// User interface
void AccountPanel()
{
    int choice;
    while (true)
    {
        system("cls");
        std::cout << "\n\n\t\tWelcome " << CG->GetFirstName() << "" << std::endl;
        std::cout << "\t1. Check your account balance" << std::endl;
        std::cout << "\t2. Withdraw" << std::endl;
        std::cout << "\t3. Deposit" << std::endl;
        std::cout << "\t4. Exit" << std::endl;
        std::cout << "\tEnter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            CheckBalance();
            break;
        case 2:
            Withdraw();
            break;
        case 3:
            Deposit();
            break;
        case 4:
            exit(0);
        default:
            break;
        }
    }
    system("pause");
}

//-------------------------------------------------------------------------------------------------------------------//

// Checking user balance

void CheckBalance()
{
    std::cout << "\n\tBalance: " << CG->GetUserBalance() << std::endl;
    Sleep(2000);
    system("pause");
}

//-------------------------------------------------------------------------------------------------------------------//

// Funcionality of depositing cash into the account
void Deposit()
{
    int balance = CG->GetUserBalance();
    bool isNotFinished = true;
    int choice;
    int depositAmount;
    system("cls");
    std::cout << "\t\tPlease enter your selection" << std::endl;
    std::cout << "\t1 - $10" << std::endl;
    std::cout << "\t2 - $20" << std::endl;
    std::cout << "\t3 - $40" << std::endl;
    std::cout << "\t4 - $60" << std::endl;
    std::cout << "\t5 - $80" << std::endl;
    std::cout << "\t6 - $100" << std::endl;
    std::cout << "\t7 - Custom Amount" << std::endl;
    std::cout << "\t8 - Back" << std::endl;
    std::cout << "\tEnter your choice: ";
    std::cin >> choice;
    system("cls");
    switch (choice)
    {
    case 1:
        balance = balance + 10;
        CG->SetUserBalance(balance);
        break;
    case 2:
        balance = balance + 20;
        CG->SetUserBalance(balance);
        break;
    case 3:
        balance = balance + 40;
        CG->SetUserBalance(balance);
        isNotFinished = false;
        break;
    case 4:
        balance = balance + 60;
        CG->SetUserBalance(balance);
        isNotFinished = false;
        break;
    case 5:
        balance = balance + 80;
        CG->SetUserBalance(balance);
        isNotFinished = false;
        break;
    case 6:
        balance = balance + 100;
        CG->SetUserBalance(balance);
        isNotFinished = false;
        break;
    case 7:
        std::cout << "\tEnter amount to Deposit: ";
        std::cin >> depositAmount;
        balance = balance + depositAmount;
        CG->SetUserBalance(balance);
        break;
    case 8:
        AccountPanel();
        break;
    default:
        std::cout << "\tInvalid choice! Try again." << std::endl;
        break;
    }
    SaveTheSavings();
}

//-------------------------------------------------------------------------------------------------------------------//

// function showing us the functionality that withdraws money from the account
void Withdraw()
{
    int balance = CG->GetUserBalance();
    int choice;
    int withdrawAmount;
    int customerRequest;
    system("cls");
    std::cout << "\t\tPlease enter your selection" << std::endl;
    std::cout << "\t1 - $10" << std::endl;
    std::cout << "\t2 - $20" << std::endl;
    std::cout << "\t3 - $40" << std::endl;
    std::cout << "\t4 - $60" << std::endl;
    std::cout << "\t5 - $80" << std::endl;
    std::cout << "\t6 - $100" << std::endl;
    std::cout << "\t7 - Custom Amount" << std::endl;
    std::cout << "\t8 - Back" << std::endl;
    std::cout << "\tEnter your choice: ";
    std::cin >> choice;
    system("cls");
    switch (choice)
    {
    case 1:
        withdrawAmount = 10;
        break;
    case 2:
        withdrawAmount = 20;
        break;
    case 3:
        withdrawAmount = 40;
        break;
    case 4:
        withdrawAmount = 60;
        break;
    case 5:
        withdrawAmount = 80;
        break;
    case 6:
        withdrawAmount = 100;
        break;
    case 7:
        std::cout << "\tEnter amount to Withdraw: ";
        std::cin >> customerRequest;
        withdrawAmount = customerRequest;
        break;
    case 8:
        AccountPanel();
        break;
    default:
        std::cout << "\tInvalid choice! Try again." << std::endl;
        break;
    }
    if (withdrawAmount > balance)
    {
        std::cout << "\tYou don't have enough cash"
                  << "\n\tYour balance is: " << balance << "$" << std::endl;
        Sleep(5000);
    }
    else
    {
        balance = balance - withdrawAmount;
        CG->SetUserBalance(balance);
    }
    withdrawAmount = 0;
    SaveTheSavings();
}

//-------------------------------------------------------------------------------------------------------------------//