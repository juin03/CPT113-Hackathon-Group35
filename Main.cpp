#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "Event.h"
#include "Inventory.h"
#include "LinkedList.h"
#include "Player.h"
#include "Area.h"

using namespace std;

//Markdown
void mapUI(); //Map
void winUI();//Win UI
void loseUI(); //Lose UI
void gameNameUI(); //Display game name UI


int main() {
	
	//INITIALISATION
	ifstream infileDescription;
	infileDescription.open("Description.txt");
	string temp_line;
	//EventList
	LinkedList<Event> eventList;
	/* PLANEWRECK1 EVENT*/
	Event event0;
	event0.event_ID = 0;
	getline(infileDescription, temp_line);
	event0.description = temp_line; 
	
	Event event1;
	event1.event_ID = 1;
	getline(infileDescription, temp_line);
	event1.description = temp_line; 
	
	Event event2;
	event2.event_ID = 2;
	getline(infileDescription, temp_line);
	event2.description = temp_line; 
	
	eventList.appendNode(event0);
	eventList.appendNode(event1);
	eventList.appendNode(event2);

	/* PLANEWRECK2 EVENT*/
	Event event3;
	event3.event_ID = 3;
	getline(infileDescription, temp_line);
	event3.description = temp_line; 

	Event event4;
	event4.event_ID = 4;
	getline(infileDescription, temp_line);
	event4.description = temp_line; 

	Event event5;
	event5.event_ID = 5;
	getline(infileDescription, temp_line);
	event5.description = temp_line; 

	eventList.appendNode(event3);
	eventList.appendNode(event4);
	eventList.appendNode(event5);

	/* RIVER EVENT*/
	Event event6;
	event6.event_ID = 6;
	getline(infileDescription, temp_line);
	event6.description = temp_line; 

	Event event7;
	event7.event_ID = 7;
	getline(infileDescription, temp_line);
	event7.description = temp_line; 
	
	Event event8;
	event8.event_ID = 8;
	getline(infileDescription, temp_line);
	event8.description = temp_line; 
	
	eventList.appendNode(event6);
	eventList.appendNode(event7);
	eventList.appendNode(event8);

	/* FOREST EVENT*/
	Event event9;
	event9.event_ID = 9;
	getline(infileDescription, temp_line);
	event9.description = temp_line; 

	Event event10;
	event10.event_ID = 10;
	getline(infileDescription, temp_line);
	event10.description = temp_line; 
	
	Event event11;
	event11.event_ID = 11;
	getline(infileDescription, temp_line);
	event11.description = temp_line; 
	
	eventList.appendNode(event9);
	eventList.appendNode(event10);
	eventList.appendNode(event11);

	/* VILLAGE EVENT*/
	Event event12;
	event12.event_ID = 12;
	getline(infileDescription, temp_line);
	event12.description = temp_line; 

	Event event13;
	event13.event_ID = 13;
	getline(infileDescription, temp_line);
	event13.description = temp_line; 
	
	Event event14;
	event14.event_ID = 14;
	getline(infileDescription, temp_line);
	event14.description = temp_line; 
	
	eventList.appendNode(event12);
	eventList.appendNode(event13);
	eventList.appendNode(event14);


	//InventoryList
	LinkedList<Inventory> inventoryList;
	/* PLANEWRECK1 ITEM*/
	Inventory item2;
	item2.item_ID=2;
	item2.item_message = "\nYou got the Teddy Bear!\n";
	item2.item_name = "Teddy";
	/* PLANEWRECK2 ITEM*/
	Inventory item5;
	item5.item_ID=5;
	item5.item_message = "\nYou got an axe!\n";
	item5.item_name = "Axe";
	/* FOREST ITEM */
	Inventory item11;
	item11.item_ID=11;
	item11.item_message = "\nPlanks could be used to build a boat!\n";
	item11.item_name = "Planks";


	//Object Initialization
	Player player;
	EmptyGround ground;
	PlaneWreck1 wreck1;
	PlaneWreck2 wreck2;
	River river;
	Forest forest;
	Village village;

	//Set area_ID for each area
	ground.setarea_ID(0);
	wreck1.setarea_ID(1);
	wreck2.setarea_ID(2);
	river.setarea_ID(3);
	forest.setarea_ID(4);
	village.setarea_ID(5);

	//Random seed generator
	unsigned int seed = time(NULL);
	srand(seed);
	
	//Game Title
//	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
//	cout << "*                               *\n";
//	cout << "*      THE VANISHED VOYAGE      *\n";
//	cout << "*                               *\n";
//	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n" << endl;
	gameNameUI();
		
	//Dashboard to choose new game, load game or quit.
	cout << "1. New Game" << endl;
	cout << "2. Load Game" << endl;
	cout << "Enter any key to Quit Game" << endl;
	int winCode; //Special code for not entering loseUI();
	int area;
	int dashboard;
	cin >> dashboard;

	switch(dashboard) {
		case 2: {
			//load previous game
			ifstream infileHP, infileArea_ID, infileItem_ID;
			infileHP.open("HP.txt");
			int temp_HP=0;
			infileHP >> temp_HP;
			player.setLoadHP(temp_HP);
			infileHP.close();
			
			infileArea_ID.open("Area.txt");			
			infileArea_ID >> area;
			infileArea_ID.close();
			
			infileItem_ID.open("Item.txt");
			while(!infileItem_ID.eof()){
				int temp_Item_ID;
				infileItem_ID >> temp_Item_ID;
				switch(temp_Item_ID){
					case 2:{
						if(!inventoryList.itemExist(temp_Item_ID))
						inventoryList.appendNode(item2);
						break;
					}
					case 5:{
						if(!inventoryList.itemExist(temp_Item_ID))
						inventoryList.appendNode(item5);
						break;
					}
					case 11:{
						if(!inventoryList.itemExist(temp_Item_ID))
						inventoryList.appendNode(item11);
						break;
					}
				}
				eventList.deleteEvent(temp_Item_ID);
			}
			infileItem_ID.close();			
		}
		case 1: {
			//Start a new game
			mapUI();
			if(dashboard==1){
				ofstream outfile;
				outfile.open("Item.txt", ofstream::trunc);
				outfile.close();
				area=0; //default area=0;
				cout << "\nIt was on Christmas eve. You were on your way home after a long year working abroad to celebrate Christmas with your family. The plane had been en route to a bustling metropolis, carrying people from all walks of life. It was supposed to be a journey full of anticipation where people are excited to be reunited with their friends and families, but fate had other plans...You awoke with a sharp pain in your head, with confusion surrounding you as to why you were lying on the ground in the middle of a forest. Then, the sudden realisation hit you, your plane has crashed. With a strong determination to meet your beloved family, you must find a way to survive and escape this forest." << endl;	
			}
			
			//Officially Start Game
			int matchID;
			do {
				switch(area) {
					//EmptyGround
					case 0: {
						cout << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
						cout << "EMPTY GROUND\n" << endl;
						getline(infileDescription, temp_line);
						cout << temp_line << endl; 
						cout << "\nHP: " << player.getHP() << endl;
						cout << "INVENTORY: ";
						inventoryList.traverseInventory();
						cout << "-------------------------------------------------------------------------------------------------------";
						area = ground.choose(ground);
						break;
					}
		
					//PlaneWreck1
					case 1: {
						cout << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
						cout << "PLANEWRECK 1 AREA\n" << endl;
						matchID = rand()%3;
						if(inventoryList.itemExist(matchID)) {
							matchID = matchID-2;
						}
						if(matchID==2) {
							inventoryList.appendNode(item2);
							//Write item_ID into the file
							ofstream outfileItem_ID;
							outfileItem_ID.open("Item.txt", ios::app);
							outfileItem_ID << 2 << endl;
							outfileItem_ID.close();
							wreck1.event(matchID,eventList,inventoryList); //Call EVENT3
//							inventoryList.traverseInventory();
							cout << "\nHP: " << player.getHP() << endl;
							cout << "INVENTORY: ";
							inventoryList.traverseInventory();
							cout << "-------------------------------------------------------------------------------------------------------";
							eventList.deleteEvent(2);
						} else if(matchID==1) {
							player.setHP(20);
							wreck1.event(matchID,eventList,inventoryList);
							cout << "\nHP + 20\n";
							cout << "\nHP: " << player.getHP() << endl;
							cout << "INVENTORY: ";
							inventoryList.traverseInventory();
							cout << "-------------------------------------------------------------------------------------------------------";
						} else {
							wreck1.event(matchID,eventList,inventoryList); //Call EVENT1
							cout << "\nHP: " << player.getHP() << endl;
							cout << "INVENTORY: ";
							inventoryList.traverseInventory();
							cout << "-------------------------------------------------------------------------------------------------------";
						}
		
						if(player.getHP()>0) {
							area = wreck1.choose(wreck1); //Choose next area
						}
						break;
					}
		
					//PlaneWreck2
					case 2: {
						cout << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
						cout << "PLANEWRECK 2 AREA\n" << endl;
						matchID = (rand()%3)+3;
						if(inventoryList.itemExist(matchID)) {
							matchID = matchID-2;
						}
						if(matchID==(2+3)) {
							inventoryList.appendNode(item5);
							//Write item_ID into the file
							ofstream outfileItem_ID;
							outfileItem_ID.open("Item.txt", ios::app);
							outfileItem_ID << 5 << endl;
							outfileItem_ID.close();
							wreck2.event(matchID,eventList,inventoryList);
//							inventoryList.traverseInventory();
							cout << "\nHP: " << player.getHP() << endl;
							cout << "INVENTORY: ";
							inventoryList.traverseInventory();
							cout << "-------------------------------------------------------------------------------------------------------";
							eventList.deleteEvent(5);
						} else if (matchID==(2+3-1)) {
							wreck2.event(matchID,eventList,inventoryList);
							cout << "\nHP: " << player.getHP() << endl;
							cout << "INVENTORY: ";
							inventoryList.traverseInventory();
							cout << "-------------------------------------------------------------------------------------------------------\n";
							cout << "Would you like to read the letter? (y/n)\n";
							char choice;
							cin >> choice;
							if (choice == 'y' || choice == 'Y'){
								cout << "\n--------------------------------------------------------------------------------\n";
								cout << "| Hey Marie,                                                                   |\n";
								cout << "|                                                                              |\n";
								cout << "| sorry I couldn't have been home as much these few days, it's a high season   |\n";
								cout << "| for people to fly and we are a bit understaffed. I promise I'll make it up   |\n";
								cout << "| to you when I reach home, wait for me ok? How's our little girl Carol doing? |\n";
								cout << "| Be sure to buy her lots of toys yeah? Kids her age would LOVE to play with   |\n";
								cout << "| toys, especially TEDDY BEARS. Anyways, be sure to keep yourselves warm and   |\n";
								cout << "| healthy, don't forget to water the plants too! I'll be home before you even  |\n";
								cout << "| know it.                                                                     |\n";
								cout << "|                                                                              |\n";
								cout << "|                                                                              |\n";
								cout << "|                                                                              |\n";
								cout << "|                                                              Sincerely,      |\n";
								cout << "|                                                              Jason           |\n";
								cout << "--------------------------------------------------------------------------------\n";

							}
							else{
								cout << "\nYou decided not to read the letter.";
								cout << "\n-------------------------------------------------------------------------------------------------------";
							}
							
							
						}
						else{
							wreck2.event(matchID,eventList,inventoryList);
							cout << "\nHP: " << player.getHP() << endl;
							cout << "INVENTORY: ";
							inventoryList.traverseInventory();
							cout << "-------------------------------------------------------------------------------------------------------";
						}
		
						if (player.getHP()>0) {
							area = wreck2.choose(wreck2);//Choose next area
						}
						break;
					}
		
					//River
					case 3: {
						cout << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
						cout << "RIVER AREA\n" << endl;
						matchID = (rand()%3)+3+3;
						if(matchID==(2+3+3)) {
							if(inventoryList.itemExist(11)) {
								cout << "You noticed you can build a boat using the planks in your inventory, would you like to build a boat? (y/n)" << endl;
								char choice;
								cin>>choice;
								if (choice == 'y'|| choice=='Y'){
									cout << "With the knowledge you have, you start building a small boat that can fit yourself. Using planks and other natural resources, you successfully built a boat and sailed away into civilization.\n" << endl;
									eventList.deleteEvent(8);
									inventoryList.deleteItem(8);
									winUI();
								
									ofstream outfile;
									outfile.open("Item.txt", ofstream::trunc);
									outfile.close();
									
									outfile.open("HP.txt", ofstream::trunc);
									outfile.close();
									
									outfile.open("Area.txt", ofstream::trunc);
									outfile.close();
									area=-1;
									player.setHP(-50000);
									winCode =1; //Code not to enter loseUI()
								}
								else{
									cout << "You decided to save your energy and not build a boat." << endl;
								}
							
							} else {
								river.event(matchID, eventList, inventoryList);
								cout << "\nHP: " << player.getHP() << endl;
								cout << "INVENTORY: ";
								inventoryList.traverseInventory();
								cout << "\n-------------------------------------------------------------------------------------------------------";
							}
						} else if(matchID==(2+3+3-1)) {
							player.setHP(10);
							river.event(matchID,eventList,inventoryList);
							cout << "\nHP + 10\n";
							cout << "\nHP: " << player.getHP() << endl;
							cout << "INVENTORY: ";
							inventoryList.traverseInventory();
							cout << "\n-------------------------------------------------------------------------------------------------------";
						} else {
							river.event(matchID,eventList,inventoryList); //Call event1
							cout << "\nHP: " << player.getHP() << endl;
							cout << "INVENTORY: ";
							inventoryList.traverseInventory();
							cout << "\n-------------------------------------------------------------------------------------------------------";
						}
						if (player.getHP()>0 && winCode	!= 1) {
							area = river.choose(river);
						}
						break;
					}
		
					//Forest
					case 4: {
						cout << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
						cout << "FOREST AREA\n" << endl;
						matchID = (rand()%3)+3+3+3;
						if(inventoryList.itemExist(matchID)) {
							matchID = matchID-2;
						}
						if(matchID==(2+3+3+3)) {
							if (inventoryList.itemExist(5)) {
								forest.event(matchID,eventList,inventoryList); //Call EVENT3
								cout << "\nDo you want to use the axe to chop the tree down? (y/n)\n";
								char choice;
								cin >> choice;
								
								if(choice == 'y' || choice == 'Y'){
									inventoryList.appendNode(item11);
									//Write item_ID into the file
									ofstream outfileItem_ID;
									outfileItem_ID.open("Item.txt", ios::app);
									outfileItem_ID << 11 << endl;
									outfileItem_ID.close();
									eventList.deleteEvent(11);
									cout << "\nYou sucessfully used the axe to chop down the tree and obtained planks!";
									cout << "\nHP: " << player.getHP() << endl;
									cout << "INVENTORY: ";
									inventoryList.traverseInventory();	
									cout << "\n-------------------------------------------------------------------------------------------------------";
								}
								else{
									cout << "You decided not to chop down the tree.";
									cout << "\n-------------------------------------------------------------------------------------------------------";
								}
							} else {
								cout << "There are many trees here, perhaps I could use a tool to chop it down...." << endl;
								cout << "\nHP: " << player.getHP() << endl;
								cout << "INVENTORY: ";
								inventoryList.traverseInventory();								
								cout << "-------------------------------------------------------------------------------------------------------";
							}
						} else if(matchID==(2+3+3+3-1)) {
							player.setHP(-20);
							forest.event(matchID,eventList,inventoryList);
							cout << "\nHP - 20\n";
							cout << "\nHP: " << player.getHP() << endl;
							cout << "INVENTORY: ";
							inventoryList.traverseInventory();
							cout << "-------------------------------------------------------------------------------------------------------";
						} else {
							forest.event(matchID,eventList,inventoryList); //Call EVENT1
							cout << "\nHP: " << player.getHP() << endl;
							cout << "INVENTORY: ";
							inventoryList.traverseInventory();
							cout << "-------------------------------------------------------------------------------------------------------";
						}
		
						if(player.getHP()>0) {
							area = forest.choose(forest);
						}
						break;
					}
		
					//Village
					case 5: {
						cout << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
						cout << "VILLAGE AREA\n" << endl;
						matchID = (rand()%3)+3+3+3+3;
						if (matchID==(2+3+3+3+3)) {
							if(inventoryList.itemExist(2)) {
								cout << "One of the children from the village looks at the teddy bear in your hands with eager eyes. \nWould you like to give it to her? (y/n)" << endl;
								char choice;
								cin>>choice;
								if (choice == 'y'|| choice=='Y'){
									cout << "You decided that the best course of action is to give it to her. After presenting the child with the teddy bear, the father of the child gives you a wireless radio in exchange for your kind gesture. You used the radio to contact help and successfully escaped into civilisation." << endl;
									inventoryList.deleteItem(2);
									eventList.deleteEvent(14);
									winUI();
									ofstream outfile;
									outfile.open("Item.txt", ofstream::trunc);
									outfile.close();
									
									outfile.open("HP.txt", ofstream::trunc);
									outfile.close();
									
									outfile.open("Area.txt", ofstream::trunc);
									outfile.close();
									area = -1;//end switch
									player.setHP(-500000);
									winCode = 1;
							
								}
								else{
									cout << "She feels sad towards your actions.";
								}
								
							} else {
								cout << "You are not welcomed by the villagers." << endl;
							}
						} else if(matchID==(2+3+3+3+3-1)) {
							player.setHP(-10);
							village.event(matchID,eventList,inventoryList);
							cout << "\nHP - 10\n";
							cout << "\nHP: " << player.getHP() << endl;
							cout << "INVENTORY: ";
							inventoryList.traverseInventory();
							cout << "-------------------------------------------------------------------------------------------------------";
						} else {
							village.event(matchID,eventList,inventoryList); //Call event1
							cout << "\nHP: " << player.getHP() << endl;
							cout << "INVENTORY: ";
							inventoryList.traverseInventory();
							cout << "-------------------------------------------------------------------------------------------------------";
						}
						if (player.getHP()>0) {
							area = village.choose(village);
						}
						break;
					}
					case -1:
					default:
						break;
				}
				//Write player.getHP() into the file
				ofstream outfileHP;
				outfileHP.open("HP.txt");
				outfileHP<<player.getHP();
				outfileHP.close();
			} while(area!=-1 && player.getHP()>0);			
			break;
		}

		case 3:
		default:
			return 0;
	}
	if(player.getHP()<=0 && winCode != 1){
		loseUI();
	}
	return 0;
}

void mapUI(){
	cout << "                                      ***************                                               " << endl;
	cout << "                                     *               *                                              " << endl;
	cout << "                                     *               *                                              " << endl;
	cout << "                                     * PLANE WRECK 1 *                                              " << endl;
	cout << "                                     *               *                                              " << endl;
	cout << "                                     *               *                                              " << endl;
	cout << "                                      ***************                                               " << endl;
	cout << "                                             |                                                      " << endl;
	cout << "                                             |                                                      " << endl;
	cout << "                                             |                                                      " << endl;
	cout << "                                             |                                                      " << endl;
    cout << "    ***************                   ***************                   ***************             " << endl;
	cout << "   *               *                 *               *                 *               *            " << endl;
	cout << "   *               *                 *               *                 *               *            " << endl;
	cout << "   *     RIVER     * --------------- *  EMPTYGROUND  * --------------- * PLANE WRECK 2 *            " << endl;
	cout << "   *               *                 *               *                 *               *            " << endl;
	cout << "   *               *                 *               *                 *               *            " << endl;
	cout << "    ***************                   ***************                   ***************             " << endl;
	cout << "                                             |                                 |                    " << endl;
	cout << "                                             |                                 |                    " << endl;
	cout << "                                             |                                 |                    " << endl;
	cout << "                                             |                                 |                    " << endl;
	cout << "                                      ***************                   ***************             " << endl;
	cout << "                                     *               *                 *               *            " << endl;
	cout << "                                     *               *                 *               *            " << endl;
	cout << "                                     *     FOREST    * --------------- *    VILLAGE    *            " << endl;
	cout << "                                     *               *                 *               *            " << endl;
	cout << "                                     *               *                 *               *            " << endl;
	cout << "                                      ***************                   ***************             " << endl;
}

void loseUI(){
	cout << endl;
	cout << "  ________                        _______                    " << endl;
    cout << " /  _____/_____    _____   ____   \\   _  \\___  __ ___________  " << endl;
    cout << "/   \\  ___\\__  \\  /     \\_/ __ \\  /  /_\\  \\  \\/ // __ \\_  __ \\ " << endl;
    cout << "\\    \\_\\  \\/ __ \\|  Y Y  \\  ___/  \\  \\_/   \\   /\\  ___/|  | \\/" << endl;
    cout << " \\______  (____  /__|_|  /\\___  >  \\_____  /\\_/  \\___  >__|   " << endl;
    cout << "        \\/     \\/      \\/     \\/         \\/          \\/        " << endl;
}

void winUI(){
	cout << "_____.___.               __      __.__        " << endl;
    cout << "\\__  |   | ____  __ __  /  \\    /  \\__| ____  " << endl;
    cout << " /   |   |/  _ \\|  |  \\ \\   \\/\\/   /  |/    \\ " << endl;
    cout << " \\____   (  <_> )  |  /  \\        /|  |   |  \\" << endl;
    cout << " / ______|\\____/|____/    \\__/\\  / |__|___|  /" << endl;
    cout << " \\/                            \\/          \\/ " << endl;
}

void gameNameUI(){
	cout << "___________.__             ____   ____             .__       .__               .___ ____   ____                                  " << endl;
    cout << "\\__    ___/|  |__   ____   \\   \\ /   /____    ____ |__| _____|  |__   ____   __| _/ \\   \\ /   /___ ___.__._____     ____   ____  " << endl;
    cout << "  |    |   |  |  \\_/ __ \\   \\   Y   /\\__  \\  /    \\|  |/  ___/  |  \\_/ __ \\ / __ |   \\   Y   /  _ <   |  |\\__  \\   / ___\\_/ __ \\ " << endl;
    cout << "  |    |   |   Y  \\  ___/    \\     /  / __ \\|   |  \\  |\\___ \\|   Y  \\  ___// /_/ |    \\     (  <_> )___  | / __ \\_/ /_/  >  ___/ " << endl;
    cout << "  |____|   |___|  /\\___  >    \\___/  (____  /___|  /__/____  >___|  /\\___  >____ |     \\___/ \\____// ____|(____  /\\___  / \\___  >" << endl;
    cout << "                \\/     \\/                 \\/     \\/        \\/     \\/     \\/     \\/                 \\/          \\/_____/      \\/" << endl;	
}