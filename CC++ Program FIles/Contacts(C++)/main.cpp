#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "LL.h"
#include "ContactNode.h"


using namespace std;
int main(){
	clock_t begin, end;
	double time_spent;
	LL linkedList;
	vector<ContactNode> contacts;
	vector<ContactNode*> contactsPtr;
	begin = clock();
	for(int i = 0; i < 50; i++){
		ContactNode* newCn = new ContactNode(to_string(i),"");
		linkedList.InsertFront(newCn);
	}
	end = clock();
	time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
	cout << "Time creating linked list: " << time_spent << endl;
	
	begin = clock();
	for(int i = 0; i < 50; i++){
		ContactNode newCn;
		contacts.insert(contacts.begin(), newCn);
	}
	end = clock();
	contacts.clear();
	time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
	cout << "Time creating vector: " << time_spent << endl;
	
	begin = clock();
	for(int i = 0; i < 50; i++){
		ContactNode* newCn = new ContactNode();
		contactsPtr.insert(contactsPtr.begin(),newCn);
	}
	end = clock();
	time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
	cout << "Time creating vector of pointers to contact nodes: " << time_spent << endl;
	contactsPtr.clear();
	
	LL DescendingList;
	for(int i = 0; i < 50; i++){
		ContactNode* newCn = new ContactNode(to_string(i),"");
		DescendingList.InsertFront(newCn);
	}
	DescendingList.PrintList();
	
	LL AscendingList;
	
	for(int i = 0; i < 50; i++){
		ContactNode* newCn = new ContactNode(to_string(i),"");
		AscendingList.InsertBack(newCn);
	}
	AscendingList.PrintList();
}