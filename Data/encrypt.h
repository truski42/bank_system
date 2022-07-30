#ifndef ENCRYPT_H
#define ECRYPT_H
#include <iostream>
#include <fstream>
#include <stdio.h>

class encdec
{
    int key;

    // File name to be encrypt
    char file[20] = "user_accounts.txt";
    char c;

public:
    void encrypt();
    void decrypt();
};
#endif // ENCRYPT_H