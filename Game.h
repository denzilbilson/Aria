#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Weapon.h"
#include "Player.h"
#include "Monster.h"
#ifndef GAME_H
#define GAME_H
using namespace std;

class Game{
    private:
    Player host;
    string temp;
    int choice;
    Weapon allWeapons[15]; // array of all weapons
    Monster opponents[45];
    Monster allMonster[20];
    Weapon activeWeapon;
    string worldMap[11][15];
    public:
    Game();
    void mainMenu();
    void newGame();
    void viewMap();
    void showMap();
    void intializeWeapons();
    void intializeMap();
    void showWeapons();
    void showCredits();
    void viewCharacters();
    void randWeapon();
    void settingsMenu();
    void fightMenu(int index);
    void newWeapon(int x);
    void gameMenu();
    void travelMenu();
    void miniMap(int x, int y);
    void changeWeapon();
    void randomizeMonsters();
    void shop();
    void saveGame();
    void checkMonsters();
    void upgradeStats();
};

#endif