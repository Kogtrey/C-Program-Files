#ifndef LL_H
#define LL_H

#include "ContactNode.h"


using namespace std;

class LL{
	public:
		void InsertFront(ContactNode* cd);
		void InsertBack(ContactNode* cn);
		void PrintList();
		LL();
	private:
		ContactNode* head;
		ContactNode* tail;
};

#endif