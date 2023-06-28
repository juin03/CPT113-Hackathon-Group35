#include "LinkedList.h"
#include "Event.h"
#include "Inventory.h"

//Event
template <>
void LinkedList<Event>::deleteItem(int matchID) {}
template <>
void LinkedList<Event>::outputItem(int matchID){}
template <>
bool LinkedList<Event>::itemExist(int matchID){return 0;}
template <>
void LinkedList<Event>::traverseInventory(){}

//Item
template <>
void LinkedList<Inventory>::deleteEvent(int matchID){}
template <>
void LinkedList<Inventory>::outputEvent(int matchID){}
template <>
bool LinkedList<Inventory>::eventExist(int matchID){return 0;}


template class LinkedList<Event>;
template class LinkedList<Inventory>;