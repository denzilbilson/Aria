#include "Game.h"

int split(string sentence, char delimiter, string arr[], int len){
    string temp;
    string compare = string() + delimiter;
    int position = 0;
    if(sentence == ""){
        position = 0;
    }
    else{
        sentence += compare;
        for(int i = 0; i < sentence.length(); i++){
            if(sentence.substr(i,1) != compare){
                temp += sentence.substr(i,1);
            }
            else{
                if(position == (len-1)){
                    position = -1;
                    break;
                }
                else if(temp != ""){
                    arr[position] = temp;
                    position++;
                    temp = "";
                }
            }
        }
    }
    return position;
}
Game::Game(){
    intializeWeapons();
    intializeMap();
    randomizeMonsters();
}
void Game::intializeWeapons(){
    string arr[3];
    ifstream file;
    int x = 0;
    int y = 0;
    file.open("weapons.txt");
    while(getline(file, temp)){
        split(temp, ',', arr, 4);
        allWeapons[x].setName(arr[0]);
        y = stoi(arr[1]);
        allWeapons[x].setAttack(y);
        y = stoi(arr[2]);
        allWeapons[x].setDefense(y);
        x++;
    }
    file.close();
}
void Game::intializeMap(){
    string arr[16];
    ifstream file;
    int y = 0;
    file.open("worldMap.txt");
    while(getline(file, temp)){
         split(temp, ',', arr, 16);
         for(int x = 0; x < 16; x++){    
             worldMap[y][x] = arr[x];
       }
         y++;
     }
     file.close();
}
void Game::showWeapons(){
    for(int i = 0; i < 15; i++){
        cout << "----------------------------" << endl;
        cout << "Name: " << allWeapons[i].getName() << endl;
        cout << "Attack: " << allWeapons[i].getAttack() << endl;
        cout << "Defense: " << allWeapons[i].getDefense() << endl;
        cout << "----------------------------" << endl;
    }
}
void Game::showMap(){
    cout << "-----THE WORLD OF ARIA-----" << endl;
    for(int y = 0; y < 10; y++){
        for(int x = 0; x < 15; x++){
            if(worldMap[y][x] == "w"){
                cout << "~";
            }
            else if(worldMap[y][x] == "L"){
                cout << "#";
            }
            else{
                cout << worldMap[y][x];
            }
            cout << " ";
        }
        cout << endl;
    }
}
void Game::miniMap(int x_map, int y_map){
    for(int j = x_map - 2; j <= x_map + 2; j++){
        if(j < 0 || j >= 10){
            continue;
        }
        for(int i = y_map - 2; i <= y_map + 2; i++){
            if(i < 0 || i >= 15){
                continue;
            }
            if(j == x_map && i == y_map){
                cout << "@ ";
            }
            else if(worldMap[j][i] == "w"){
                cout << "~ ";
            }
            else if(worldMap[j][i] == "L"){
                cout << "# ";
            }
            else{
                cout << worldMap[j][i] << " ";
            }
        }
        cout << endl;
    }
}
void Game::mainMenu(){
    while(true){
        cout << "-------Main Menu-------" << endl;
        cout << "1.Start a New Game" << endl;
        cout << "2.View World Map" << endl;
        cout << "3.View all Weapons" << endl;
        cout << "4.View Saved Games" << endl;
        cout << "5.View Game Credits" << endl;
        cout << "6.Quit" << endl;
        getline(cin,temp);
        if(temp == "1"){
            newGame();
            break;
        }
        else if(temp == "2"){
            showMap();
        }
        else if(temp == "3"){
         showWeapons();
        }
        else if(temp == "4"){
            viewCharacters();
        }
        else if(temp == "5"){
            showCredits();
        }
        else if(temp == "6"){
            break;
        }
        else{
            cout << "Sorry, your input is not valid. Please try again." << endl;
            continue;
        }
    }
    cout << "Thanks for playing, intrepid adventurer!" << endl;
}
void Game::showCredits(){
    ifstream file;
    file.open("credits.txt");
    while(getline(file, temp)){
        cout << temp << endl;
    }
    file.close();
    while(true){
        cout << "Would you like to add your name to the tester list?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        getline(cin, temp);
        if(temp == "1"){
            ofstream file;
            file.open("credits.txt", ios_base::app);
            cout << "Please type your name in: ";
            getline(cin, temp);
            file << "\n" << temp;
            file.close();
            break;
        }
        else if(temp == "2"){
            break;
        }
        else{
            cout << "Your input cannot be understood. Please try again." << endl;
        }
    }
}
void Game::newGame(){
    cout << "Hello Traveler! Welcome to the world of Aria!" << endl;
    cout << "What might your name be?" << endl;
    getline(cin, temp);
    host.setName(temp);
    cout << "Nice to meet you " << host.getName() << "!" << endl;
    cout << "I know your kind. You adventurers want to defeat the monsters" << endl;
    cout << "that plague the once beautiful lands. If you wish to survive," << endl;
    cout << "You must choose a weapon or a potion! You can choose any of the four" << endl;
    cout << "below or try your luck to see if you can receive a LEGENDARY weapon!" << endl;
    while(true){
        cout << "1. Beginner Sword" << endl;
        cout << "2. Beginner Shield" << endl;
        cout << "3. Attack Potion" << endl;
        cout << "4. Defense Potion" << endl;
        cout << "5. The Spirits are on my Side!" << endl;
        getline(cin, temp);
        if(temp == "1" || temp == "2"){
            choice = stoi(temp) - 1;
            cout << "You picked the " << allWeapons[choice].getName() << "!" << endl;
            newWeapon(choice);
            host.addWeapon(allWeapons[choice]);
            host.getActiveWeapon();
            activeWeapon = host.getActiveWeapon();
            cout << "----------------------------" << endl;
            cout << "Name: " << activeWeapon.getName() << endl;
            cout << "Attack: " << activeWeapon.getAttack()  << endl;
            cout << "Defense: " << activeWeapon.getDefense()  << endl;
            cout << "----------------------------" << endl;
            cout << "Go on your way, and defeat all the monsters that stand in your way!" << endl;
            gameMenu();
            break;
        }
        else if(temp == "3"){
            cout << "You drank an Attack Potion!" << endl;
            cout << "Your attack has increased from " << host.getAttack();
            host.setAttack(host.getAttack() + 20);
            cout << " to " << host.getAttack() << endl;
            cout << "Go on your way, and defeat all the monsters that stand in your way!" << endl;
            gameMenu();
            break;
        }
        else if(temp == "4"){
            cout << "You drank an Defense Potion!" << endl;
            cout << "Your defense has increased from " << host.getDefense();
            host.setDefense(host.getDefense() + 20);
            cout << " to " << host.getDefense() << endl;
            cout << "Go on your way, and defeat all the monsters that stand in your way!" << endl;
            gameMenu();
            break;
        }
        else if(temp == "5"){
            srand(time(NULL));
            choice = rand() % 15;
            host.addWeapon(allWeapons[choice]);
            cout << "You picked the " << allWeapons[choice].getName() << "!" << endl;
            cout << "----------------------------" << endl;
            cout << "Name: " << allWeapons[choice].getName() << endl;
            cout << "Attack: " << allWeapons[choice].getAttack() << endl;
            cout << "Defense: " << allWeapons[choice].getDefense() << endl;
            cout << "----------------------------" << endl;
            cout << "Go on, and defeat all the monsters that stand in your way!" << endl;
            gameMenu();
            break;
           
        }
        else{
            cout << "Sorry, this is an invalid input." << endl;
        }
    }
    
}
void Game::gameMenu(){
    while(true){
        if(host.getHealth() <= 0){
            break;
        }
        miniMap(host.getyMap(), host.getxMap());
        cout << host.getName() << endl;
        cout << "Your health is " << host.getHealth();
        cout << ", your attack is " << host.getAttack();
        cout << ", and your defense is " << host.getDefense() << "." << endl;
        if(host.getNumWeapons() > 0){
            cout << "Your current weapon is a " << host.getActiveWeapon().getName() << "." << endl;
            cout << "Its attack is " << host.getActiveWeapon().getAttack();
            cout << ", and its defense is " << host.getActiveWeapon().getDefense() << "." << endl;
        }
        cout << "1. Travel" << endl;
        cout << "2. Change Weapon" << endl;
        cout << "3. Go to Shop" << endl;
        cout << "4. Upgrade Stats" << endl;
        cout << "5. Save Game" << endl;
        cout << "6. Quit" << endl;
        getline(cin, temp);
        if(temp == "1"){
            travelMenu();
        }
        else if(temp == "2"){
            changeWeapon();
        }
        else if(temp == "3"){
            shop();
        }
        else if(temp == "4"){
            upgradeStats();
        }
        else if(temp == "5"){
            saveGame();
        }
        else if(temp == "6"){
            break;
        }
        else{
            cout << "Sorry, your input is not valid. Please try again." << endl;
            continue;
        }
    }
}
void Game::newWeapon(int x){
    activeWeapon.setName(allWeapons[x].getName());
    activeWeapon.setAttack(allWeapons[x].getAttack());
    activeWeapon.setDefense(allWeapons[x].getDefense());
}
void Game::travelMenu(){
    while(true){
        checkMonsters();
        if(host.getHealth() <= 0){
            break;
        }
        miniMap(host.getyMap(), host.getxMap());
        cout << "1.Up" << endl;
        cout << "2.Down" << endl;
        cout << "3.Left" << endl;
        cout << "4.Right" << endl;
        cout << "5.Back to Game Menu" << endl;
        getline(cin, temp);
        if(temp == "1"){
            if(host.getyMap() - 1 < 0){
                cout << "This move is invalid. Try again." << endl;
                continue;
            }
            host.setyMap(host.getyMap() - 1);
        }
        else if(temp == "2"){
            if(host.getyMap() + 1 >= 10){
                cout << "This move is invalid. Try again." << endl;
                continue;
            }
            host.setyMap(host.getyMap() + 1);
        }
        else if(temp == "3"){
            if(host.getxMap() - 1 < 0){
                cout << "This move is invalid. Try again." << endl;
                continue;
            }
                host.setxMap(host.getxMap() - 1);
        }
        else if(temp == "4"){
            if(host.getxMap() + 1 >= 15){
                cout << "This move is invalid. Try again." << endl;
                continue;
            }
                host.setxMap(host.getxMap() + 1);
        }
        else if(temp == "5"){
            break;
        }
        else{
            cout << "Sorry, your input is not valid. Please try again." << endl;
            continue;
        }
    }
}
void Game::randomizeMonsters(){
    ifstream file;
    file.open("monster.txt");
    int i = 0;
    int x = 0;
    int y = 0;
    int check;
    string arr[5];
    while(getline(file, temp)){
        split(temp,',', arr, 5);
        allMonster[i].setName(arr[0]);
        allMonster[i].setAttack(stoi(arr[1]));
        allMonster[i].setDefense(stoi(arr[2]));
        allMonster[i].setHealth(stoi(arr[3]));
        i++;
    }
    srand(time(NULL));
    for(int j = 0; j < 45; j++){
        check = 0;
        choice = rand() % 20;
        x = rand() % 15;
        y = rand() % 10;
        for(int z = 0; z < j; z++){
            if(x == opponents[z].getXPos() && y == opponents[z].getYPos()){
                check = -1;
                break;
            }
        }
        if(worldMap[y][x] == "S" || check == -1){
            j--;
            continue;
        }
        opponents[j] = allMonster[choice];
        opponents[j].setXPos(x);
        opponents[j].setYPos(y);
    }
}
void Game::changeWeapon(){
    cout << "You have " << host.getNumWeapons() << " weapons."<< endl;
    for(int i = 0; i < host.getNumWeapons(); i++){
        cout << "----------------------------" << endl;
        cout << i << ". " << "Name: " << host.weapons[i].getName() << endl;
        cout << " " << "Attack: " << host.weapons[i].getAttack() << endl;
        cout << " " << "Defense: " << host.weapons[i].getDefense() << endl;
        cout << "----------------------------" << endl;
    }
    while(true){
        if(host.getNumWeapons() == 0){
               break;
        }
        cout << "Which weapon would you like to select?" << endl;
        getline(cin, temp);
        choice = stoi(temp);
        if(choice >= host.getNumWeapons() || choice < 0){
            cout << "This is an invalid input" << endl;
            continue;
        }
        host.setActive(choice);
        break;
    }
}
void Game::shop(){
    cout << "Welcome to the Game Shop!" << endl;
    cout << "Here we sell weapons of all kinds. Pick any thing that fits your fancy!" << endl;
    cout << "All weapons are worth 30 EXP" << endl;
    for(int i = 0; i < 15; i++){
        cout << "    " << "----------------------------" << endl;
        cout << i << ". " << " Name: " << allWeapons[i].getName() << endl;
        cout << "    " << "Attack: " << allWeapons[i].getAttack() << endl;
        cout << "    " << "Defense: " << allWeapons[i].getDefense() << endl;
        cout << "    " << "----------------------------" << endl; 
    }
    while(true){
        cout << "Which weapon do you wish to buy?" << endl;
        getline(cin, temp);
        choice = stoi(temp);
        if(choice < 15 && choice >= 1){
            break;
        }
        cout << "Your input is invalid, try again." << endl;
    }
    if(host.getPoints() < 30){
        cout << "Sorry, you do not have enough points to buy this." << endl;
    }
    else{
        host.addWeapon(allWeapons[choice]);
            cout << "You picked the " << allWeapons[choice].getName() << "!" << endl;
            cout << "----------------------------" << endl;
            cout << "Name: " << allWeapons[choice].getName() << endl;
            cout << "Attack: " << allWeapons[choice].getAttack() << endl;
            cout << "Defense: " << allWeapons[choice].getDefense() << endl;
            cout << "----------------------------" << endl;
            host.setPoints(host.getPoints() - 30);
    }
}
void Game::saveGame(){
    ofstream file;
    file.open("saveGame.txt", ios_base::app);
    file << to_string(host.getNumWeapons()) << "," << to_string(host.getxMap()) << "," << to_string(host.getyMap()) << "," << host.getName() << ",";
    file << to_string(host.getAttack()) << "," << to_string(host.getDefense()) << ",";
    file  << to_string(host.getHealth()) << "," << to_string(host.getLevel()) << ",";
    file << to_string(host.getPoints()) << "," << to_string(host.getActive()) << ",";
    for(int i = 0; i < host.getNumWeapons(); i++){
        file << host.weapons[i].getName() << "," << to_string(host.weapons[i].getAttack()) << "," << to_string(host.weapons[i].getDefense()) << ",";
    }
    file  << "\n";
    cout << "Your game has been saved!" << endl;
    file.close();
    
}
void Game::viewCharacters(){
    ifstream file;
    file.open("saveGame.txt");
    string arr[56];
    int num = 0;
    while(getline(file, temp)){
        split(temp,',', arr, 56);
        cout << num << "." << endl;
        cout << "\t" << "-------------------------" << endl;
        cout << "\t" << "Name: "<< arr[3] << endl;
        cout << "\t" << "Attack: " << arr[4] << endl;
        cout << "\t" << "Defense: " << arr[5] << endl;
        cout << "\t" << "Health: " << arr[6] << endl;
        cout << "\t" << "Level: " << arr[7] << endl;
        cout << "\t" << "EXP: " << arr[8] << endl;
        num++;
        if(stoi(arr[0]) == 0){
            cout << "-------------------------" << endl;
            continue;
        }
        cout << "\t" << "Weapons" << endl;
        for(int i = 0; i < stoi(arr[0]); i++){
            cout << "\t" << "\t" << "Name: "<< arr[(10 + (3*i))] << endl;
            cout << "\t" << "\t" << "Attack: " << arr[(11 + (3*i))] << endl;
            cout << "\t" << "\t" << "Defense: " << arr[(12 + (3*i))] << endl;
            cout << endl;
        }
        cout << "\t" << "-------------------------" << endl;
    }
    while(true){
        int escape = 0;
        cout << "Would you like to play a saved game?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        getline(cin, temp);
        if(temp == "1"){
            while(true){
                cout << "Which saved game do you want to play?" << endl;
                getline(cin, temp);
                choice = stoi(temp);
                if(choice > num || choice < 0){
                    cout << "Sorry, this is an invalid input." << endl;
                    continue;
                }
                escape = 1;
                host.setName(arr[3]);
                host.setAttack(stoi(arr[4]));
                host.setDefense(stoi(arr[5]));
                host.setHealth(stoi(arr[6]));
                host.setLevel(stoi(arr[7]));
                host.setPoints(stoi(arr[8]));
                host.setActive(stoi(arr[9]));
                host.setNumWeapons(stoi(arr[0]));
                host.setyMap(stoi(arr[2]));
                host.setxMap(stoi(arr[1]));
                for(int i = 0; i < host.getNumWeapons(); i++){
                    host.weapons[i].setName(arr[(10 + (3*i))]);
                    host.weapons[i].setAttack(stoi(arr[(11 + (3*i))]));
                    host.weapons[i].setDefense(stoi(arr[(12 + (3*i))]));
                }
                gameMenu();
                break;
            }
        }
        else if(temp == "2"){
            break;
        }
        else{
            cout << "Sorry, this input is invalid." << endl;
        }
        if(escape == 1){
            break;
        }
    }
}
void Game::checkMonsters(){
    for(int i = 0; i < 45; i++){
        if(host.getxMap() == opponents[i].getXPos() && host.getyMap() == opponents[i].getYPos() && opponents[i].getHealth() > 0){
            cout << "You have encountered an enemy!" << endl;
            fightMenu(i);
        }
    }
}
void Game::fightMenu(int index){
    int health = host.getHealth();
    int attack = 0;
    while(true){
        cout << "Monster: " << opponents[index].getName() << endl;
        cout << "Health: " << opponents[index].getHealth() << endl;
        cout << "Attack: " << opponents[index].getAttack() << endl;
        cout << "Defense: " << opponents[index].getDefense() << endl;
        cout << "1. Attack!" << endl;
        cout << "2. Run" << endl;
        getline(cin, temp);
        if(temp == "1"){
            attack = host.getAttack() + host.getActiveWeapon().getAttack();
            opponents[index].setHealth(opponents[index].getHealth() - attack);
            cout << "You dealt the " << opponents[index].getName() << " " << attack << " damage!" << endl;
            if(opponents[index].getHealth() <= 0){
                cout << "You have defeated the " << opponents[index].getName() << "!" << endl;
                host.setPoints(host.getPoints() + 10);
                cout << "You have received 10 exp points!" << endl;
                break;
            }
            attack = opponents[index].getAttack();
            host.setHealth(host.getHealth() - attack);
            cout << "You have suffered " << attack << " damage!" << endl;
            if(host.getHealth() <= 0){
                cout << "You have died." << endl;
                break;
            }
        }
        else if(temp == "2"){
            break;
        }
        else{
            cout << "Your input is incorrect. Try again." << endl;
        }
    }
}
void Game::upgradeStats(){
    if(host.getPoints() >= 10){
        while(true){
            cout << "1.Health: " << host.getHealth() << endl;
            cout << "2.Attack: " << host.getAttack() << endl;
            cout << "3.Defense: " << host.getDefense() << endl;
            cout << "Which stat do you want to increase?" << endl;
            getline(cin, temp);
            if(temp == "1"){
                host.setHealth(host.getHealth() + 10);
                host.setPoints(host.getPoints() - 10);
                cout << "Your health is now " << host.getHealth() << endl;
                break;
            }
            else if(temp == "2"){
                host.setAttack(host.getAttack() + 10);
                host.setPoints(host.getPoints() - 10);
                cout << "Your attack is now " << host.getAttack() << endl;  
                break;
            }
            else if(temp == "3"){
                host.setDefense(host.getDefense() + 10);
                host.setPoints(host.getPoints() - 10);
                cout << "Your defense is now " << host.getDefense() << endl;
                break;
            }
            else{
                cout << "This is an invalid input. Please try again." << endl;
            }
            
        }
    }
    else{
        cout << "You do not have enough points to upgrade your stats" << endl;
    }    
}