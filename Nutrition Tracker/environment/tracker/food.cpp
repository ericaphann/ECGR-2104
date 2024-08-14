#include "food.h"
//Default constructor
FoodItem::FoodItem(){
    name = "No name";
    calories = 0;
    fat = 0;
    sugars = 0;
    protein = 0;
    sodium = 0;
};
//Constructor with parameters
FoodItem::FoodItem(string name, int calories, int fat, int sugars, int protein, int sodium){
    this -> name = name;
    this -> calories = calories;
    this -> fat = fat;
    this -> sugars = sugars;
    this -> protein = protein;
    this -> sodium = sodium;    
};

//Addition operator
FoodItem FoodItem::operator+(FoodItem rhs){
    FoodItem f;
    f.name = name + " and " + rhs.name;
    f.calories = calories + rhs.calories;
    f.fat = fat + rhs.fat;
    f.sugars = sugars + rhs.sugars;
    f.protein = protein + rhs.protein;
    f.sodium = sodium + rhs.sodium;
    return f;
}

//Accessors 
string FoodItem::getName(){
    return name;
}

int FoodItem::getCalories(){
    return calories;
}

int FoodItem::getFat(){
    return fat;
}

int FoodItem::getSugars(){
    return sugars;
}

int FoodItem::getProtein(){
    return protein;
}

int FoodItem::getSodium(){
    return sodium;
}

//Print function
void FoodItem::Print() const {
    cout << "Total: " << "Calories: " << calories << "cal" << ", Fat: " <<
    fat << "g" << ", Sugar: " << sugars << "g" << ", Protein: " << protein << "g" << ", Sodium: " << sodium << "mg" << endl;
}