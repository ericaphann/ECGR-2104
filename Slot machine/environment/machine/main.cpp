#include <iostream>
#include <time.h>

using namespace std;

int main(){
    
    srand(time(0));
    string start_end;
    string pull;
    
    //start question
    cout << "Hello! Would you like to play or exit?" << endl;
    cin >> start_end;
    
    //start money
    int dollars = 10;
    
    //If the user enters something other than exit or play this will catch it
    //until the user inputs exit or play.
    while(start_end != "exit" && start_end != "play"){
        cout << "Try again!" << endl;
        cin >> start_end;
        if (start_end == "exit"){
            break;
        } else if (start_end == "play"){
            break;
        }
    }
    
    while (start_end == "play"){
        
        //display money
        cout << "You currently have " << dollars << " dollars." << endl;
        
        //Ask user to pull or end
        cout << "Would you like to pull or exit?" << endl;
        cin >> pull;
        
        //User choses pull
        if (pull == "pull"){
            //Subtract cost of pull $1
            dollars -= 1;
            
            //three random numbers
            int x = rand() % 4;
            int y = rand() % 4;
            int z = rand() % 4;
            string x1;
            string y1;
            string z1;
            
            //Set symbols for x
            if (x == 0){
                x1 = "7";
            } else if (x == 1){
                x1 = "$";
            } else if (x == 2){
                x1 = "#";
            } else if (x == 3){
                x1 = "X";
            }
            
            //Set symbols for y
            if (y == 0){
                y1 = "7";
            } else if (y == 1){
                y1 = "$";
            } else if (y == 2){
                y1 = "#";
            } else if (y == 3){
                y1 = "X";
            }
            
            //Set symbols for z
            if (z == 0){
                z1 = "7";
            } else if (z == 1){
                z1 = "$";
            } else if (z == 2){
                z1 = "#";
            } else if (z == 3){
                z1 = "X";
            }
            
            //print values
            cout << x1 << y1 << z1 << endl;
            
            if (x1 + y1 + z1 == "777"){
                dollars += 100;
            } else if (x1 + y1 + z1 == "$$$"){
                dollars += 50;
            } else if (x1 + y1 + z1 == "###"){
                dollars += 25;
            } else if (x1 + y1 + z1 == "XXX"){
                dollars += 10;
            }
            
        }
        
        //End game when user chooses exit
        if (start_end == "exit" || pull == "exit"){
            break;
        }
        
        //End game when user hits $0
        if (dollars == 0){
            cout << "You hit $0!" << endl;
            break;
        }
    }
    
    if (start_end == "exit"){
        return 0;
    }
    
    
    
    return 0;
}