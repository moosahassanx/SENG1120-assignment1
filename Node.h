#ifndef NODE_H		//macroguarding
#define NODE_H		//macroagurding

#include <cstdlib>		//C standard utilities library - allows for size_t and NULL functions
#include <iostream>		//standard input / output streams library - allows for cout functions
#include "Student.h"	//include directive for Student.h file

using namespace std;	//standard namespace (no need for std:: when using cout <<)

class Node{
	public:
		typedef Student dataType;

		//constructor
		Node(const dataType& initialData = dataType(), Node* initialNext = NULL, Node* initialPrevious = NULL){
			data = initialData;
			next = initialNext;
			previous = initialPrevious;
		}
		
		//destructor
		//ADD CODE LATER
		
		void setData(const dataType& newData){
			data = newData;
		}
		
		void setNext(Node* nextLink){
			next = nextLink;
		}
		
		void setPrevious(Node* previousLink){
			previous = previousLink;
		}
		
		//constant member functions
		string getName() const{
			string name = "";
			name = data.get_name();
			return name;
		}
		
		double getScore() const{
			double score;
			score = data.get_score();
			return score;
		}
		
		dataType getData() const{
			return data;
		}
		
		Node* getPrevious() const{
			return previous;
		}
		
		Node* getNext() const{
			return next;
		}
		
	private:
		dataType data;   	//variable to store data
		Node* next;        	//variable to store address of next Node
		Node* previous;    	//variable to store address of previous Node
};


#endif