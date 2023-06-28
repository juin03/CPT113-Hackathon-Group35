#include "Area.h"
#include <iostream>
#include <fstream>
using namespace std;

/*
Area
*/
	//Mutator
	void Area::setarea_ID(int area_ID) {
		this->area_ID = area_ID;
	}

	//Accessor
	int Area::getarea_ID() {
		return area_ID;
	}

	//Call event based on matchID
	void Area::event(int matchID,LinkedList<Event> &eventList, LinkedList<Inventory> &inventoryList) {
		eventList.outputEvent(matchID);
		inventoryList.outputItem(matchID);
	}


/*
[0] EmptyGround
*/
	int EmptyGround::choose(EmptyGround &ground) {
		int temp;
		string direction;			
		cout << "\nChoose your direction. North(n), South(s), East(e), West(w), or 'quit' to save and quit." << endl;
		do {
			cin >> direction;
			if(direction=="n") {
				temp=1;
				return temp;
			} else if(direction=="s") {
				temp=4;
				return temp;
			} else if(direction=="e") {
				temp=2;
				return temp;
			} else if(direction=="w") {
				temp=3;
				return temp;
			} else if(direction=="quit") {
				//write the area_ID into file.

				ofstream outfileArea_ID;
				outfileArea_ID.open("Area.txt");
				outfileArea_ID<<ground.getarea_ID();
				return -1;
			} else {
				temp=-1;
				cout << "Unreachable." << endl;
			}
		} while(temp<0 || temp>3);
		return 0;//random return[FOR PROGRAMMER];
	}


/*
[1] PlaneWreck1
*/
	//Choose next area
	int PlaneWreck1::choose(PlaneWreck1 &wreck1) {
		int temp;
		string direction;
		cout << "\nChoose your direction. North(n), South(s), East(e), West(w), or 'quit' to save and quit." << endl;

		do {
			cin >> direction;
			if(direction=="s") {
				temp=0;
				return temp;
			} else if(direction=="quit") {
				//write the area_ID into file.
				ofstream outfileArea_ID;
				outfileArea_ID.open("Area.txt");
				outfileArea_ID<<wreck1.getarea_ID();
				return -1;
			} else {
				temp=-1;
				cout << "Unreachable." << endl;
			}
		} while(temp!=0);
		return 0;//random return[FOR PROGRAMMER];
	}


/*
[2] PlaneWreck2
*/
	//Choose next area
	int PlaneWreck2::choose(PlaneWreck2 &wreck2) {
		int temp;
		string direction;
		cout << "\nChoose your direction. North(n), South(s), East(e), West(w), or 'quit' to save and quit." << endl;

		do {
			cin >> direction;
			if(direction=="s") {
				temp=5;
				return temp;
			} else if(direction=="w") {
				temp=0;
				return temp;
			} else if(direction=="quit") {
				//write the area_ID into file.
				ofstream outfileArea_ID;
				outfileArea_ID.open("Area.txt");
				outfileArea_ID<<wreck2.getarea_ID();
				return -1;
			} else {
				temp=-1;
				cout << "Unreachable." << endl;
			}
		} while(temp!=5 && temp!=0);
		return 0;//random return[FOR PROGRAMMER];
	}


/*
[3] River
*/
	//Choose next area
	int River::choose(River &river) {
		int temp;
		string direction;
		cout << "\nChoose your direction. North(n), South(s), East(e), West(w), or 'quit' to save and quit." << endl;

		do {
			cin >> direction;
			if(direction=="e") {
				temp=0;
				return temp;
			} else if(direction=="quit") {
				//write the area_ID into file.
				ofstream outfileArea_ID;
				outfileArea_ID.open("Area.txt");
				outfileArea_ID<<river.getarea_ID();
				return -1;
			} else {
				temp=-1;
				cout << "Unreachable." << endl;
			}
		} while(temp!=0);
		return 0;//random return[FOR PROGRAMMER];
	}


/*
[4] Forest
*/
	//Choose next area
	int Forest::choose(Forest &forest) {
		int temp;
		string direction;
		cout << "\nChoose your direction. North(n), South(s), East(e), West(w), or 'quit' to save and quit." << endl;

		do {
			cin >> direction;
			if(direction=="n") {
				temp=0;
				return temp;
			} else if(direction=="e") {
				temp=5;
				return temp;
			} else if(direction=="quit") {
				//write the area_ID into file.
				ofstream outfileArea_ID;
				outfileArea_ID.open("Area.txt");
				outfileArea_ID<<forest.getarea_ID();
				outfileArea_ID.close();
				return -1;
			} else {
				temp=-1;
				cout << "Unreachable." << endl;
			}
		} while(temp!=5 && temp!=0);
		return 0;//random return[FOR PROGRAMMER];
	}

/*
[5] Village
*/
	//Choose next area
	int Village::choose(Village &village) {
		int temp;
		string direction;
		cout << "\nChoose your direction. North(n), South(s), East(e), West(w), or 'quit' to save and quit." << endl;

		do {
			cin >> direction;
			if(direction=="n") {
				temp=2;
				return temp;
			} else if(direction=="w") {
				temp=4;
				return temp;
			} else if(direction=="quit") {
				//write the area_ID into file.
				ofstream outfileArea_ID;
				outfileArea_ID.open("Area.txt");
				outfileArea_ID<<village.getarea_ID();
				return -1;
			} else {
				temp=-1;
				cout << "Unreachable." << endl;
			}
		} while(temp!=2 && temp!=4);
		return 0;//random return[FOR PROGRAMMER];
	}