//*****************************
//**	Moosa Hassan
//**	SENG1120 Data Structures
//**    c3331532
//*****************************
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include "Node.h"
using namespace std;

class LinkedList{
	public:
	
		typedef Student data_type;
		
		// Constructors
		LinkedList();					//accepts no arguments
		LinkedList(data_type& data);	//accepts 1 argument
		
		// Descructors 
		~LinkedList();
		
		// Function: Create new node with input data at tail of list 
		// Precondition:    List is initiated and a valid input given by user
		// Postcondition:   new node is at the end which is the tail
		void addToTail(const data_type& data);	
		
		//Function:
		//Precondition:		
		//Postcondition:	
		void LinkedList::addToHead(const data_type& data);
		
		//Function: Return current node 
		//Precondition:   'current' set to a node
		//Postcondition:  return 'current'
		Node* getCurrent() const;

		//Function: calculate mean mark of list 
		//Precondition: Nodes have a valid data value set
		//Postcondition: mean returned as double
		const double calcAverage();

		// Member function: Counts number of students with same name as inputted
		// Precondition:    nodes have valid data
		// Postcondition:   return number of students with same name
		const int count(string name);
		
		// Function: Return head node 
		// Precondition:  'head' is set to a node
		// Postcondition:  return head
		Node* getHead() const;
		
		// Function: Set current node 
		// Precondition:    input valid node
		// Postcondition:   inputted node is set as the current node
		void setCurrent(Node* newCurrent);

		// Function: Deletes every node with the input name 
		// Precondition:    input string is valid
		// Postcondition:   Deletes node using list position/length
		void remove(const string name);


		// Operator Overload: adds nodes from input list onto the current list 
		// Precondition:    input list is valid
		// Postcondition:   the nodes from one end of the Linkedlist are added to the other end. 
		LinkedList& operator+= (LinkedList& list);
		
		//CHECK BACK ON THIS ON OWN TIME
		void order();
		
	private:
		Node* head;     // Pointer variable for head
		Node* tail;     // Pointer variable for tail
		Node* current;  // Pointer variable for current 
		int length;	// Variable to store length of linkedlist
};

// Operator Overload: Prints name and score from each node in input linked list
// Precondition:    Input list is valid
// Postcondition:   Mame and score of the students in the list are printed in order
ostream& operator<< (ostream& stream, LinkedList& list);
	

#endif