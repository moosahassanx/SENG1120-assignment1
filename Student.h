//*****************************
//**	Moosa Hassan
//**	SENG1120 Data Structures
//** c3331532
//*****************************
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

class Student{
public:
	
	// Constructors
	Student();
	Student(const string, const int);

	// Destructor
    ~Student();

	// Setters
    void set_name(const string);
	void set_score(const int);

	// Getters
	string get_name() const;
	int get_score() const;

	private:
		string name; 	// student's name
		int score;		// student's score
};

ostream& operator <<(ostream&, const Student&);

#endif