#include <iostream>
#include <windows.h> 
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <fstream>

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
template <typename F>
void file_system(F f_first_name, F f_last_name, F f_personal_id, F f_country_of_birth, F f_account_number){
	ofstream user_account("user_accounts.txt", ofstream::app);
	if(user_account.is_open()){
		user_account << f_first_name << endl;
		user_account << f_last_name << endl;
		user_account << f_personal_id << endl;
		user_account << f_country_of_birth << endl;
		user_account << f_account_number << endl;
		user_account.close();
	}else cout << "Problem with opening file";
}

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
	file_system(country_of_birth, first_name, last_name, personal_id, account);
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
