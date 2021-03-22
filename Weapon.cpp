#include "Weapon.h"
// constructor
Weapon::Weapon(){
    name = "";
    defense = 0;
    attack = 0;
}
//setters
void Weapon::setName(string name_){
    name = name_;
}
void Weapon::setAttack(int attack_){
    attack = attack_;
}
void Weapon::setDefense(int defense_){
    defense = defense_;
}
//getters
string Weapon::getName(){
    return name;
}
int Weapon::getAttack(){
    return attack;
}
int Weapon::getDefense(){
    return defense;
}