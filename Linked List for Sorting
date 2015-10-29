// Author:  Emily Wolf
// Date:    2/19/14
// Purpose: To implement a simple, sorted linked-list of positive
//          integers

#include "LLSortedPosInt.h"
#include <cmath>

// The linked-list is constructed of Node elements
struct Node {
   int   key;
   Node *next;
};

// createNode() allocates a Node and initializes it with the
// given parameter values to simplify the initilization of a Node
static NodePtr createNode(int key, NodePtr p) {
   // allocate a new Node for storing the given key value
   NodePtr n = new Node;

   // store the key value and NULL the next pointer
   n->key  = key;
   n->next = p;

   // return the new Node to the caller
   return n;
}

// Implementation of the LLSortedPosInt begins here
// Constructors
LLSortedPosInt::LLSortedPosInt() {
   // create the sentinal Node at the head of the list
   head = createNode (HEAD_OF_LIST , NULL);
   
}

LLSortedPosInt::LLSortedPosInt(int key) {
   // create the sentinal Node at the head of the list
   head = createNode (HEAD_OF_LIST , NULL);
   // add the single element key, as long as it is positive
   if (key > 0) {
	   insert(key);
   }

}

LLSortedPosInt::LLSortedPosInt(int *keys,    int n) {
   // create the sentinal node at the head of the list
   head = createNode (HEAD_OF_LIST , NULL);
   // add new Nodes for each positive value in keys
  for (int i = 0; i < n; i++) {
    if ( keys[i] > 0) {
      insert (keys[i]);
    } 
  }
}
//this uses my opertaot= function, defined below
LLSortedPosInt::LLSortedPosInt(const LLSortedPosInt &l) {
   // create a deep copy of the input list l
   head = createNode (HEAD_OF_LIST , NULL);
   *this = l;
}
   
// Destructor
LLSortedPosInt::~LLSortedPosInt() {
   // free the Nodes in *this, including the sentinal
   while (head -> next != NULL) {
	   remove (head -> next -> key);
   }
   //completely deletes the senitnel node
   remove(head -> key);
   delete head;
}

// Boolean Functions
bool LLSortedPosInt::containsElement (int key) const {
   // return true if key is in the list; return false otherwise
   NodePtr npc = head->next;   
   while (npc != NULL) {

      // if the key value is found, then splice this Node from the list and
      // reclaim its storage
      if (npc->key == key) {
       return true;
      }
      //walk the pointer
      npc = npc->next;
   }
   
   if (npc == NULL) {
	   return false;
   }
}

bool LLSortedPosInt::isEmpty (       ) const {
   // return true if only the sentinal is in the list; return false otherwise  
   return (this -> head ->next == NULL);
}

// Operators
LLSortedPosInt&  LLSortedPosInt::operator= (const LLSortedPosInt &l) {
   // handle self assignment  
  if (this == &l) {
      return *this;
   }
  // free old elements of the list before the new elements from l are assigned
  while (head -> next != NULL) {
    remove (head -> next -> key);
   }

  remove (head -> key);
  delete head;
  // if necessary, rebuild the sentinal
  head = createNode (HEAD_OF_LIST , NULL);
  // build the list as a deep copy of l
  NodePtr npt = l.head -> next;
  //rebuilds bit-by-bit	
  while (npt != NULL) {
    insert(npt ->key);
    npt = npt->next;
	}
   // return *this
   return *this;
}

bool LLSortedPosInt::operator==(const LLSortedPosInt &l) const {
  // compare the Nodes in *this with the Nodes in l
  // if all Node key values in *this match the cooresponding
  //  Node key values in l and the lists are the same length,
  //  then the lists are equivalent

  // set pointers to the first Nodes with actual key values in the lists
  NodePtr npt = this->head->next;
  NodePtr npl = l.head->next;

  // "walk" the lists with the pointers, using the while condition to
  // protect from de-referencing a NULL pointer
  while (npt != NULL && npl != NULL) {
    // if the present key values in the lists are not the same, then
	// the lists cannot be identical, so return false
    if (npt->key != npl->key) {
      return false;
    }

    // "advance" the pointers
    npt = npt->next;
    npl = npl->next;
	}

	// since we reached here, the while loop must have exited with all 
	// compared keys being identical; however, the lists are only truly identical
	// when they also have identical length, meaning npt and npl must both be
	// NULL.  If npt and npl are different, then the lists do NOT have the
	// same length
	return (npt == npl);
}

bool LLSortedPosInt::operator!=(const LLSortedPosInt &l) const {
  //returns opposite of operator== 
  return !(*this == l);
}

LLSortedPosInt  operator+ (const LLSortedPosInt &l1, 
                              const LLSortedPosInt &l2)  {
   // create a copy of l1 and add each element of l2 to it in 
   // the correct (sorted ascending) order, allow duplicates
   
  LLSortedPosInt sum;
  sum = l1;
  NodePtr l2P = l2.head->next;

  // search the list until the end (if necessary)
  while (l2P != NULL) {
    //using containsElement (defined elsewhere)
    if (!(sum.containsElement(l2P -> key))) {
		sum.insert(l2P -> key);
	}
    //walking through	
    l2P = l2P -> next;	
  }
   
   return sum;
}

LLSortedPosInt  operator- (const LLSortedPosInt &l1,
                              const LLSortedPosInt &l2)  {
  // copy l1 and remove all of l2 from l1, taking care to 
  // reclaim any storage -- do not forget to remove the sentinal Node
  LLSortedPosInt diff;
  diff = l1;
  NodePtr l2P = l2.head->next;

  // search the list until the end (if necessary)
  while (l2P != NULL) {
    //also uses contains, helps shorten code
    if ((diff.containsElement(l2P -> key))) {
      diff.remove(l2P -> key);
	}
	
	l2P = l2P -> next;	
  }
   
  return diff;
}

ostream&  operator<<  (ostream &out, const LLSortedPosInt &l) {
   // an empty list will be printed as <>
   if (l.isEmpty()) {
	   out << "<>";
   }
  // a singleton list (a list having one key value k) will be
  //     printed as <k>
  else if (l.head -> next -> next == NULL) {
    out << "<" << l.head -> next -> key;
    out << ">";
  }
  // a list having multiple keys such as 2, 5, 7 will be printed
  //     as <2, 5, 7>

  // print the left angle bracket

  else {
    out <<"<";
    // print the keys in the list l
    NodePtr npt = l.head -> next;    
    while (npt != NULL) {
      //special case to check if last value
      if (npt -> next == NULL) {
        out << npt -> key;
      }
			
      else {
        out << npt -> key << ", "; 
      }	
	  
      npt = npt->next;	
    }
   
  // print the right angle bracket
    out << ">";
  }

  return out;
}
// The following helper functions are provide to assist you in
// building the class--these helper functions are useful in
// several places among the functions you will write--take time
// to learn what they do

// insert() inserts an element in the linked list in sorted order
void LLSortedPosInt::insert(int key) {

   // setup pointers to walk the list
   NodePtr npp = head;
   NodePtr npc = head->next;

   // walk the list, searching until the given key value is exceeded
   while (npc != NULL && npc->key <= key) {
      npp = npc;
      npc = npc->next;
   }

   // insert the new value into the list
   npp->next = createNode(key, npc);
}

// remove() removes an element from the list (if it is present)
void LLSortedPosInt::remove(int key) {

   // negative values should not be stored in the list
   if (key <= 0) {
      return;
   }

   // setup pointers to walk the list
   NodePtr npp = head;
   NodePtr npc = head->next;

   // search the list until the end (if necessary)
   while (npc != NULL) {

      // if the key value is found, then splice this Node from the list and
      // reclaim its storage
      if (npc->key == key) {
         npp->next = npc->next;
         delete npc;
         break;
      }

      // walk the pointers to the next Node
      npp = npc;
      npc = npc->next;
   }
}
