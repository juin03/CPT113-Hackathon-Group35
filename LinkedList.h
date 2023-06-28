#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <string>
using namespace std;

/*
LinkedList for Event and Inventory
*/
template <class T>
class LinkedList {
	private:
		struct ListNode {
			T data;
			ListNode *next;
		};
	public:
		ListNode *head;
		LinkedList() {
			head=nullptr;
		}

		//appendNode
		void appendNode(T data) {
			ListNode *newNode = nullptr;
			ListNode *nodePtr = head;

			newNode = new ListNode;
			newNode->data = data;
			newNode->next = nullptr;

			if(!head) {
				head = newNode;
			} else {
				while(nodePtr->next) {
					nodePtr = nodePtr->next;
				}
				nodePtr->next = newNode;
			}
		}

		//delete based on event_ID
		void deleteEvent(int matchID) {
			ListNode *nodePtr = head;
			ListNode *previousNode = nullptr;

			if(!head) {
				return;
			}
			if(head->data.event_ID == matchID ) {
				nodePtr=head->next;
				delete head;
				head = nodePtr;
			} else {
				while(nodePtr!=nullptr && nodePtr->data.event_ID != matchID) {
					previousNode = nodePtr;
					nodePtr = nodePtr->next;
				}
				if(nodePtr!=nullptr) {
					previousNode->next = nodePtr->next;
					delete nodePtr;
				}
			}
		}

		//delete based on item_ID
		void deleteItem(int matchID) {
			ListNode *nodePtr = head;
			ListNode *previousNode = nullptr;

			if(!head) {
				return;
			}
			if(head->data.item_ID == matchID ) {
				nodePtr=head->next;
				delete head;
				head = nodePtr;
			} else {
				while(nodePtr!=nullptr && nodePtr->data.item_ID != matchID) {
					previousNode = nodePtr;
					nodePtr = nodePtr->next;
				}
				if(nodePtr!=nullptr) {
					previousNode->next = nodePtr->next;
					delete nodePtr;
				}
			}
		}
		//Output specific node based on event_ID;
		void outputEvent(int matchID) {
			ListNode *nodePtr = head;
			while (nodePtr != nullptr) {
				if(nodePtr->data.event_ID == matchID) {
//					cout << "Event_ID: " << nodePtr->data.event_ID << endl;
					cout << nodePtr->data.description << endl;
				}
				nodePtr = nodePtr->next;
			}
		}

		//Output specific item based on item_ID;
		void outputItem(int matchID) {
			ListNode *nodePtr = head;
			while (nodePtr != nullptr) {
				if(nodePtr->data.item_ID == matchID) {
					cout << nodePtr->data.item_message;
				}
				nodePtr = nodePtr->next;
			}
		}
		
		//Check if EVENT still can be called.
		bool eventExist(int matchID) {
			bool status=0;
			ListNode *nodePtr = head;
			while(nodePtr!=nullptr) {
				if(nodePtr->data.event_ID == matchID) {
					status = 1;
				}
				nodePtr = nodePtr->next;
			}
			return status;
		}

		//Check if item already in inventory
		bool itemExist(int matchID) {
			bool status=0;
			ListNode *nodePtr = head;
			while(nodePtr!=nullptr) {
				if(nodePtr->data.item_ID == matchID) {
					status = 1;
				}
				nodePtr = nodePtr->next;
			}
			return status;
		}

		//Traverse the inventory
		void traverseInventory() {
			ListNode *nodePtr = head;
			while(nodePtr!= nullptr) {
				cout << nodePtr->data.item_name << " ";
				nodePtr = nodePtr->next;
			}
			cout << endl;
		}
};

#endif