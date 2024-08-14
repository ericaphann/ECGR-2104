#include "cryption.h"
#include <iostream>
#include <fstream>
#include <cstring>

void cryption::encryption(int key, string ifile, string ofile){
    this->key = key;
    this->file = file;
    
    outFile.open(ofile);
    inFile.open(ifile);
    
    while (inFile >> tempword){
        for (int i = 0; i < tempword.length(); i++){
            ch = tempword[i];
            if (ch >= 'a' && ch <= 'z'){
                ch = ch + key;
                if (ch > 'z') {
                   ch = ch - 'z' + 'a' - 1;
                }  
                tempword[i] = ch;
            } else if (ch >= 'A' && ch <= 'Z'){
                ch = ch + key;
                if (ch > 'Z'){
                   ch = ch - 'Z' + 'A' - 1;
                }
                tempword[i] = ch;
            }
        }
        outFile << tempword << " ";
    }
    
    outFile.close();
    inFile.close();
    
}

void cryption::decryption(int key, string ifile, string ofile){
    ofstream outFile;
    ifstream inFile;
    this->key = key;
    this->file = file;
    
    outFile.open(ofile);
    inFile.open(ifile);
    
    while (inFile >> tempword){
        for (int i = 0; i < tempword.length(); i++){
            ch = tempword[i];
            if (ch >= 'a' && ch <= 'z'){
                ch = ch - key;
                if (ch < 'a') {
                   ch = ch + 'z' - 'a' - 1;
                }  
                tempword[i] = ch;
            } else if (ch >= 'A' && ch <= 'Z'){
                ch = ch - key;
                if (ch < 'A'){
                   ch = ch + 'Z' - 'A' - 1;
                }
                tempword[i] = ch;
            }
        }
        outFile << tempword << " ";
    }
    
    outFile.close();
    inFile.close();
}