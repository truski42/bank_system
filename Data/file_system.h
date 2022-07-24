#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H
#include <fstream>
#include <iostream>
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::cout;
using std::endl;
template <typename F>
void file_system(F f_first_name, F f_last_name, F f_personal_id, F f_country_of_birth, F f_account_number){
	ofstream user_account("user_accounts.txt", ofstream::app);
	if(user_account.is_open()){
		user_account << f_first_name << ", " << f_last_name << ", " << f_personal_id << ", " << f_country_of_birth << ", " << f_account_number << endl;
		user_account.close();
	}else cout << "Problem with opening file";
}
#endif //FILE_SYSTEM_H