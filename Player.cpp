#include "Player.h"
//constructor
Player::Player(){
    name = "";
    attack = 10;
    defense = 10;
    health = 10;
    level = 1;
    active = 0;
    points = 0;
    xMap = 7;
    yMap = 4;
    numWeapons = 0;
}
void Player::setName(string name_){
    name = name_;
}
void Player::setPosition(int x, int y){
    xMap = x;
    yMap = y;
}
void Player::setAttack(int attack_){
    attack = attack_;
}
void Player::setDefense(int defense_){
    defense = defense_;
}
void Player::setHealth(int health_){
    health = health_;
}
void Player::setLevel(int level_){
    level = level_;
}
void Player::setNumWeapons(int num){
    numWeapons = num;
}
void Player::addWeapon(Weapon x){
    weapons[numWeapons].setName(x.getName());
    weapons[numWeapons].setAttack(x.getAttack());
    weapons[numWeapons].setDefense(x.getDefense());
    setNumWeapons(getNumWeapons() + 1);
}
void Player::setxMap(int x_map){
    xMap = x_map;
}
void Player::setyMap(int y_map){
    yMap = y_map;
}
void Player::setActive(int active_){
    active = active_;
}
void Player::setPoints(int points_){
    points = points_;
}
string Player::getName(){
    return name;
}
int Player::getyMap(){
    return yMap;
}
int Player::getxMap(){
    return xMap;
}
int Player::getAttack(){
    return attack;
}
int Player::getDefense(){
    return defense;
}
int Player::getHealth(){
    return health;
}
int Player::getLevel(){
    return level;
}
int Player::getPoints(){
    return points;
}
int Player::getNumWeapons(){
    return numWeapons;
}
int Player::getActive(){
    return active;
}
Weapon Player::getActiveWeapon(){
    return weapons[active];
}