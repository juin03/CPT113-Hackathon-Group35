#include "Player.h"
#include <iostream>
using namespace std;

/*
Player
*/

//Constructor
Player::Player() {
	HP = 50;//default 50HP
}

//Mutator
void Player::setHP(int change) {
	HP = HP + change;//Increase or decrease HP
}

void Player::setLoadHP(int loadHP){
	HP = loadHP;
}

//Accessor
int Player::getHP() {
	return HP;
}
