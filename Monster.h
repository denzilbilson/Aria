#include <iostream>
#include <string>
#ifndef MONSTER_H
#define MONSTER_H
using namespace std;
class Monster{
    private:
    string name;// monster name
    int attack;// monster attack strength
    int defense;// monster defense
    int health;// monster health
    int xPos;
    int yPos;
    public:
    // constructor
    Monster();
    
    // setters
    void setName(string name_);
    void setAttack(int attack_);
    void setDefense(int defense_);
    void setHealth(int health_);
    void setXPos(int x);
    void setYPos(int y);
    
    //getters
    string getName();
    int getAttack();
    int getDefense();
    int getHealth();
    int getXPos();
    int getYPos();
};
#endif