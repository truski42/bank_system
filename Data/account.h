#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <fstream>
class Person
{
public:
    Person();
    ~Person();
    void SetUserBalance(int x) {user_balance = x;}
    void SetFirstName(std::string x) { first_name = x; }
    void SetLastName(std::string x) { last_name = x; }
    void SetCountryBirth(std::string x) { country_of_birth = x; }
    void SetPersonalId(std::string x) { personal_id = x; }
    void SetAccountNumber(std::string x) { account = x; }
    int GetUserBalance() { return user_balance;}
    std::string GetFirstName() { return first_name; }
    std::string GetLastName() { return last_name; }
    std::string GetCountrytBirth() { return country_of_birth; }
    std::string GetPersonalId() { return personal_id; }
    std::string GetAccountNumber() { return account; }

protected:
    std::string first_name;
    std::string last_name;
    std::string personal_id;
    std::string country_of_birth;
    std::string account;
    int user_balance;
    bool one_load;
};
// Function Prototypes
void LoginPerson();
void CreatePerson();
void NewAccount();
void DisplayAccount();
void SavePerson();
void LoadPerson();
void DestroyPerson();

// Function prototypes for the interface panel
void AccountPanel();
void CheckBalance();
void Withdraw();
void Deposit();
std::string gen_random(const int len);
#endif // ACCOUNT_H
