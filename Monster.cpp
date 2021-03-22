#include "Monster.h"
Monster::Monster(){
    name = "";
    attack = 0;
    defense = 0;
    health = 0;
    xPos = 0;
    yPos = 0;
}

void Monster::setName(string name_){
    name = name_;
}
void Monster::setAttack(int attack_){
    attack = attack_;
}
void Monster::setDefense(int defense_){
    defense = defense_;
}
void Monster::setHealth(int health_){
    health = health_;
}
void Monster::setXPos(int x){
    xPos = x;
}
void Monster::setYPos(int y){
    yPos = y;
}
    //getters
string Monster::getName(){
    return name;
}
int Monster::getAttack(){
    return attack;
}
int Monster::getDefense(){
    return defense;
}
int Monster::getHealth(){
    return health;
}
int Monster::getXPos(){
    return xPos;
}
int Monster::getYPos(){
    return yPos;
}