#include <iostream>
#include <string>

#include "ContactNode.h"

using namespace std;
int main(){
	string name;
	string phoneNum;
	ContactNode* head = nullptr;
	ContactNode* prevContact = nullptr;
	for(int i = 1;i < 4; i++){
	cout << "Person "<< i << endl
		<< "Enter name: " << endl;
	
	getline(cin, name);
	
	cout << "Enter phone number: " << endl;
	
	getline(cin,phoneNum);
	ContactNode* newContact = new ContactNode(name, phoneNum);
	cout << "You entered: " << (*newContact).GetName() << ", " << (*newContact).GetPhoneNumber() << endl << endl;
	if(i == 1){
		head = newContact;
		prevContact = newContact;
	}
	(*prevContact).InsertAfter(newContact);
	prevContact = newContact;
	}
	cout << "CONTACT LIST" << endl;
	for(ContactNode* ptr = head; ; ptr = (*ptr).GetNext()){
		(*ptr).PrintContactNode();
		cout << endl;
		if((*ptr).GetNext() == NULL){
			break;
		}
	}
	
	return 0;
}