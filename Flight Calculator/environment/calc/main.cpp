#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
using namespace std;

const double radius = 3958.8;
//Distance calculations
double haversine(double lat1, double long1, double lat2, double long2, double radius){
    double sinSquare1 = pow(sin((lat2 - lat1)/2.0), 2.0);
    double sinSquare2 = pow(sin((long2 - long1)/2.0), 2.0);
    double distance = 2 * radius * asin(sqrt(sinSquare1 + cos(lat1) * cos(lat2) * sinSquare2)); 
    return distance;
}

const int speedMPH = 500;
//Flight time calculations
double getFlightTime(double lat1, double long1, double lat2, double long2){
    double distance = haversine(lat1, long1, lat2, long2, radius);
    double hours = distance/speedMPH;
    return hours;
}

const int listSize = 12;
const int listSize1 = 11;
const int characters = 100000;
const int zero = 0;
//change names to user input and adjust small things for departure or destination
int wrongInputCheck(bool departure){
    //Getting departure location
    char userInput[characters];
    if (departure == true){
        cout << "Where are you departing from? (Input the number)" << endl;
    } else {
        cout << "Where is your destination? (Input the number)" << endl;
    }
    
    cin.getline(userInput, characters);
    int value;
    //Will ask again if a number is not inputted
    while (atoi(userInput) == zero){
        if (atoi(userInput) != zero){
            value = atoi(userInput);
            break;
        } else {
            cout << "Try again! Input a number from the list" << endl;
            cin.getline(userInput, characters);
        }
    }
    //Will ask again if the number is not on the list
    while(atoi(userInput) != zero){
        value = atoi(userInput);
        if (departure == true && value > zero && value <= listSize){
            break;
        } else if (departure == false && value > zero && value <= listSize1){
            break;
        } else {
            cout << "Try again! Input a number from the list" << endl;
            cin.getline(userInput, characters);
            //Will ask again if the user inputs a string after putting the wrong number
            while (atoi(userInput) == zero){
                if (atoi(userInput) != zero){
                    value = atoi(userInput);
                    break;
                } else {
                    cout << "Try again! Input a number from the list" << endl;
                    cin.getline(userInput, characters);
                }
            }
        }
    }
    return value;
}

int main(){
    //Introduction sentence
    cout << "The purpose of this application is to "
    "compute the amount of time it takes an "
    "airplane to fly from one GPS location to another." << endl;
    
    //Hard coding data
    vector <string> name = {"Miami Beach", "Fargo", "Idaho City", 
    "Belmont", "Grifton", "Keene", "Manhattan", "Cary", "Canton", 
    "North Las Vegas", "Lynn", "Garden City"};
    
    vector <double> latitude = {25.793449, 46.877186, 43.828850, 37.524174, 
    35.372662, 42.934307, 39.183609, 35.791538, 40.798946, 36.201946, 42.466763, 42.325569};
    
    vector <double> longitude = {-80.139198, -96.789803, -115.837860, -122.304199, 
    -77.437462, -72.283859, -96.571671, -78.781120, -81.378448, -115.120216, -70.949493, -83.330933};
    
    vector <string> state = {"FL", "ND", "ID", "CA", 
    "NC", "NH", "KS", "NC", "OH", "NV", "MA", "MI"};
    
    const int increment = 1;
    const int decimalPlace = 10;
    //List of options locations
    for (int i = 0; i < name.size(); i++){
        cout<< i + increment << ". " << name.at(i) << ", " << state.at(i) 
        << ", USA ";
        std:: cout << std::setprecision(decimalPlace) << latitude.at(i) << " ";
        std:: cout << std::setprecision(decimalPlace) << longitude.at(i) << endl; 
    }
    
    //Will make sure the user input does not bug for departure
    const int departure = wrongInputCheck(true);
    
    //creates new departure vector
    vector <double> latitude1 = {};
    vector <double> longitude1 = {};
    
    int count = 1;
    //Creates updated list
    for (int i = 0; i < name.size(); i++){
        if (i + increment != departure){
            cout<< count << ". " << name.at(i) << ", " << state.at(i) 
            << ", USA ";
            std::cout << std::setprecision(decimalPlace) << latitude.at(i) << " ";
            std:: cout << std::setprecision(decimalPlace) << longitude.at(i) << endl; 
            count +=increment;
            latitude1.push_back(latitude.at(i));
            longitude1.push_back(longitude.at(i));
        }
        
    }
    
    //Will make sure the user input does not bug for departure
    const int destination = wrongInputCheck(false);
    
    //calling functions based on user input
    double distance = haversine(latitude.at(departure - increment), longitude.at(departure - increment), 
    latitude1.at(destination - increment), longitude1.at(destination - increment), radius);
    
    double hours = getFlightTime(latitude.at(departure - increment), longitude.at(departure - increment), 
    latitude1.at(destination - increment), longitude1.at(destination - increment));
    
    cout << "Distance between the departure zone and destination is: " << distance << endl;
    
    const int decimalPlace1 = 6;
    cout << "This flight takes " << std::setprecision(decimalPlace1) << hours << " hours, going at 500mph" << endl;
   
    return 0;
}