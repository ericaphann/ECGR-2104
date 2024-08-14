#ifndef CRYPTION_H
#define CRYPTION_H
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class cryption{
    public:
    void encryption(int key, string ifile, string ofile);
    void decryption(int key, string ifile, string ofile);
    
    private:
    int key;
    string file;
    char ch;
    string tempword;
    ofstream outFile;
    ifstream inFile;
    
};


#endif