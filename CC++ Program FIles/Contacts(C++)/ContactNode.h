#ifndef CONTACTNODE_H
#define CONTACTNODE_H
#include <string>

using namespace std;
class ContactNode{
	public:
		void InsertAfter(ContactNode* NextNodePtr);
		string GetName();
		string GetPhoneNumber();
		void setNextNode(ContactNode* nextNode);
		ContactNode* GetNext();
		void PrintContactNode();
		ContactNode();
		ContactNode(string name, string phoneNum);
	private:
		string contactName;
		string contactPhoneNum;
		ContactNode* nextNodePtr;
		ContactNode* prevNodePtr;
};

#endif
