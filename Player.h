#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Weapon.h"
#ifndef PLAYER_H
#define PLAYER_H
using namespace std;

class Player{
    private:
    //positions on map
    int xMap;
    int yMap;
    //player attributes
    string name;// name of player
    int attack; // players strength
    int defense; // players defense
    int health; // players health
    int level; // player level
    int active;// index of the active weapon
    int points; // player's experience points
    int numWeapons;// number of player weapons
    
    public:
    // constructors
    Weapon weapons[20];// weapons
    Player();
    Player(string name_);
    
    // setters
    void setPosition(int x, int y);//sets the players position on map
    void setAttack(int attack_);// this sets the player's attack
    void setDefense(int defense_);// this sets the player's defense
    void setName(string name_);// sets the players name
    void setHealth(int health_);//sets the players health
    void setLevel(int level_);//sets the players level
    void setActive(int active_);// sets the index of the active weapon
    void setNumWeapons(int num);// sets the number of weapons the user has
    void addWeapon(Weapon x);// adds a weapon to the weapons vector
    void setxMap(int x_map);// set x position
    void setyMap(int y_map);// set x position
    void setPoints(int points_); // sets the players points
    // getters
    string getName();
    int getyMap();
    int getxMap();
    int getAttack();
    int getDefense();
    int getHealth();
    int getLevel();
    int getPoints();
    int getNumWeapons();
    int getActive();
    Weapon getActiveWeapon();
};

#endif