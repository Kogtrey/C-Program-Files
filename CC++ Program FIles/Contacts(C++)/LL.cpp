#include "LL.h"
#include "ContactNode.h"
#include <iostream>
#include <string>

using namespace std;

void LL::InsertFront(ContactNode* cn){
	if(tail == nullptr){
		head = cn;
		tail = cn;
	}
	(*cn).setNextNode(head);
	head = cn;
}
void LL::InsertBack(ContactNode* cn){
	if(head == nullptr){
		head = cn;
		tail = cn;
	}
	ContactNode* temp = tail;
	(*tail).setNextNode(cn);
	tail = cn;
}
void LL::PrintList(){
	for(ContactNode* ptr = head; ; ptr = (*ptr).GetNext()){
		(*ptr).PrintContactNode();
		if(ptr == tail){
			return;
		}
	}
}
LL::LL(){
	head = nullptr;
	tail = nullptr;
}