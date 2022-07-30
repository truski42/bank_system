#include <iostream>
#include <stdio.h>
#include "deletefile.h"
using namespace std;
void deletefile::DestoryFile(){
    int status;
    status = remove(fileName);
    if (status == 0)
        cout << "\nFile Deleted Successfully!";
    else
        cout << "\nError Occurred!";
    cout << endl;
}
