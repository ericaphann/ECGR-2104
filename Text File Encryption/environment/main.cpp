#include <iostream>
#include <fstream>
#include <cstring>
#include "cryption.h"

using namespace std;


int main(int argc, char* argv[]){
    string fileinput;
    string fileoutput;
    bool encrypting = false;
    bool decrypting = false;
    int key;
    ofstream outFile;
    ifstream inFile;
    cryption c;
    
    for (int i = 0; i < argc; i ++){
        
        //if(argv[i][0] == '-' && argv[i][1] == 'o'){
        if (strcmp(argv[i], "-o") == 0){
            if (i + 1 < argc){
                fileoutput = string(argv[i + 1]);
            } else {
                cout << "missing file name" << endl;
                return 1;
            }
        }else if (strcmp(argv[i], "-i") == 0){
            if (i + 1 < argc){
                fileinput = string(argv[i + 1]);
            } else {
                cout << "missing file name" << endl;
                return 1;
            }
        }else if (strcmp(argv[i], "-k") == 0){
            if (i + 1 < argc){
                if (atoi(argv[i + 1]) == 0){
                    cout << "Enter an int value for the key!" << endl;
                    return 1;
                }
                key = atoi(argv[i + 1]);
            } else {
                cout << "missing key number" << endl;
                return 1;
            }
        }else if (strcmp(argv[i], "-e") == 0){
            if (i < argc){
                encrypting = true;
            }
        }else if (strcmp(argv[i], "-d") == 0){
            if (i < argc){
                decrypting = true;
            }
        }
    }
    
    if (encrypting == true){
        c.encryption(key, fileinput, fileoutput);
    } else if (decrypting == true){
        c.decryption(key, fileinput, fileoutput);
    } else if (encrypting == false && decrypting == false){
        cout << "No -e or -d" << endl;
        return 1;
    }
    
    return 0;
}