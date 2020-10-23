#include "ContactNode.h"
#include <iostream>
#include <string>

using namespace std;
void ContactNode::InsertAfter(ContactNode* NextNodePtr){
	this->nextNodePtr = NextNodePtr;
}
string ContactNode::GetName(){
	return contactName;
}
string ContactNode::GetPhoneNumber(){
	return contactPhoneNum;
}
void ContactNode::setNextNode(ContactNode* nextNode){
	this->nextNodePtr = nextNode; 
}
ContactNode* ContactNode::GetNext(){
	return nextNodePtr;
}
void ContactNode::PrintContactNode(){
	cout << "Name: " << contactName << endl 
		<< "Phone number: " << contactPhoneNum << endl;
}
ContactNode::ContactNode(){
	contactName = "abc def";
	contactPhoneNum = "xxx-xxx-xxxx";
}
ContactNode::ContactNode(string name, string phoneNum){
	this->contactName = name;
	this->contactPhoneNum = phoneNum;
}

