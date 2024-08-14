#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class employee {
    public:
    void setName(string name1){
        name = name1;
    }
    
    string getName(){
        return name;
    }
    
    void setJobTitle(string jobTitle1){
        jobTitle = jobTitle1;
    }
    
    string getJobTitle(){
        return jobTitle;
    }
    
    void setHourlyWage(double hourlyWage1){
        //This will automatically make it positive if a negative is entered
        if (hourlyWage1 < 0){
            hourlyWage1 = hourlyWage1 * -1;
        }
        hourlyWage = hourlyWage1;
    }
    
    double getHourlyWage(){
        return hourlyWage;
    }
    
    double getTotalWage(double hours){
        double total = hours * hourlyWage;
        return total;
    }
    
    void print(){
        cout << "Name: " << name << endl;
        cout << "Job Title: " << jobTitle << endl; 
        cout << "Hourly Wage: " << hourlyWage << endl;
        cout << endl;
    }
    
    private:
    string name;
    string jobTitle;
    double hourlyWage;
};

int main(){
    
    employee erica;
    employee daisy;
    employee monica;
    employee daliya;
    employee elizabeth;
    employee tina;
    
    erica.setName("Erica");
    erica.setJobTitle("Manager");
    erica.setHourlyWage(25.75);
    
    daisy.setName("Daisy");
    daisy.setJobTitle("Director");
    daisy.setHourlyWage(50.50);
    
    monica.setName("Monica");
    monica.setJobTitle("Cashier");
    monica.setHourlyWage(13.25);
    
    daliya.setName("Daliya");
    daliya.setJobTitle("Server");
    daliya.setHourlyWage(7.25);
    
    elizabeth.setName("Elizabeth");
    elizabeth.setJobTitle("Manager");
    elizabeth.setHourlyWage(25.75);
    
    tina.setName("Tina");
    tina.setJobTitle("Assistant Manager");
    tina.setHourlyWage(18.0);
    
    vector <employee> employees = {erica, daisy, monica, daliya, elizabeth, tina};
    
    
    
    cout << "This application will track employee's names, job titles, and wages." << endl;
    cout << "This application will also be used to calculate the total amount of wages that employees are to be paid for the week." << endl;
    
    string userInput;
    char hours[1000];
    double value;
    while (true){
        cout << "Please input which option you want (input 1 or 2 or 3)" << endl;
        cout << "1. Print list of employees" << endl;
        cout << "2. Calculate total wages" << endl;
        cout << "3. Exit application" << endl;
        
        cin >> userInput;
        double TotalWage = 0.0;
        
        if (userInput == "1"){
            for (int i = 0; i < employees.size(); ++i){
                employee current = employees.at(i);
                current.print();
            }
        } else if (userInput == "2"){
            
            for (int i = 0; i < employees.size(); ++i){
                employee current = employees.at(i);
                
                cout << "How many hours has " << current.getName() << " worked? (Double type)" << endl;
                cin.ignore(256, '\n');
                cin >> hours;
                
                //Will ask again if a number is not inputted
                while (atof(hours) == 0){
                    if (atof(hours) != 0){
                        value = atof(hours);
                        break;
                    } else {
                        cout << "Try again! Input a valid number (A double type)" << endl;
                        cin.ignore(256, '\n');
                        cin >> hours;
                    }
                }
                
                while (atof(hours) != 0){
                    value = atof(hours);
                    if (atof(hours) == 0){
                        cout << "Try again! Input a valid number (A double type)" << endl;
                        cin.ignore(256, '\n');
                        cin >> hours;
                    }
                    
                    if (atof(hours) != 0){
                        value = atof(hours);
                        break;
                    } else {
                        cout << "Try again! Input a valid number (A double type)" << endl;
                        cin.ignore(256, '\n');
                        cin >> hours;
                    }
                }
                if (value < 0 ){
                    value = value * -1;
                }
                TotalWage += current.getTotalWage(value);
                
            }
            cout << "Total wage of all employees combined: " << TotalWage << endl;
        } else if (userInput == "3"){
            break;
        } else {
            cout << "Try Again! Please enter 1 or 2 or 3" << endl;
        }
    } 
    
    return 0;
}