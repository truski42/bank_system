#include <iostream>
#include <fstream>
#include <stdio.h>
#include "encrypt.h"

using namespace std;

void encdec::encrypt()
{
    // Key to be used for encryption
    key = 5;

    // Input stream
    fstream fin, fout;

    // Open input file
    // ios::binary- reading file
    // character by character
    fin.open(file, fstream::in);
    fout.open("encrypt.txt", fstream::out);

    // Reading original file till
    // end of file
    while (fin >> noskipws >> c)
    {
        int temp = (c + key);

        // Write temp as char in
        // output file
        fout << (char)temp;
    }

    // Closing both files
    fin.close();
    fout.close();
}