#include <iostream>
#include "amoebas.h"

using namespace std;

int main () {
	Amoeba* me = new Amoeba (string ("me"));
	Amoeba* parent = new Amoeba (string ("mom/dad"));
	Amoeba* grandparent = new Amoeba (string ("Amos McCoy"));
	Amoeba* brother = new Amoeba (string ("Fred"));
	Amoeba* sister = new Amoeba (string ("Wilma"));
	Amoeba* child1 = new Amoeba (string ("Mike"));
	Amoeba* child2 = new Amoeba (string ("Homer"));
	Amoeba* child3 = new Amoeba (string ("Marge"));
	Amoeba* grandchild11 = new Amoeba (string ("Bart"));
	Amoeba* grandchild12 = new Amoeba (string ("Lisa"));
	Amoeba* grandchild31 = new Amoeba (string ("Bill"));
	Amoeba* grandchild32 = new Amoeba (string ("Hilary"));

	// This will seem a bit backward, since we have an "add child"
	// instead of an "add parent".

	// First do Mike's kids.
	child1->AddChild (grandchild11);
	child1->AddChild (grandchild12);

	// Next do Marge's kids.
	child3->AddChild (grandchild31);
	child3->AddChild (grandchild32);

	// Now add Mike, Homer, and Marge to me.
	me->AddChild (child1);
	me->AddChild (child2);
	me->AddChild (child3);

	// Now add me to my parent.
	parent->AddChild (me);

	// Now add my brother and sister.
	parent->AddChild (brother);
	parent->AddChild (sister);
	
	// Add my parent to my grandparent.
	grandparent->AddChild(parent);
  

	// We won't need these any more now, will we?
	parent = 0;
	grandparent = 0;
	brother = 0;
	sister = 0;
	child1 = 0;
	child2 = 0;
	child3 = 0;
	grandchild11 = 0;
	grandchild12 = 0;
	grandchild31 = 0;
	grandchild32 = 0;

	// Print my name and my parent's name.
	cout << "Hi, my name is " << me->Name () << endl;
	cout << "Meet my parent " << me->Parent ()->Name () << endl;
	
	// 2. Print my grandparent's name
  cout << "My grandparent is " << me->Parent()->Parent()->Name() << endl;
  
  // 3. Print my children's names
  cout << "My children are " << endl;
  me->PrintChildren ();
  cout << "My parent's children are " << endl;
  me->Parent()->PrintChildren();
  
  // 4. Print my grandchildren's names
  cout << "My grandchildren are " << endl;
  me->PrintGrandchildren ();
  cout << "My parent's grandchildren are " << endl;
  me->Parent()->PrintGrandchildren();
  
  // 5. Print descendants
  cout << "My descendants are " << endl;
  me->PrintDescendants ();
  cout << "My parent's descendants are " << endl;
  me->Parent()->PrintDescendants ();
  cout << "My grandparent's descendants are " << endl;
  me->Parent()->Parent()->PrintDescendants();
}