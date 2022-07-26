#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H
#include <fstream>
#include <iostream>
#include <vector>
#include "..\rapidxml.hpp"
using std::cout;
using std::endl;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;
using namespace rapidxml;

void file();
void file_write();
void show();
string gen_random();
template <typename W>
void file(W f_first_name, W f_last_name, W f_personal_id, W f_country_of_birth, W f_account_number)
{
	ofstream user_account("user_accounts.txt", ofstream::app);
	if (user_account.is_open())
	{
		cout << "\tsuccessfully create the file\n";
	}
	vector<string> users;
	users.push_back(f_first_name);
	users.push_back(f_last_name);
	users.push_back(f_personal_id);
	users.push_back(f_country_of_birth);
	users.push_back(f_account_number);
	int a = 0;
	for (string name : users)
	{
		user_account << name << endl;
	}
	user_account.close();
}
template <typename W>
void file_write(W f_first_name, W f_last_name, W f_personal_id, W f_country_of_birth, W f_account_number)
{
	ofstream user_account("user_accounts.txt", ofstream::out);
	if (user_account.is_open())
	{
		user_account << f_first_name << "\n";
		user_account << f_last_name << "\n";
		user_account << f_personal_id << "\n";
		user_account << f_country_of_birth << "\n";
		user_account << f_account_number << "\n";
		user_account.close();
	}
	else
		cout << "Problem with opening file";
}
template <typename R>
void file_read(R f_country_of_birth)
{
	try{
		cout << "success";
		ifstream user_account("user_accounts.txt", ifstream::in);
		getline(user_account, f_country_of_birth);
		user_account.close();
	}catch(int exc){
		cout<< exc;
	}
/*	if (user_account.is_open())
	{
		int lineNumber = 1;
		cout << "\tsuccessfully opened the file user_account\n";
		string line;
			for(int i = 1; i <= lineNumber; i++){
				getline(user_account, line);
				cout << line << endl;
			}
	}
	else
	{
		cout << "\tsomething went wrong\n";
	}
	*/
}
/*string gen_random(const int len){
	//ofstream user_account("user_accounts.txt", ofstream::app);
	static const char alphanum[] = "0123456789";
	string tmp_s;
	tmp_s.reserve(len);

	for(int i = 0; i < len; ++i){
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
	}
	return tmp_s;
}*/
#endif // FILE_SYSTEM_H