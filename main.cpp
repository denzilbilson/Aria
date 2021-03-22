#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Weapon.h"
#include "Player.h"
#include "Game.h"
using namespace std;

// Quick compile with: c++ main.cpp Weapon.cpp Monster.cpp Player.cpp Game.cpp -o game

int main(){
    Game game;
    game.mainMenu();
    return 0;
}