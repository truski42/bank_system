#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <fstream>
#include "Data\personal_id.h"
#include "Data\account.h"
#include "Data\encrypt.h"
#include "Data\deletefile.h"
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;

int main()
{
	encdec E;
	deletefile D;
	srand(time(0));
	int choice;
	system("cls");
	system("Color 0A");
	CreatePerson();
	std::cout << "\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM" << std::endl;
	while (true)
	{
		LoadPerson();
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
			E.encrypt();
			//D.DestoryFile();
			break;
		case 2:
			LoginPerson();
			break;
		case 3:
			NewAccount();
			break;
		case 4:
			//DestroyPerson();
			exit(0);
		default:
			break;
		}
	}
	return 0;
}
