#ifndef FOOD_H
#define FOOD_H

#include <iostream>

using namespace std;

class FoodItem{
    public:
    FoodItem();
    FoodItem(string name, int calories, int fat, int sugars, int protein, int sodium);
    FoodItem operator+(FoodItem rhs);
    string getName();
    int getCalories();
    int getFat();
    int getSugars();
    int getProtein();
    int getSodium();
    void Print() const;
    
    private:
    //Private members
    string name;
    int calories;
    int fat;
    int sugars;
    int protein;
    int sodium;
};

//guard
#endif