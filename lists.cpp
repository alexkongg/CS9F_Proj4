#include <iostream>
#include <cassert>
using namespace std;

#include "lists.h"

ListNode::ListNode (int k) {
	myValue = k;
	myNext = 0;
}

ListNode::ListNode (int k, ListNode* ptr) {
	myValue = k;
	myNext = ptr;
}

// Delete the node and all nodes accessible through it.
// Precondition: this != 0.
ListNode::~ListNode () {
  
	// Old version was buggy because it called delete p, which is a recursive call to the destructor.
	/*
	for (ListNode* p=this; p!=0; p=p->myNext) {
  		delete p;
  }
	*/
	cout << "Deleting node with value " << myValue << endl;
  myValue = 0;
	if (this!=0) {
    delete myNext;
	}
}
// Print the list.
void ListNode::Print () {
	ListNode* list = this;
	for (; list; list = list->Rest()) {
		cout << list->First() << " ";
	}
	cout << endl;
}

// Return the value stored in the node.
int ListNode::First () {
	return myValue;
}

// Return the list of the remaining elements.
ListNode* ListNode::Rest () {
	return myNext;
}
