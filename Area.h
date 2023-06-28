#ifndef AREA_H
#define AREA_H
#include "Event.h"
#include "Inventory.h"
#include "Linkedlist.h"

/*
Area
*/
class Area {
	private:
		int area_ID;
	public:
		//Mutator
		void setarea_ID(int area_ID);

		//Accessor
		int getarea_ID();

		//Call event based on matchID
		void event(int matchID,LinkedList<Event> &eventList, LinkedList<Inventory> &inventoryList);
};

/*
[0] EmptyGround
NO EVENT.
Direction:
<1> N, PlaneWreck1
<4> S, Forest
<2> E, PlaneWreck2
<3> W, River
*/
class EmptyGround:public Area {
	public:
		int choose(EmptyGround &ground);
};


/*
[1] PlaneWreck1
Event1: Description
Event2:	BUFF - Get some antibiotics (+20 HP)
Event3: Get toys
Direction:
<0> S, EmptyGround
*/
class PlaneWreck1:public Area {
	public:
		//Choose next area
		int choose(PlaneWreck1 &wreck1);
};


/*
[2] PlaneWreck2
Event1:	Descriptions
Event2:	HINT -Villagers like toys
Event3: Get axe
Direction:
<5> S, Village
<0> W, EmptyGround
*/
class PlaneWreck2:public Area {
	public:
		//Choose next area
		int choose(PlaneWreck2 &wreck2);
};


/*
[3] River
Event1: HINT : The river seems quite enuf for a boat
Event2:	BUFF - Fresh water (+10 HP)
Event3: (Use Forest's planks) Build boat - END GAME
Direction:
<0> E, EmptyGround
*/
class River:public Area {
	public:
		//Choose next area
		int choose(River &river);
};


/*
[4] Forest
Event1: HINT - There are so many woods here.
Event2:	DEBUFF - Snake bite (-20HP)
Event3: (Use PlaneWreck2's axe) get planks
Direction:
<0> N, EmptyGround
<5> E, Village
*/
class Forest:public Area {
	public:
		//Choose next area
		int choose(Forest &forest);
};


/*
[5] Village
Event1:	Descriptions - Villagers dont welcome strangers
Event2:	DEBUFF - Stepped on the animal trap (-20HP)
Event3: (Use PlaneWreck1's toys) Receive radio - END GAME
Direction:
<2> N, PlaneWreck2
<4> W, Forest
*/
class Village:public Area {
	public:
		//Choose next area
		int choose(Village &village);
};
#endif