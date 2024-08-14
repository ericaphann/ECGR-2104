#include <iostream>
#include "food.h"
#include <vector>
using namespace std;

int main(){
    int i; 
    char userInput[10000];
    int value;
    
    //Creating vector to hold list of food and their values
    vector <FoodItem> foodList;
    FoodItem total;
    FoodItem Apple("Apple", 50, 0, 5, 10, 0);
    foodList.push_back(Apple);
    FoodItem Banana("Banana", 50, 0, 5, 10, 0);
    foodList.push_back(Banana);
    FoodItem Chicken("Chicken", 1000, 30, 5, 35, 100);
    foodList.push_back(Chicken);
    FoodItem Fish_Rice("Fish and Rice", 1000, 20, 7, 20, 200);
    foodList.push_back(Fish_Rice);
    FoodItem Burger_Fries("Burger and Fries", 2000, 30, 10, 30, 300);
    foodList.push_back(Burger_Fries);
    FoodItem Omelette("Omelette", 700, 10, 9, 20, 50);
    foodList.push_back(Omelette);
    FoodItem Pancakes("Pancakes", 400, 5, 20, 5, 200);
    foodList.push_back(Pancakes);
    FoodItem Spaghetti("Spaghetti", 200, 10, 10, 15, 185);
    foodList.push_back(Spaghetti);
    FoodItem Pizza("Pizza", 600, 100, 10, 40, 1000);
    foodList.push_back(Pizza);
    FoodItem Burrito("Burrito", 60, 25, 20, 20, 20);
    foodList.push_back(Burrito);
    FoodItem Pasta("Pasta", 100, 10, 10, 30, 160);
    foodList.push_back(Pasta);
    FoodItem Cereal("Cereal", 70, 10, 40, 10, 100);
    foodList.push_back(Cereal);
    
    
    while (true){
        //Will create the list of food items and their names
        for (i = 0; i < foodList.size(); i++){
            FoodItem f = foodList.at(i);
            if (i == foodList.size() - 1){
                cout << i + 1 << ": " << f.getName() << endl;
                cout << foodList.size() + 1 << ": " << "Finished" << endl;
            } else {
                cout << i + 1 << ": " << f.getName() << endl;
            }
        }
        
        cin.getline(userInput, 1000);
        //If user input is not a number on the list
        while (atoi(userInput) == 0){
            if (atoi(userInput) != 0){
                value = atoi(userInput);
                break;
            } else {
                cout << "Try again! Input a number from the list" << endl;
                cin.getline(userInput, 1000);
            }
        }
        
        //if user input is a number it will check to make sure its a number on the list
        while (atoi(userInput) != 0){
                value = atoi(userInput);
                if (value > 0 && value <= foodList.size()+1){
                    break;
                } else {
                    cout << "Try again! Input a number from the list" << endl;
                    cin.getline(userInput, 1000);
                    while (atoi(userInput) == 0){
                        if (atoi(userInput) != 0){
                            value = atoi(userInput);
                            break;
                        } else {
                            cout << "Try again! Input a number from the list" << endl;
                            cin.getline(userInput, 1000);
                        }
                    }
                }
            }
        
        //Use addition overloader to add the nutritional values together
        for (i = 0; i < foodList.size(); i++){
            FoodItem a = foodList.at(i);
            int num = i + 1;
            if (value == num){
                total = total + a;
            }
            
        }
        
        if (value == foodList.size() + 1){
            total.Print();
            
            //Will print out specific messages based on the total nutritional values
            if (total.getCalories() <= 3000 && total.getCalories() >= 1000){
                cout << "Good Energy!" << endl;
            } else if (total.getCalories() > 3000){
                cout << "Too many calories!" << endl;
            } else {
                cout << "Not enough calories!" << endl;
            }
            
            if (total.getFat() < 70){
                cout << "Regular fat intake!" << endl;
            } else {
                cout << "Too much fat intake!" << endl;
            }
            
            if (total.getSugars() < 30){
                cout << "Good sugar intake!" << endl;
            } else {
                cout << "Too much sugar!" << endl;
            }
            
            if (total.getProtein() <= 70 && total.getProtein() >= 40){
                cout << "Good on protein intake!" << endl;
            } else if (total.getProtein() > 70){
                cout << "Too much protein!" << endl;
            } else {
                cout << "Not enough protein intake!" << endl;
            }
            
            if (total.getSodium() < 2300){
                cout << "Good sodium intake levels!" << endl;
            } else {
                cout << "Too much sodium intake!" << endl;
            }
            
            break;
        }
    }
    
    return 0;
}