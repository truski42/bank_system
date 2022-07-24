#include <iostream>
#include <windows.h> 
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <fstream>
#include "C:\git repository\bank\bank_system\Data\file_system.h"

using std::fstream;
using std::ofstream;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::string;

class account{
protected:
	int account_number;
	string first_name;
	string last_name;
	string personal_id;
	string country_of_birth;
public:
	void new_acc();
	void read_acc();
};
string gen_random(const int len){
	ofstream user_account("user_accounts.txt", ofstream::app);
	static const char alphanum[] = "0123456789";
	string tmp_s;
	tmp_s.reserve(len);

	for(int i = 0; i < len; ++i){
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
	}
	return tmp_s;
}

void account::new_acc(){
	system("cls");
	cout << "\n\tEnter country of birth: ";
	cin >> country_of_birth;

	cout << "\n\tEnter your first name: ";
	cin >> first_name;
	

	cout << "\n\tEnter your last name: ";
	cin >> last_name;
	
	cout << "\n\tEnter your personal id: ";
	cin >> personal_id;
	

	string account = gen_random(9);
	cout << "\n\tThat is your account number, please remember it, you will need it for login: " << account << endl;
	file_system(first_name, last_name, country_of_birth, personal_id, account);
	system("\n\tpause");
	system("cls");
}

int main() {
	srand(time(0));
	account A;
	int choice;
	system("cls");
	system("Color 0A");
	std::cout << "\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM" << std::endl;
	while (true)
	{
		cout << "\t1. Create new account" << endl;
		cout << "\t2. Login to existing account" << endl;
		cout << "\t3. Exit" << endl;
		cout << "\n\tEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			A.new_acc();
			break;
		case 2:
			//A.random_account();
			break;
		case 3:
			//delete new_acc;
			exit(0);
		default:
			break;
		}
	}
	return 0;
}
