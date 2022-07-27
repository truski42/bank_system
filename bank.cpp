#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <fstream>
#include "C:\git repository\bank\bank_system\Data\personal_id.h"
#include "Data\account.h"
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;

class account
{
protected:
	int account_number;
	// string first_name;
	// string last_name;
	// string personal_id;
	// string country_of_birth;
public:
	void new_acc();
	void login_acc();
};

void account::new_acc()
{
	system("cls");
	cout << "\n\tEnter country of birth: ";
	// cin >> country_of_birth;

	cout << "\n\tEnter your first name: ";
	// cin >> first_name;

	cout << "\n\tEnter your last name: ";
	// cin >> last_name;

	cout << "\n\tEnter your personal id: ";
	// cin >> personal_id;
	string account = gen_random(9);
	// cout << "\n\tThat is your account number, please remember it, you will need it for login: " << account << endl;
	// cout << "peselk" << getBirthYear();
	// file_write(first_name, last_name, country_of_birth, personal_id, account);
	// vector <string> wektor_1 = {country_of_birth, first_name, last_name, personal_id, account};
	// file(country_of_birth);
	// file(first_name, last_name, country_of_birth, personal_id, account);
	system("\n\tpause");
	system("cls");
}
void account::login_acc()
{
	system("cls");
	cout << "Enter your account number: " << endl;
	ifstream user_account("user_accounts.txt", ifstream::in);
	// file_read(country_of_birth);
}
int main()
{
	CreatePerson();
	srand(time(0));
	// account A;
	int choice;
	system("cls");
	system("Color 0A");
	std::cout << "\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM" << std::endl;
	while (true)
	{
		//LoadPerson();
		cout << "\t1. Create new account" << endl;
		cout << "\t2. Login to existing account" << endl;
		cout << "\t3. Edit your account" << endl;
		cout << "\t4. Exit" << endl;
		cout << "\n\tEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			NewAccount();
			// A.new_acc();
			break;
		case 2:
			LoginPerson();
			// A.login_acc();
			break;
		case 3:
			NewAccount();
			break;
		case 4:
			// delete new_acc;
			exit(0);
		default:
			break;
		}
	}
	return 0;
}
