#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#ifndef WEAPON_H
#define WEAPON_H

using namespace std;

class Weapon{
    private:
    string name;// weapon name
    int attack;// weapon attack
    int defense;// weapon defense
    public:
    // constructor
    Weapon();
    // setters
    void setName(string name_);
    void setAttack(int attack_);
    void setDefense(int defense);
    // getters
    string getName();
    int getAttack();
    int getDefense();
};

#endif