//*****************************
//**	Moosa Hassan
//**	SENG1120 Data Structures
//**    c3331532
//*****************************

#include <cstdlib>

#include "LinkedList.h"
#include "Node.h"

using namespace std;

// Constructors
LinkedList::LinkedList(){
	head = NULL;
	tail = NULL;
	current = NULL;
	length = 0;
}
    
LinkedList::LinkedList(data_type& data){
	head = new Node(data);  // Takes input data and creates a head node
	tail = head;            // Takes new node equates it to tail, and current.
	current = tail;         
	length = 1;             //  Set length to 1
	return;
}
    
// Destructor
LinkedList::~LinkedList(){
	while(head != NULL){
		Node* interim;									// Create a temporary node called "interim" 
		interim = head;									// interim = head 
		head = head->getNext();							// Move head to the next node in list
		if (head != NULL) {head->setPrevious(NULL);}	// If head node NOT null, reset its 'previous' pointer
		else {tail = NULL;} 							// if head node = null then the list is empty therefore  
		delete interim; 								// Delete interim node 
		current = head; 								// Set current to the new head node
	}
	length = 0;											// length=0 because the list is empty
}
    
    
void LinkedList::addToTail(const data_type& data){
	// add tail Node for empty list (an empty list obviously will have no length)
	if (length == 0){
		tail = new Node(data); 								// user inputs data which will create a new node. 
		head = tail;           
		current = head;        
		length = 1;           								// Set length of linkedList to 1
	}else{
		Node* newtail = new Node(data);   					// user inputs data and creates new node
		tail->setNext(newtail);         					// the following node of the tail 
		newtail->setPrevious (tail);   						// The precusor node of the tail
		tail = newtail;                   					// new node of tail is set as the tail
		length++;                         					// Add one length to the list
		newtail = NULL;                   					// newtail node = null
	}
}

void LinkedList::addToHead(const data_type& data){
	// add tail Node for empty list (an empty list obviously will have no length)
	if (length == 0){
		tail = new Node(data); 								// user inputs data which will create a new node. 
		head = tail;           
		current = head;        
		length = 1;           								// Set length of linkedList to 1
	}else{
		Node* newtail = new Node(data);   					// user inputs data and creates new node
		tail->setNext(newtail);         					// the following node of the tail 
		newtail->setPrevious (tail);   						// The precusor node of the tail
		tail = newtail;                   					// new node of tail is set as the tail
		length++;                         					// Add one length to the list
		newtail = NULL;                   					// newtail node = null
	}
}
	
//Returns current node
Node* LinkedList::getCurrent() const{
	return current;  										// Return data of current node
}  
    

//counting the students with a particular name
// similar to average except just adding the number of times a specific string occurs in the list and adding it to a counter. 
const int LinkedList::count(string name){
	int counter = 0;										
	current = head;											 
		do{
			if( name == current->getName()){				// user inputs name and name is compared to names in the list of current students
				counter++;									// Add one for each match in list
			}
			current = current->getNext();					 
		} while(current != NULL);							 
	return counter;											// Returns counter value to user
}

// Returns head node
Node* LinkedList::getHead() const{
	return head;
}

//Set current node can contain inputted data
void LinkedList::setCurrent(Node* newC){
	current = newC;
}


//removing // some coding has been repeated and hence i have not decidied to explain the code there. 
void LinkedList::remove(const string name){
	current = head;										    	 
	
	while(current != NULL){										
		if(name == current->getName() && current == head){		// Compares inputted name with name in current node also checks if current is the head 
			Node* interim;										// Creates temporary node called 'interim' to delete items in node
			interim = head;										 
			head = head->getNext();								// Makes head moves along the node
			if (head != NULL) {head->setPrevious(NULL);}		
			else {tail = NULL;} 								
			delete interim; 									// Delete 'interim' 
			length --;											// cut a length off the list as a person has been removed.  
			current = head; 									
		}
		else if(name == current->getName() && current == tail){ // Compares inputted name with name in current node also checks if current is the tail
			Node* interimTail;     								
			interimTail = tail;									//'interimTail' is a temporary node for the tail
			tail = interimTail->getPrevious();						
			if (tail != NULL){tail -> setNext(NULL);}			// If tail!= NULL , reset its 'previous' pointer
			else{head = NULL;}									// If head = list,set 'head' to null 
			delete interimTail;            						 
			length --;											
			current = NULL;  									
		}
		else if(name == current->getName()){
			Node* interim;     									
			interim = current->getPrevious();					
			interim->setNext(current->getNext());				
			interim = current->getNext();						// interim node skips to the node after current
			interim->setPrevious(current->getPrevious());		
			delete current;            							 
			current = interim;
			length--;											
		}
		else{	
		current = current->getNext();							// current node moves along the list
		}
		
	}
}

//ordered listing (CHECK BACK ON THIS)
void LinkedList::order(){
	
}

//Overloading cout <<
ostream& operator << (ostream& stream, LinkedList& list){
	list.setCurrent(list.getHead());
	do{
		stream << list.getCurrent()->getData(); 					// Get current node and uses the student inbuilt overload to print the data 
		list.setCurrent(list.getCurrent()->getNext()); 				// Move current node along the list 
		}while(list.getCurrent() != NULL); 							// loops whilst the next element isn't null (e.g. more nodes in list)         
		list.setCurrent(list.getHead()); 							// Resets current node to head
		return stream;												// returns stream
	} 

//overloading +=
LinkedList& LinkedList::operator+= (LinkedList& list){
	do{
		this->addToTail(list.current->getData());			// Gets current node in 'list' and makes a new node on the end of the first list using this data
		list.setCurrent(list.getCurrent()->getNext());		// Moves current node along the list
	}
	while(list.getCurrent() != NULL);						

	return *this;												// Returns new linkedlist
}