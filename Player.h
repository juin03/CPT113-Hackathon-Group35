#ifndef PLAYER_H
#define PLAYER_H

/*
Player
*/
class Player {
	private:
		int HP;

	public:
		//Constructor
		Player();
		
		//Mutator
		void setHP(int change);
		
		void setLoadHP(int loadHP);

		//Accessor
		int getHP();
};

#endif