#include <iostream>
#include <sstream>
#include <time.h>

using namespace std;

class Player {
    public:
    Player(int x, int y){
        health = MAX_HEALTH;
        hunger = MAX_HUNGER;
        thirst = MAX_THIRST;
        
        this->x = x;
        this->y = y;
        this->score = 0;
    }
    
    int getScore() const {
        return score;
    }
    
    void takeDamage(int val){
        this->health -= val;
        if(this->health < 0) this->health = 0;
    }
    
    void takeHunger(int val){
        this->hunger -= val;
        if(this->hunger < 0) this->hunger = 0;
    }
    
    void takeThirst(int val){
        this->thirst -= val;
        if(this->thirst < 0) this->thirst = 0;
    }
    
    void takeTurn(){
        this->thirst--;
        this->hunger--;
        
        if(this->thirst <= 0){
            this->health--;
            this->thirst = 0;
        }
        
        if(this->hunger <= 0){
            this->health--;
            this->hunger = 0;
        }
        
        this->score++;
    }
    
    string getStats() const {
        stringstream ss;
        ss  << "============\n"
            << "Health: " << this->health << "\n" 
            << "Hunger: " << this->hunger << "\n" 
            << "Thirst: " << this->thirst << "\n"
            << "============\n";
        return ss.str();
    }
    
    bool isAlive() const {
        return this->health > 0;
    }
    
    void increaseThrist(int val){
        //this->thirst = this->thirst + val;
        if(this->thirst > MAX_THIRST) this->thirst = MAX_THIRST;
    }
    
    void increaseHunger(int val){
        this->hunger += val;
        if(this->hunger > MAX_HUNGER) this->hunger = MAX_HUNGER;
    }
    
    int x, y;
    private:
    int health, hunger, thirst, score;
    const int MAX_HEALTH = 3;
    const int MAX_HUNGER = 5;
    const int MAX_THIRST = 3;
};

class Land {
    public:
    virtual string getDescription() = 0;
    virtual string visit(Player& player) = 0;
};

// TODO: Define at least 3 more types of derivded land types
// TODO: Add some unique effect to each new type

class Forest : public Land {
    public:
    string getDescription(){
        return "a densely wooded forest.";
    }
    
    string visit(Player& player){
        int randomNum = rand() % 100;
        
        if(randomNum > 74){
            player.takeDamage(1);
            return "You are attacked by a bear while foraging for berries.";
        } else {
            player.increaseHunger(1);
            return "You forage for berries in the woods and eat a few.";
        }
    }
};

class Lake : public Land {
    public:
    string getDescription(){
        return "a clear sparkling lake.";
    }
    
    string visit(Player& player){
        player.increaseThrist(2);
        return "You visit the lake and drink its clean water";
    }
};

// New land
class Jungle : public Land{
    public:
    string getDescription (){
        return "a loud and crowded jungle.";
    }
    
    string visit(Player& player){
        player.takeDamage(1);
        player.increaseHunger(1);
        return "You wander the jungle and a monkey throws a banana at you";
    }
};

// New land
class Beach : public Land{
    public:
    string getDescription (){
        return "a sandy and hot beach.";
    }
    
    string visit(Player& player){
        player.takeThirst(2);
        return "You start to get thirsty and take a sip of the salt water";
    }
};

// New land
class Swamp : public Land{
    public:
    string getDescription (){
        return "a froggy filled swamp.";
    }
    
    string visit(Player& player){
        player.takeDamage(2);
        return "You get stuck in the mud and the frogs attack you!";
    }
};

const int MAP_SIZE = 10;
Land* map[MAP_SIZE][MAP_SIZE];

void populateMap(){
    for(int i = 0; i < MAP_SIZE; i++){
        for(int j = 0; j < MAP_SIZE; j++){
            // TODO: Modify this code to add your new land types
            int randomNum = rand() % 5;
            switch(randomNum){
                case 0: // Forest
                    map[i][j] = new Forest;
                    break;
                case 1: // Lake
                    map[i][j] = new Lake;
                    break;
                case 2: // Jungle
                    map[i][j] = new Jungle;
                    break;
                case 3: // Beach
                    map[i][j] = new Beach;
                    break;
                case 4: // Swamp
                    map[i][j] = new Swamp;
                    break;
                default:
                    cout << "Invalid land type selected" << endl;
                    break;
            }
        }
    }
}

int wrap(int index) {
    if(index < 0) {
        return MAP_SIZE - 1;
    } else if(index >= MAP_SIZE) {
        return 0;
    } else {
        return index;
    }
}

int main(){
    srand(time(0));
    
    populateMap();
    
    Player player(MAP_SIZE/2, MAP_SIZE/2);
    
    cout << "You wake up and find yourself lost in the middle of a strange wilderness." << endl;
    
    // TODO: Handle boundary conditions (e.g., if index out of bounds north, you index the south-most location)
    
    while(player.isAlive()){
        
        int north = wrap(player.y - 1);
        int east = wrap(player.x + 1);
        int south = wrap(player.y + 1);
        int west = wrap(player.x - 1);
        
        cout << "To the north you see " << map[player.x][player.y - 1]->getDescription() << endl;
        cout << "To the east you see " << map[player.x + 1][player.y]->getDescription() << endl;
        cout << "To the south you see " << map[player.x][player.y + 1]->getDescription() << endl;
        cout << "To the west you see " << map[player.x - 1][player.y]->getDescription() << endl;
        
        cout << "Which way will you go? Enter N, E, S, or W:" << endl;
        char userInput;
        cin >> userInput;
        
        while (userInput != 'N' || userInput != 'n' || userInput != 'E' || userInput != 'e' || userInput != 'W' || userInput != 'w' || userInput != 'S' || userInput != 's'){
            if (userInput == 'N' || userInput == 'n' || userInput == 'E' || userInput == 'e' || userInput == 'W' || userInput == 'w' || userInput == 'S' || userInput == 's'){
                break;
            }
            cout <<  "Invalid input try again!" << endl;
            cin >> userInput;
            
        }
        
        switch(userInput){
            case 'N':
                player.y = wrap(player.y - 1);
                break;
            case 'E':
                player.x = wrap(player.x + 1);
                break;
            case 'S':
                player.y = wrap(player.y + 1);
                break;
            case 'W':
                player.x = wrap(player.x - 1);
                break;
            default:
                break;
        }
        
        cout << map[player.x][player.y]->visit(player) << endl;
        
        cout << player.getStats() << endl;
        player.takeTurn();
    }
    
    cout << "You died." << endl;
    cout << player.getScore() << endl;
    
    return 0;
}